#ifndef REPRESENTATIONGL_H
#define	REPRESENTATIONGL_H


/* 
 * @(#) RepresentationGL.h
 */
#include "Representation.h"

/* 
 * File:   RepresentationGL.h
 * 
 *              @class RepresentationGL
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on October 24, 2012, 12:57 AM
 * 
 * * $Header $
 */
using namespace std; 

class RepresentationGL :  public Representation{
    public:
        void initRep();
        void windowUpdate();
    private:
};

#endif	/* REPRESENTATIONGL_H */

