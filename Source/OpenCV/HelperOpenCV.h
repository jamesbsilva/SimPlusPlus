#ifndef HELPEROPENCV_H
#define	HELPEROPENCV_H
/* 
 * @(#) HelperOpenCV.h
 */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define DEFAULT_WIDTH 400
#define DEFAULT_LENGTH 400

#define MAXL 2000
#define MAXW 2000

/* 
 * File:   HelperOpenCV.h
 * 
 *              @class HelperOpenCV
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on December 28, 2012, 5:48 PM
 * 
 * * $Header $
 */

using namespace cv;

class HelperOpenCV{
    public:
        void DrawRectangle(Mat,float,float,float,float);
        void DrawRectangle(Mat,float,float,float,float,Scalar);
        void DrawRectangle(Mat,Point,Point);
        void DrawRectangle(Mat,Point,Point,Scalar);
        void DrawRectangle(Mat,Point,float,float);
        void DrawRectangle(Mat,Point,float,float,Scalar);
        void DrawEllipse(Mat,float,float,float,float,float);
        void DrawEllipse(Mat,Point,float,float,float);
        void DrawEllipse(Mat,Point,float,float,float,Scalar);
        void DrawCircle(Mat,float,float,float);
        void DrawCircle(Mat,Point,float);
        void DrawCircle(Mat,Point,float,Scalar);
        void DrawLine(Mat,float,float,float,float);
        void DrawLine(Mat,Point,Point);
        void DrawLine(Mat,Point,Point,Scalar);
        Scalar getColor(float,float,float);
        Point getPoint(float,float);
        void SaveImage(std::string,Mat);
        void DisplayImage(std::string,Mat);
        void MoveDisplayedImage(std::string,int,int);
        Mat getBlankFloatImage(int, int);
        Mat getImageMat(string);
        Scalar getPointColor(Mat,int,int);
        float getPointColorR(Mat,int,int);
        float getPointColorG(Mat,int,int);
        float getPointColorB(Mat,int,int);
    private:

};

#endif	/* HELPEROPENCV_H */

