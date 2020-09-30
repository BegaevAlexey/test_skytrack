#include <opencv2/opencv.hpp>

namespace call
{
    /*!
     * @brief Structure for containing params for callback function
     * @date 30.09.2020
     * @author BegaevAlexey
     */
    struct ParamCallBack
    {
        int     Xcurr;     ///< current x coordinate
        int     Ycurr;     ///< current y coordinate
        cv::Mat currFrame; ///< current frame
        int     blurSize;  ///< area size for blur effect
        int     kSize;     ///< size of blur kernel
    
        ParamCallBack()
        : Xcurr(-1)
        , Ycurr(-1)
        , blurSize(1)
        , kSize(1)
        {

        }
    };
} // namespace call