#ifndef TEST_SKYTRACK_PARAMCALLBACK_H
#define TEST_SKYTRACK_PARAMCALLBACK_H

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
    public:
        /*!
         * @brief Structure for containing params for callback function
         * @param blurSize[in] Size of blur area
         * @param kernelSize[in] Kernel size for blur effect
         */
        ParamCallBack(int blurSize, int kernelSize);

        /*!
         * @brief Make blur effict for current frame
         * @param frame[in, out] Current frame
         */
        void makeBlur(cv::Mat &frame);

        void setPoint(const cv::Point &p);

        cv::Point getPoint() const;        

    private:
        cv::Point m_currPoint; ///< current cursor coordinates        
        int       m_blurSize;  ///< area size for blur effect
        int       m_kSize;     ///< size of blur kernel
        bool      m_isUpdated; ///< true - data was updated 
    
        
    };
} // namespace call

#endif // TEST_SKYTRACK_PARAMCALLBACK_H