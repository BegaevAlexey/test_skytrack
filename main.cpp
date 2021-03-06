#include <iostream>
#include <memory>

#include <opencv2/opencv.hpp>
#include <libconfig.h++>

#include "utils.h"
#include "paramcallback.h"

int main(int argc, char **argv)
{
    // init config file
    if (argc < 2)
    {
        std::cerr << "[ERROR] Number of argumets is not enough!" << std::endl;
        return -1;
    }
    bool isRead = utls::initConfig(argv[1]);
    if(!isRead)
    {
        return -1;
    }

    // open video
    std::string videoFile = utls::readCfgParam<std::string>("video_file");
    cv::VideoCapture cap(videoFile);
    if (!cap.isOpened())
    {
        std::cerr << "[ERROR] Video '" << videoFile << "'was not opened!" << std::endl;
        return -1;
    }

    // calculate pause for waiting video
    int fps = cap.get(cv::CAP_PROP_FPS);
    int pause = 1000 / fps;

    // create callback params    
    int blurSize = utls::readCfgParam<int>("blur_size");
    int kSize = utls::readCfgParam<int>("kernel_size");
    std::unique_ptr<call::ParamCallBack> paramCallBack = std::make_unique<call::ParamCallBack>(blurSize, kSize);

    // set callback
    const std::string NAME_WIN = "SKYTRACK";
    cv::namedWindow(NAME_WIN, cv::WINDOW_NORMAL);
    cv::setMouseCallback(NAME_WIN, utls::callBackFunc, paramCallBack.get());

    cv::Mat frame;
    while (true)
    {
        cap >> frame;
        if(frame.empty())
        {
            std::cout << "[INFO] Frame is empty!" << std::endl;
            break;
        }

        paramCallBack->makeBlur(frame);

        cv::imshow(NAME_WIN, frame);
        if (0 < cv::waitKey(pause))
        {
            break;
        }
    }

    cv::destroyAllWindows();

    std::cout << "\n\t***END PROGRAM!***" << std::endl;
    return 0;
}