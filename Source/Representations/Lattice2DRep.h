#ifndef LATTICE2DREP_H
#define	LATTICE2DREP_H
/* 
 * @(#) Lattice2DRep.h
 */

#include <sstream>
#include "Representation.h"
#include "../OpenCV/HelperOpenCV.h"
#include "../Util/Files/DirHandler.h"
#include "../SimSystem/SimSystem.h"

#define MAXL 2000
#define MAXW 2000

#define MINL 400
#define MINW 400

/* 
 * File:   Lattice2DRep.h
 * 
 *              @class Lattice2DRep
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on December 29, 2012, 5:20 PM
 * 
 * * $Header $
 */
using namespace std;

class Lattice2DRep : public Representation{
    public:
        Lattice2DRep(int,int,int,bool,int);
        void update(int,int,int);
        void update(int,int,float);
        void update(int,int,float,float,float);
        void update(int,int,cv::Scalar);
        void saveImageLattice(string);
        void displayLattice();
        void changeSquareSize(int);
        void moveDisplayLat(int, int);
        void initialDraw(SimSystem);
        void changeInstId(int);
        vector<defColor> getColorDefs();
private:
        int length;
        int width;
        int squareSize;
        bool defineColors;
        long seed;
        int time;
        int instId;
        
        vector<defColor> colorDefValues; 
        cv::Mat imgLattice;
        HelperOpenCV helperCV;
        DirHandler dirs;
        int getImgLoc(int);
};

#endif	/* LATTICE2DREP_H */

