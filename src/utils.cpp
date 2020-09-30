#include "utils.h"

libconfig::Config cfg;

bool utls::initConfig(const std::string &nameFile)
{
    try
    {
        cfg.readFile(nameFile.c_str());
    }
    catch(const libconfig::FileIOException &fioex)
    {
        std::cerr << "[ERROR] I/O error while reading file." << std::endl;
        return false;
    }
    catch(const libconfig::ParseException &pex)
    {
        std::cerr << "[ERROR] Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return false;
    }
    return true;
}

void utls::callBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if ( event != cv::EVENT_MOUSEMOVE )
     {
         return;
     }

     call::ParamCallBack *paramCallPack = (call::ParamCallBack*)userdata;

     if ((paramCallPack->Xcurr != x) && (paramCallPack->Ycurr != y))
     {
        //cout << "[DEBUG] Mouse move over the window - position (" << x << ", " << y << ")" << endl;        
        paramCallPack->Xcurr     = x;
        paramCallPack->Ycurr     = y;
        paramCallPack->isUpdated = true;        
     }     
}

void utls::makeBlur(cv::Mat &frame, call::ParamCallBack* paramCallBack)
{
    if(paramCallBack->isUpdated)
    {
        int x = paramCallBack->Xcurr;
        int y = paramCallBack->Ycurr;

        // calculation blur area
        int w = paramCallBack->blurSize;
        int h = paramCallBack->blurSize;
        int xLeft = x - w / 2;
        xLeft = (xLeft < 0) ? xLeft : 0;
        int yTop  = y - h / 2;
        yTop = (yTop < 0) ? yTop : 0;
        w = (xLeft + w) < frame.cols ? w : frame.cols - xLeft - 1;
        h = (yTop + h) < frame.rows ? h : frame.rows - yTop - 1 ;
        yTopHeight = yTopHeight >  frame.rows ? frame.rows - yTop - 1 : yTopHeight;
        cv::Rect blurRect(xLeft, yTop, w, h);

        // make blur filter
        cv::Size kSize(paramCallBack->kSize, paramCallBack->kSize);
        cv::GaussianBlur(frame(blurRect), frame(blurRect), kSize, 0, 0 );

        paramCallBack->isUpdated = false;
    }
}