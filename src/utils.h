#ifndef TEST_SKYTRACK_UTILS_H
#define TEST_SKYTRACK_UTILS_H

#include <iostream>
#include <libconfig.h++>
#include <string>

#include "paramcallback.h"

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
    template<typename T>
    T readCfgParam(const std::string &nameParam)
    {
        T param;
        if (cfg.lookupValue(nameParam, param))
        {
            std::cout << "[INFO]" << nameParam  << ": " << param << std::endl;
        } 
        else
        {
            std::cerr << "No '" << nameParam << "' setting in configuration file.\n";
            exit(EXIT_FAILURE);
        }
        return param;
    }

    /*!
     * @brief Read param from config file
     * @date 30.09.2020
     * @author BegaevAlexey
     */
    void callBackFunc(int event, int x, int y, int flags, void* userdata);

    /*!
     * @brief Read param from config file
     * @date 30.09.2020
     * @author BegaevAlexey
     * @param frame[in, out] Current frame
     * @param paramCallBack[in, out] Params for making blur
     */
    void makeBlur(cv::Mat &frame, call::ParamCallBack* paramCallBack);

} // namespace utls

#endif // TEST_SKYTRACK_UTILS_H