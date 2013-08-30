#ifndef PARSERHELPER_H
#define	PARSERHELPER_H

/* 
 * @(#) ParserHelper.h
 */

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

/* 
 * File:   ParserHelper.h
 * 
 *              @class ParserHelper
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

class ParserHelper
{
        public:
        ParserHelper();
            
        string parseString(string,string,int);
        vector<string> parseVecString(string,string,int);
        int parseInt(string,string,int);
        vector<int> parseIntVec(string,string,int);
        int* parseIntArr(string,string,int);
        double parseDouble(string,string,int);
        vector<double> parseDblVec(string,string,int);
        double* parseDblArr(string,string,int);
        bool parseBool(string,string,int);
        vector<bool> parseBoolVec(string,string,int);
        bool StringToBool(string);
        bool targetExists(string,string);
        bool targetExists(vector<string>,string);
        string targetLine(vector<string>,string);
        bool targetExists(string,string,int);
        
        private:
        string getTargetSubString(string,string);
        bool debugOutput;
};

#endif	/* PARSERHELPER_H */

