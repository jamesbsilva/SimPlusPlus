// File and Version Information:   Lattice2DRep.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include "Lattice2DRep.h"
#include "Source/SimSystem/SimSystem.h"

Lattice2DRep::Lattice2DRep(int l=20, int w=20,int sq = 5, bool def=false, int instId=1){
    helperCV = HelperOpenCV();
    length = l;
    width = w;
    defineColors = def;
    squareSize = sq;
    colorDefValues = vector<defColor>();
    imgLattice = helperCV.getBlankFloatImage(length,width);
}

void Lattice2DRep::update(int x, int y, int v){
    update(x,y,(float)v);
}

void Lattice2DRep::update(int x, int y, float v){
    if(defineColors){
        for(int u = 0; u < colorDefValues.size();u++){
            if(v == colorDefValues.at(u).value){
                cv::Scalar col = cv::Scalar(colorDefValues.at(u).b,colorDefValues.at(u).g,colorDefValues.at(u).r);
                update(x,y,col);
            }
        }
    }else{
        float col = (float) v;
        update(x,y,col,col,col);
    }
}
    
void Lattice2DRep::update(int x, int y, cv::Scalar color){
    x = getImgLoc(x); y = getImgLoc(y);
    cv::Point cen = cv::Point(x,y);
    helperCV.DrawRectangle(imgLattice,cen,squareSize,squareSize,color);
}

void Lattice2DRep::update(int x, int y, float b, float g, float r){
    cv::Scalar color(b,g,r);
    update(x,y,color);
}

int Lattice2DRep::getImgLoc(int u){
    float s2 = squareSize/2.0;
    s2 = s2+u*squareSize;
    while(s2 < MINL || s2 < MINW){
        squareSize = squareSize*2.0;
        s2 = s2+u*squareSize;        
    }
    while(s2 > MAXL || s2 > MAXW){
        squareSize = squareSize/2.0;
        s2 = s2+u*squareSize;    
    }
    return ((int)s2);
}

void Lattice2DRep::saveImageLattice(string post=""){  
    if(post.c_str()[post.size()-1]=='/'){
        post.append("/");
    }
    stringstream ss (stringstream::in | stringstream::out);
    ss << time;
    string t = ss.str();
    string imageName = dirs.getImagesDir(post)+post+"Lattice2D-"
            +t+"-"+dirs.getParamsForFilename()+".jpg";
    helperCV.SaveImage(imageName,imgLattice);
}
    
void Lattice2DRep::initialDraw(SimSystem sys){  
    int x; int y;
    for(int u = 0; u < (sys.getSize());u++){
        float val = sys.getValue(u);
        x = u%length;
        y = ((int)(((float)u)/length))%width;
        update(x,y,val);
    }
}    
    
void Lattice2DRep::changeSquareSize(int s){
    squareSize = s;
}

void Lattice2DRep::changeInstId(int id){
    instId = id;
}

void Lattice2DRep::displayLattice(){
    string latWin = "Lattice";
    stringstream ss (stringstream::in | stringstream::out);
    ss << instId;
    latWin = latWin+ss.str();
    helperCV.DisplayImage(latWin,imgLattice);
}    
    
void Lattice2DRep::moveDisplayLat(int x, int y){
    string latWin = "Lattice";
    stringstream ss (stringstream::in | stringstream::out);
    ss << instId;
    latWin = latWin+ss.str();
    helperCV.MoveDisplayedImage(latWin,x,y);
}

vector<defColor> Lattice2DRep::getColorDefs(){
    return colorDefValues;
}

