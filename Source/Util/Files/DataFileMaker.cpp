// File and Version Information:   DataFileMaker.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include "DataFileMaker.h"

void DataFileMaker::saveDoubleVec(string file, vector<double> vec){
    std::ofstream outfile;
    outfile.open(file.c_str(), std::ios_base::app);
    for(int u = 0; u < vec.size();u++){ 
        outfile << vec.at(u) << "    ";
    }
    outfile << "\n";
    
    outfile.close();
}

void DataFileMaker::saveFloatVec(string file,vector<float> vec){
    std::ofstream outfile;
    outfile.open(file.c_str(), std::ios_base::app);
    for(int u = 0; u < vec.size();u++){ 
        outfile << vec.at(u) << "    ";
    }
    outfile << "\n";
    
    outfile.close();
}

void DataFileMaker::saveIntVec(string file,vector<int> vec){
    std::ofstream outfile;
    outfile.open(file.c_str(), std::ios_base::app);
    for(int u = 0; u < vec.size();u++){ 
        outfile << vec.at(u) << "    ";
    }
    outfile << "\n";
    
    outfile.close();
}

void DataFileMaker::saveIntArr(string file,int arr[],int size){
    std::ofstream outfile;
    outfile.open(file.c_str(), std::ios_base::app);
    for(int u = 0; u < size;u++){ 
        outfile << arr[u] << "    ";
    }
    outfile << "\n";
    
    outfile.close();

}
void DataFileMaker::saveDoubleArr(string file,double arr[],int size){
    std::ofstream outfile;
    outfile.open(file.c_str(), std::ios_base::app);
    for(int u = 0; u < size;u++){ 
        outfile << arr[u] << "    ";
    }
    outfile << "\n";
    
    outfile.close();
}

void DataFileMaker::saveFloatArr(string file,float arr[],int size){
    std::ofstream outfile;
    outfile.open(file.c_str(), std::ios_base::app);
    for(int u = 0; u < size;u++){ 
        outfile << arr[u] << "    ";
    }
    outfile << "\n";
    
    outfile.close();
}
