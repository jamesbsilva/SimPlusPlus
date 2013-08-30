#ifndef PARAMETERS_H
#define	PARAMETERS_H

/* 
 * @(#) Parameters.h
 */

#include <fstream>
#include <stdio.h>
#include <vector>
#include "ParserHelper.h"

/* 
 * File:   Parameters.h
 * 
 *              @class Parameters
 *      
 *      @brief 
 * 
 * @author James B. Silva <jbsilva@bu.edu>
 * 
 * Created on October 20, 2012, 12:41 AM
 * 
 * * $Header $
 */
using namespace std; 

enum paramType{intParam=0,doubleParam=1,floatParam=2,boolParam=3,stringParam=4};

struct paramAliases{
    string param;
    paramType typeP;
    vector<string> aliases;
    
    paramAliases() : param(), typeP(), aliases() {}
    paramAliases(string st,paramType ty,vector<string> al) : param(st), typeP(ty),aliases(al){}
};

struct paramStrKey{
    string pId;
    int index;
    paramType typeP;
    int offset;    
    paramStrKey() : pId(), index(), typeP(), offset() {}
    paramStrKey(string st,int ind,paramType ty,int off) : pId(st), index(ind), typeP(ty),offset(off){}
};

class Parameters{
    public:
        Parameters();
        ~Parameters();
        Parameters(vector<paramAliases>, const char*);
        Parameters(vector<paramAliases>,string);
        Parameters(vector<paramAliases>);

        int getParameterI(string);
        double getParameterD(string);
        bool getParameterB(string);
        float getParameterF(string);
        string getParameter(string);
        int searchParam(string,paramType);
        paramStrKey searchParamKey(string);
        void parseParamFile(string);
        bool keyExist(string);
        void makeOutputKeysSet(vector<string>);
        vector<paramStrKey> getOutputKeysSet();

    private:
            bool doneInitializing;
            bool debugOutput;
            string paramFile;
            string delimParam;
            vector<bool> boolParams;
            vector<int> intParams;
            vector<double> dblParams;
            vector<float> flParams;
            vector<string> strParams;
            vector<paramStrKey> paramKeys;
            vector<paramStrKey> outputKeys;
            
            void initVecs();
            void initParse(vector<paramAliases>);

            void pushKey(paramAliases,paramType,int);
            void parseParamFile();
            void updateKeyValue(string, paramStrKey, ParserHelper);
            vector<string> getFileStringVector();
};

#endif	/* PARAMETERS_H */

