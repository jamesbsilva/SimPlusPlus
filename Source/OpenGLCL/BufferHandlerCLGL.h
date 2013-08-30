#ifndef BUFFERHANDLERCLGL_H
#define	BUFFERHANDLERCLGL_H

/* 
 * @(#) BufferHandlerCLGL
 */

#define __NO_STD_VECTOR // Use cl::vector instead of STL version
#define __CL_ENABLE_EXCEPTIONS
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "GLHandlerIO.h"
// CL should go after GLUT/GLEW which is in GL Handler
#include <CL/cl.hpp>
#include "KernelPackage.h"
#include "ProcessHandlerCLGL.h"
/* 
 * File:   BufferHandlerCLGL.h
 * 
 *              @class BufferHandlerCLGL
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

class BufferHandlerCLGL{
        
    public:
        int getArgumentInt(string);
        int getArgumentFloat(string);
        int getArgumentLong(string);
        kernelPackage parseKernelPackage(string,bool);
        void createArgumentBufferInt(string,string,int,int);
        void createArgumentBufferInt(string,string,vector<int>,int);
        void createArgumentBufferFl(string,string,int,int);
        void createArgumentBufferLong(string,string,int,int);
        void createArgumentBufferIntGL(string,string,int);
        void createArgumentBufferFlGL(string,string,int);
        void createArgumentBufferLongGL(string,string,int);
        void enableGLinArg(kernelPackage, string);
    private:
        void parseArgsFromKernelSource(kernelPackage);
        cl::Kernel findKernel(string kern);
        kernelPackage findKernelPack(string kern);
        void addBufferToKernelArg(kernelPackage,std::string,cl::Buffer,int);
        void addMemoryToKernelArgGL(kernelPackage,std::string,cl::BufferGL,int,GLuint);
        void updateKernelPacks(kernelPackage);
        cl::vector<kernelPackage> kernels;
        cl::vector<cl::Device> devices;
        cl::vector<cl::Platform> platforms;
        cl::CommandQueue queue;
        cl::Context context;
        GLHandlerIO glHandler;
        //debugging variables
        cl_int err;
        
};


#endif	/* BUFFERHANDLERCLGL_H */

