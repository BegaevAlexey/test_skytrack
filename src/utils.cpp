#include "utils.h"

libconfig::Config cfg;

bool utls::initConfig(const std::string &nameFile)
{
    try
    {
        cfg.readFile(nameFile);
    }
    catch(const FileIOException &fioex)
    {
        std::cerr << "[ERROR] I/O error while reading file." << std::endl;
        return false;
    }
    catch(const ParseException &pex)
    {
        std::cerr << "[ERROR] Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return false;
    }
    return true;
}