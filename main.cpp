#include <iostream>
#include <opencv2/opencv.hpp>
#include <libconfig.h++>

#include "utils.h"

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
        retrun -1;
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
    int fps = cap.get(cv::CV_CAP_PROP_FPS);
    int pause = 1000 / fps; 

    const std::string NAME_WIN = "SKYTRACK";
    cv::namedWindow(NAME_WIN, cv::WINDOW_NORMAL);

    cv::Mat frame;
    while (true)
    {
        cap >> frame;
        if(frame.isEmpty())
        {
            std::cout << "[INFO] Frame is empty!" << std::endl;
            break;
        }


        cv::imshow(NAME_WIN, frame);
        if (0 < cv::waitKey(pause))
        {
            break;
        }
    }

    cv::destroyAllWindows();

    std::cout << "\n\t***END PROGRAM!***" << std::endl;
}