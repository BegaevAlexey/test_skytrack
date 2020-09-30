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

     if ((paramCallPack->getPoint().x != x) && (paramCallPack->getPoint().y != y))
     {       
        paramCallPack->setPoint(cv::Point(x ,y));
     }     
}