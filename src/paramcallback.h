#include <opencv2/opencv.hpp>

namespace call
{
    /*!
     * @brief Structure for containing params for callback function
     * @date 30.09.2020
     * @author BegaevAlexey
     */
    class ParamCallBack
    {
        int     Xcurr;     ///< current x coordinate
        int     Ycurr;     ///< current y coordinate
        cv::Mat currFrame; ///< current frame
        int     blurSize;  ///< Area size for blur effect
    
        ParamCallBack::ParamCallBack()
        : Xcurr(-1)
        , Ycurr(-1)
        , blurSize(1)
        , kSize(1)
        {

        }
    };
} // namespace call