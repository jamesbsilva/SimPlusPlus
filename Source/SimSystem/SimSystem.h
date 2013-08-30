#ifndef SIMSYSTEM_H
#define	SIMSYSTEM_H

/* 
 * @(#) SimSystem.h
 */

#include <iostream>

/* 
 * File:   SimSystem.h
 * 
 *              @class SimSystem
 *      
 *      @brief 
 * 
 * @author James B. Silva <jbsilva@bu.edu>
 * 
 * Created on October 19, 2012, 8:04 PM
 * 
 * * $Header $
 */
using namespace std;

class SimSystem{
    public:
        int getDimension() const;
        int getSize() const;        
        double getValue(int) const;
    private:
            
};

#endif	/* SIMSYSTEM_H */
