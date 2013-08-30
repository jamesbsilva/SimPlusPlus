#ifndef LATTICESQ2DINT_H
#define	LATTICESQ2DINT_H

/* 
 * @(#) LatticeSq2DInt.h
 */
#include <iostream>
#include "SimSystem.h"

/* 
 * File:   Lattice2DInt.h
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
using namespace std;

class LatticeSq2DInt : public SimSystem{
        public:
            LatticeSq2DInt(int);
            LatticeSq2DInt();
            ~LatticeSq2DInt();
                virtual int getDimension() const;
                virtual int getSize() const;
                virtual int getValue(int,int) const;
                virtual int getValue(int) const;
                virtual void setValue(int,int,int);
                virtual int getSum() const;
                virtual int calcSum() const;
                virtual int getSumSqRange(int,int,int) const;
        private:
            int L;
            int sum;
            int * lattice;
            static const int dimension=2;
            int size;
            int getIndexX(int);
            int getIndexY(int);
            int getIndex(int,int);
};


#endif	/* LATTICESQ2DINT_H */

