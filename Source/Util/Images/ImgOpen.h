#ifndef IMGOPEN_H
#define	IMGOPEN_H


/* 
 * @(#) ImgOpen.h
 */

#include "../../OpenCV/HelperOpenCV.h"
#include "../Files/DirHandler.h"

/* 
 * File:   ImgOpen.h
 * 
 *              @class ImgOpen
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on January 1, 2013, 10:48 PM
 * 
 * * $Header $
 */

class ImgOpen{
    public:
        float getValueFromImg(string,int,int);
        float getValueFromDirImg(string,int,int);
        float getValueFromImg(Mat,int,int);
        vector<float> getValueFromImg(string);
        vector<float> getValueFromImgDir(string);
        vector<float> getValueFromImg(Mat);
        void setColorDefs(vector<defColor>);
        
    private:
        bool defineColors;
        vector<defColor> defColorValues;
        DirHandler dirs;
        HelperOpenCV helperCV;
        int instId;        
};

#endif	/* IMGOPEN_H */

