#ifndef PROCESSHANDLERCLGL_H
#define	PROCESSHANDLERCLGL_H

/* 
 * @(#) ProcessHandlerCLGL
 */

#define __NO_STD_VECTOR // Use cl::vector instead of STL version
#define __CL_ENABLE_EXCEPTIONS
#define GLHANDLERIN 1
#include "GLHandlerIO.h"
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "../Representations/RepresentationGL.h"
#include "BufferHandlerCLGL.h"
// CL should go after GLUT/GLEW which is in GL Handler
#include <CL/cl.hpp>
#include "KernelPackage.h"

/* 
 * File:   ProcessHandlerCLGL.h
 * 
 *              @class ProcessHandlerCLGL
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
class RepresentationGL;
class GLHandlerIO;
class BufferHandlerCLGL;

class ProcessHandlerCLGL{
    public:
        void initOpenCL();
        void initOpenCL(string,string);
        void initOpenGL(int,char**);
        void initOpenCLGL();
        void initOpenCLGL(string);
        void initOpenCLGL(string,string);
        void runKernel(string);
        void runCurrentKernel(int);
        void popCorn(string);
        void updateKernelPacks(kernelPackage);
        
    private:
        void printDeviceInfo(cl::Device);
        int findMaxFlopsDevice(int);
        int findMaxFlopsGPU(int);
        int findMaxFlopsCPU(int);
        bool doesPlatformHaveGPU(int);
        int findPlatformByName(string);
        cl::Program loadProgram(string);
        void setKernel(string);
        string getSourceString(string,bool);
        // CL Handling. belongs here
        const char* oclErrorString(cl_int);
        
        cl::vector<cl::Device> devices;
        cl::vector<int> deviceIdUsed;
        cl::vector<cl::Platform> platforms;
        cl::CommandQueue queue;
        cl::Context context;
        cl::Event event;
        cl::vector<kernelPackage> kernels;
        cl::Kernel currKernel;
        cl::vector<kernelArg> currArgs;
        cl::vector<cl::BufferGL> currGlArgsMem;
        BufferHandlerCLGL *buffHandler;
        GLHandlerIO *glHandler;
        RepresentationGL *represent;
        bool useGL;
        cl_int err;  //debugging variables
};

#endif	/* PROCESSHANDLERCLGL_H */

