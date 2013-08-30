#ifndef DIRHANDLER_H
#define	DIRHANDLER_H


/* 
 * @(#) DirHandler.h
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)   
    #define UNIX false
    #include <windows.h>
#else
    #define UNIX true
    #include<stdio.h>
    #include<sys/stat.h>
#endif

#include "../Parameters.h"

/* 
 * File:   DirHandler.h
 * 
 *              @class DirHandler
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on November 20, 2012, 4:42 PM
 * 
 * * $Header $
 */
using namespace std;


class DirHandler{
    public:
        DirHandler();
        DirHandler(int);
        string getRootDirectory();
        string getRootDirectory(string);
        string getImagesDirectory();
        string getImagesDirectory(string);
        void assertDir(string);
        void setRootDir(string);
        void setRootDir();
        string getRootDir();
        string getImagesDir(string);
        string getSettingsDir(string);
        string getVideosDir(string);
        string getConfigsDir(string);
        string getScratchDir(string);
        string getScratchConfDir(string);
        string getParamsForFilename();
        void setParams(Parameters);
        void updateRootDir(string);

    private:
        void makeDir(string);
        int instId;
        Parameters param;
        string rootDir;
        vector<string> explodeString(const string&, const char &);
};


#endif	/* DIRHANDLER_H */

