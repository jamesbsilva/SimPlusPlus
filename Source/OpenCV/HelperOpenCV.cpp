// File and Version Information:   HelperOpenCV.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include "HelperOpenCV.h"

void HelperOpenCV::DrawEllipse( Mat img,  float x1, float y1, float rx, float ry, float angle ){
    Point cen = Point(x1,y1);
    DrawEllipse(img,cen,rx,ry,angle);
}
/**
 * @function MyEllipse
 * @brief Draw a fixed-size ellipse with different angles
 */
void HelperOpenCV::DrawEllipse( Mat img, Point center, float rx, float ry, float angle ){
  int thickness = 2;
  int lineType = 8;

  ellipse( img,
	   center,
	   Size( rx, ry),
	   angle,
	   0, 
	   360,
	   Scalar( 255, 0, 0 ),
	   thickness,
	   lineType );  
}

void HelperOpenCV::DrawEllipse( Mat img, Point center, float rx, float ry, float angle, Scalar col ){
  int thickness = 2;
  int lineType = 8;

  ellipse( img,
	   center,
	   Size( rx, ry),
	   angle,
	   0, 
	   360,
	   col,
	   thickness,
	   lineType );  
}

void HelperOpenCV::DrawCircle( Mat img, float x1, float y1 , float rad){
        Point cen = Point( x1, y1 );
        DrawCircle(img,cen,rad);
}

void HelperOpenCV::DrawCircle( Mat img, Point center , float rad){
  int thickness = -1;
  int lineType = 8;

  circle( img, 
	  center,
	  rad,
	  Scalar( 0, 0, 255 ),
	  thickness, 
	  lineType );
}

void HelperOpenCV::DrawCircle( Mat img, Point center , float rad,Scalar col){
  int thickness = -1;
  int lineType = 8;

  circle( img, 
	  center,
	  rad,
	  col,
	  thickness, 
	  lineType );
}

void HelperOpenCV::DrawRectangle( Mat img, float l1x, float l1y, float l2x, float l2y){
    Point l1 = Point( l1x, l1y );
    Point l2 = Point( l2x, l2y );
    DrawRectangle(img,l1,l2);
}

void HelperOpenCV::DrawRectangle( Mat img, float l1x, float l1y, float l2x, float l2y,Scalar col){
    Point l1 = Point( l1x, l1y );
    Point l2 = Point( l2x, l2y );
    DrawRectangle(img,l1,l2,col);
}
void HelperOpenCV::DrawRectangle( Mat img, Point center, float len, float wid){
    float l1x = center.x-(len/2);
    float l1y = center.y-(wid/2);
    float l2x = center.x+(len/2);
    float l2y = center.y+(wid/2);
    Point l1 = Point( l1x, l1y );
    Point l2 = Point( l2x, l2y );
    DrawRectangle(img,l1,l2);
}

void HelperOpenCV::DrawRectangle( Mat img, Point center, float len, float wid,Scalar col){
    float l1x = center.x-(len/2);
    float l1y = center.y-(wid/2);
    float l2x = center.x+(len/2);
    float l2y = center.y+(wid/2);
    Point l1 = Point( l1x, l1y );
    Point l2 = Point( l2x, l2y );
    DrawRectangle(img,l1,l2,col);
}

void HelperOpenCV::DrawRectangle( Mat img, Point l1,Point l2){
  int thickness = -1;
  int lineType = 8;

  rectangle( img, 
	  l1,
	  l2,
	  Scalar( 0, 0, 255 ),
	  thickness, 
	  lineType );
}

void HelperOpenCV::DrawRectangle( Mat img, Point l1,Point l2,Scalar col){
  int thickness = -1;
  int lineType = 8;

  rectangle( img, 
        l1,
        l2,
        col,
        thickness, 
        lineType );
}

void HelperOpenCV::DrawLine( Mat img,float l1x, float l1y, float l2x, float l2y){
    Point l1 = Point( l1x, l1y );
    Point l2 = Point( l2x, l2y );
    DrawLine(img,l1,l2);
}

void HelperOpenCV::DrawLine( Mat img, Point start, Point end ){
  int thickness = 2;
  int lineType = 8;
  line(img, 
	start,
	end,
	Scalar( 0, 0, 0 ),
	thickness,
	lineType);
}

void HelperOpenCV::DrawLine( Mat img, Point start, Point end , Scalar col){
  int thickness = 2;
  int lineType = 8;
  line(img, 
	start,
	end,
	col,
	thickness,
	lineType);
}

Mat HelperOpenCV::getBlankFloatImage( int wid, int len){
    return Mat::zeros( wid, len, CV_8UC3 );
}

Mat HelperOpenCV::getImageMat(string filename){
    return imread(filename);
}

Scalar HelperOpenCV::getColor(float b, float g, float r){
    return Scalar(b,g,r);
}

Point HelperOpenCV::getPoint(float x, float y){
    return Point(x,y);
}

void HelperOpenCV::SaveImage(std::string dir,Mat image){
    imwrite( dir.c_str(), image);
}

void HelperOpenCV::DisplayImage(std::string name, Mat image){
    imshow( name.c_str(),image );
}

void HelperOpenCV::MoveDisplayedImage(std::string name, int mx, int my){
    cvMoveWindow( name.c_str(), mx, my );
}

Scalar HelperOpenCV::getPointColor(Mat img,int x,int y){
    Scalar bgrPixel = img.at<Scalar>(x, y);
    return bgrPixel;
}

float HelperOpenCV::getPointColorB(Mat img,int x,int y){
    Scalar bgrPixel = img.at<Scalar>(x, y);
    return bgrPixel[0];
}

float HelperOpenCV::getPointColorG(Mat img,int x,int y){
    Scalar bgrPixel = img.at<Scalar>(x, y);
    return bgrPixel[1];
}

float HelperOpenCV::getPointColorR(Mat img,int x,int y){
    Scalar bgrPixel = img.at<Scalar>(x, y);
    return bgrPixel[2];
}

/**
 * @function main
 * @brief Main function
 */
int mainCVHelper( int argc, char **argv ){
    HelperOpenCV *helper = new HelperOpenCV();
    /// Windows names
    char window[] = "Drawing 1";

    /// Create black empty images 
    Mat image = helper->getBlankFloatImage(400,400);
    helper->DrawCircle(image,200.0,200.0,15.0);
    helper->DrawRectangle(image,0.0,0.0,45.0,45.0);
    helper->DrawRectangle(image,50.0,50.0,145.0,145.0,helper->getColor(50,50,50));
    
    /// 3. Display your stuff!
    imshow( window,image );
    cvMoveWindow( window, 0, 200 );

    // Save Image
    imwrite( "test.png", image );

    waitKey( 0 );
    delete helper;
    return(0);
}
