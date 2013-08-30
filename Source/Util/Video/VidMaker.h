#ifndef VIDMAKER_H
#define	VIDMAKER_H


/* 
 * @(#) VidMaker.h
 */
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>

/* 
 * File:   VidMaker.h
 * 
 *              @class VidMaker
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on November 20, 2012, 4:43 PM
 * 
 * * $Header $
 */
using namespace cv;

class VidMaker{
    public:
        void initVideo(string,Mat);
        void addFrame(Mat);
        void addFrame(string,Mat);
        void displayCurrentVid(string);
    private:
        VideoWriter record;
        bool displayVid;
        string vidName;
};

#endif	/* VIDMAKER_H */

