#ifndef DATAFILEMAKER_H
#define	DATAFILEMAKER_H


/* 
 * @(#) DataFileMaker.h
 */

#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

/* 
 * File:   DataFileMaker.h
 * 
 *              @class DataFileMaker
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on January 1, 2013, 1:26 AM
 * 
 * * $Header $
 */
using namespace std;

class DataFileMaker{
    public:
        void saveDoubleVec(string,vector<double>);
        void saveFloatVec(string,vector<float>);
        void saveIntVec(string,vector<int>);
        void saveDoubleArr(string,double[],int);
        void saveFloatArr(string,float[],int);
        void saveIntArr(string,int[],int);
        
    private:
        
};

#endif	/* DATAFILEMAKER_H */

