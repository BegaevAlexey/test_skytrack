#include "paramcallback.h"

using namespace call;

ParamCallBack::ParamCallBack(int blurSize, int kernelSize)
            : m_currPoint(-1, -1)
            , m_isUpdated(false)
{
    m_blurSize = blurSize > 0 ? blurSize : 1;

    m_kSize = kernelSize > 0 ? kernelSize : 1;

}

void ParamCallBack::setPoint(const cv::Point &p)
{
    m_currPoint = p;
    m_isUpdated = true; 
}

cv::Point ParamCallBack::getPoint() const
{
    return m_currPoint;
}

void ParamCallBack::makeBlur(cv::Mat &frame)
{
    if(m_isUpdated)
    {
        int x = m_currPoint.x;
        int y = m_currPoint.y;

        // calculation blur area
        int w = m_blurSize;
        int h = m_blurSize;
        int xLeft = x - w / 2;
        xLeft = (xLeft > 0) ? xLeft : 0;
        int yTop  = y - h / 2;
        yTop = (yTop > 0) ? yTop : 0;
        w = (xLeft + w) < frame.cols ? w : frame.cols - xLeft - 1;
        h = (yTop + h) < frame.rows ? h : frame.rows - yTop - 1 ;
        cv::Rect blurRect(xLeft, yTop, w, h);

        // make blur filter
        cv::GaussianBlur(frame(blurRect), frame(blurRect), cv::Size(m_kSize, m_kSize), 0, 0 );

        m_isUpdated = false;
    }

}