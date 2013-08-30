// File and Version Information:   ImgOpen.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include "ImgOpen.h"
#include "Source/Representations/Representation.h"

void ImgOpen::setColorDefs(vector<defColor> defs){
    defColorValues = defs;
    defineColors = true;
}

float ImgOpen::getValueFromImg(string filename ,int x, int y){
    return (getValueFromImg(helperCV.getImageMat(filename),x,y));
}

vector<float> ImgOpen::getValueFromImg(string filename ,int x, int y){
    return (getValueFromImg(helperCV.getImageMat(filename),x,y));
}

vector<float> ImgOpen::getValueFromImgDir(string filename ,int x, int y){
    return (getValueFromImg(helperCV.getImageMat(dirs.getImagesDir()+filename),x,y));
}

float ImgOpen::getValueFromImgDir(string filename ,int x, int y){
    return (getValueFromImg(helperCV.getImageMat(dirs.getImagesDir()+filename),x,y));
}

float ImgOpen::getValueFromImg(cv::Mat img ,int x, int y){
    cv::Scalar col = helperCV.getPointColor(img,x,y);
    if(defineColors){
        for(int u = 0; u < defColorValues.size();u++){
            if(col[0] == defColorValues.at(u).b &&
                col[1] == defColorValues.at(u).g &&
                col[2] == defColorValues.at(u).r){
                return defColorValues.at(u).value;
            }
        }
    }else{
        return (float) col[0];
    }
}

vector<float> ImgOpen::getValueFromImg(cv::Mat img){
    vector<float> imgVals = vector<float>();
    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j < img.cols; j++){
            imgVals.push_back(getValueFromImg(img,i,j));
        }
    }
    return imgVals;
}

