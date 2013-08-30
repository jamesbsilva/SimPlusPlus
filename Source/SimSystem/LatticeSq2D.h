#ifndef LATTICESQ2D_H
#define	LATTICESQ2D_H

/* 
 * @(#) LatticeSq2D.h
 */
#include <iostream>
#include <stdio.h>
#include "SimSystem.h"

/* 
 * File:   Lattice2D.h
 * 
 *              @class Lattice
 *      
 *      @brief 
 * 
 * @author James B. Silva <jbsilva@bu.edu>
 * 
 * Created on October 19, 2012, 8:06 PM
 * 
 * * $Header $
 */
template<class T>
class LatticeSq2D : public SimSystem{
        public:
            LatticeSq2D();
            LatticeSq2D(int);
            LatticeSq2D(int,T);
            ~LatticeSq2D();
            int getDimension() const;
            int getSize() const;
            T getValue(int,int) const;
            T getValue(int) const;
            void setValue(int,int,T);
            T getSum() const;
            T calcSum() const;
            T getSumSqRange(int,int,int) const;
        
        private:
            int L;
            T sum;
            T * lattice;
            static const int dimension=2;
            int size;
            int getIndexX(int);
            int getIndexY(int);
            int getIndex(int,int);
};


#endif	/* LATTICESQ2D_H */

