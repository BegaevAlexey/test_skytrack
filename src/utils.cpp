#include "utils.h"

#include "paramcallback.h"

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
     if ( event != EVENT_MOUSEMOVE )
     {
         return;
     }

     call::ParamCallBack *paramCallPack = (call::ParamCallBack*)userdata;

     if ((paramCallPack->Xcurr != x) && (paramCallPack->Ycurr != y))
     {
        //cout << "[DEBUG] Mouse move over the window - position (" << x << ", " << y << ")" << endl;

        // update coordinates
        paramCallPack->Xcurr = x;
        paramCallPack->Ycurr = y;

        // calculation blur area
        int w = paramCallPack->blurSize / 2;
        int h = paramCallPack->blurSize / 2;
        int xLeft = x - w / 2;
        int yTop  = y - h / 2;
        cv::Rect blurRect(xLeft, yTop, w, h);
        cv::Mat blurArea = paramCallPack->currFrame(blurRect);

        // make blur filter
        cv::Size kSize(paramCallPack->kSize, paramCallPack->kSize);
        cv::blur(blurArea, blurArea, kSize);
     }
     

     
}