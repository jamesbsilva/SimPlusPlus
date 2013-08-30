// File and Version Information:   DirHandler.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include <string>

#include "DirHandler.h"
#include "Source/Util/Parameters.h"

DirHandler::DirHandler(){
    instId = 0;
}

DirHandler::DirHandler(int ins){
    instId = ins;
}

void DirHandler::assertDir(string dir){
    vector<string> dirAll;
    replace(dir.begin(),dir.end(),'\\','/');
    dirAll = explodeString(dir,'/');
    if(UNIX){dir = "/";}else{dir = "C://";}
    for(int u = 0;u<dirAll.size();u++){
        dir = dir + dirAll.at(u) + "/";
        makeDir(dir);
    }
}

void DirHandler::makeDir(string dir){
    const char *dirname = dir.c_str();
    replace(dir.begin(),dir.end(),'\\','/');
    if(dirname[dir.size()-1]=='/'){
        dir.append("/");
    }
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)   
        CreateDirectory (dirname, NULL);
    #else
        if((mkdir(dirname,00775))==-1) {
        }
    #endif
}

vector<string> DirHandler::explodeString(const string& str, const char& ch) {
    string next = "";
    vector<string> result;
    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
    	// If we've hit the terminal character
    	if (*it == ch) {
            // If we have some characters accumulated
            if (next.length() > 0) {
                // Add them to the result vector
                result.push_back(next);
                next = "";
            }
    	} else {
            // Accumulate the next character into the sequence
            next += *it;
    	}
    }
    return result;
}


void DirHandler::setRootDir(string base){
    rootDir = base;
    updateRootDir(base);
}

void DirHandler::updateRootDir(string base){
    string rFile = "baseDir.sciparam";
    assertDir(base);
    ofstream myfile;
    myfile.open (rFile.c_str(),ios::trunc);
    myfile << base;
    myfile.close();
}

void DirHandler::setRootDir(){
    string rFile = "baseDir.sciparam";
    ifstream myfile(rFile.c_str());
    if (myfile.is_open()){
        while (myfile.good()){
            string line;
            getline (myfile,line);
            if(line.length() > 2){
                rootDir = string(line);
            }
        }
        myfile.close();
    }
}

string DirHandler::getRootDir(){
    return rootDir; 
}

string DirHandler::getImagesDir(string post=""){
    assertDir(rootDir+"Images/"+post);
    return (rootDir +"Images/"+post); 
}

string DirHandler::getSettingsDir(string post=""){
    assertDir(rootDir+"Settings/"+post);
    return (rootDir +"Settings/"+post); 
}

string DirHandler::getVideosDir(string post=""){
    assertDir(rootDir+"Videos/"+post);
    return (rootDir +"Videos/"+post); 
}

string DirHandler::getConfigsDir(string post=""){
    assertDir(rootDir+"Configs/"+post);
    return (rootDir +"Configs/"+post); 
}

string DirHandler::getScratchDir(string post=""){
    assertDir(rootDir+"Scratch/"+post);
    return (rootDir +"Scratch/"+post); 
}

string DirHandler::getScratchConfDir(string post=""){
    assertDir(rootDir+"Scratch/Configs/"+post);
    return (rootDir +"Scratch/Configs/"+post); 
}

string DirHandler::getParamsForFilename(){
    vector<paramStrKey> pOut = param.getOutputKeysSet();
    string outStr = "";
    for(int u = 0;u < pOut.size();u++){
        stringstream ss (stringstream::in | stringstream::out);
        if(pOut.at(u).typeP == intParam){
            ss << param.getParameterI(pOut.at(u).pId);
            outStr = outStr+"-"+pOut.at(u).pId+"-"+ss.str();
        }else if(pOut.at(u).typeP == doubleParam){
            ss << param.getParameterD(pOut.at(u).pId);
            outStr = outStr+"-"+pOut.at(u).pId+"-"+ss.str();
        }else if(pOut.at(u).typeP == floatParam){
            ss << param.getParameterF(pOut.at(u).pId);
            outStr = outStr+"-"+pOut.at(u).pId+"-"+ss.str();
        }else if(pOut.at(u).typeP == boolParam){
            ss << param.getParameterB(pOut.at(u).pId);
            outStr = outStr+"-"+pOut.at(u).pId+"-"+ss.str();
        }else if(pOut.at(u).typeP == stringParam){
            outStr = outStr+"-"+pOut.at(u).pId+"-"+param.getParameter(pOut.at(u).pId);
        }
    }
    return outStr;
}

void DirHandler::setParams(Parameters p){
    param = p;
}

/*
 *  Simple test of parser helper
 */
int main(int argc, char** argv) {
    DirHandler handler = DirHandler();
    handler.updateRootDir("/home/j2/SciKitNew/");
    handler.setRootDir();
    printf("RoorDir: %s \n",(handler.getRootDir()).c_str());
    printf("ImagesDir: %s \n",(handler.getImagesDir()).c_str());
    printf("ImagesDir: %s \n",(handler.getImagesDir("Test2/test3/")).c_str());
}