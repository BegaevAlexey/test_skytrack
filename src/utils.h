#include <libconfig.h++>
#include <string>

extern libconfig::Config cfg;

namespace utls
{
    /*!
     * @brief Init config file
     * @date 30.09.2020
     * @author BegaevAlexey
     * @param nameFile[in] Path to config file
     */ 
    bool initConfig(const std::string &nameFile);

    /*!
     * @brief Read param from config file
     * @date 30.09.2020
     * @author BegaevAlexey
     * @param nameParam[in] Name param
     */ 
    T readCfgParam(const std::string &nameParam)
    {
        T param;
        if (cfg.lookupValue(nameParam, param))
        {
            std::cout << "[INFO] nameParam: " << param << std::endl;
        } 
        else
        {
            std::cerr << "No '" << nameParam << "' setting in configuration file.\n";
            exit(EXIT_FAILURE);
        }
        return param;
    }

} // namespace utls