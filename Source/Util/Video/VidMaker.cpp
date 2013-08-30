// File and Version Information:   VidMaker.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include "VidMaker.h"

void VidMaker::initVideo(string vid, Mat frame){        
    vidName = vid;
    // record video
    record = VideoWriter(vid, CV_FOURCC('D','I','V','X'), 30, frame.size(), true);
    if( !record.isOpened() ) {
        printf("VideoWriter failed to open!\n");
    }
    displayVid = false;
}

void VidMaker::addFrame(Mat frame){
    // add frame to recorded video
    record << frame; 
}
void VidMaker::addFrame(string window, Mat frame){
    // show frame on screen
    imshow(window, frame); 
    // add frame to recorded video
    record << frame; 
}

void VidMaker::displayCurrentVid(string window){
    namedWindow(window,1);
    displayVid = true;
}
