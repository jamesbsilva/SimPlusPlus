#ifndef REPRESENTATION_H
#define	REPRESENTATION_H


/* 
 * @(#) Representation.h
 */

#include <vector>

/* 
 * File:   Representation.h
 * 
 *              @class Representation
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on October 24, 2012, 12:54 AM
 * 
 * * $Header $
 */

using namespace std; 

struct defColor{
    float value;
    float b;
    float g;
    float r;
    
    defColor() : value(), b(), g(), r() {}
    defColor(float v,float b1,float g1,float r1) : value(v), b(b1),g(g1),r(r1){}
};

class Representation{
    public:
        std::vector<defColor> getColorDefs();
        virtual ~Representation();
    private:
        
};

#endif	/* REPRESENTATION_H */

