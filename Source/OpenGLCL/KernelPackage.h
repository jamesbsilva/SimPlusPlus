#ifndef KERNELPACKAGE_H
#define	KERNELPACKAGE_H


/* 
 * @(#) KernelPackage.h
 */
// CL should go after GLUT/GLEW which is in GL Handler
#include <CL/cl.hpp>


/* 
 * File:   KernelPackage.h
 * 
 *              @class KernelPackage
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on January 16, 2013, 3:31 PM
 * 
 * * $Header $
 */
#include <string>
enum argType{intArg=0,doubleArg=1,floatArg=2,longArg=3,boolArg=4,stringArg=5};

struct kernelArg{
    std::string kernelName;
    std::string argName;
    argType type;
    int bufferIndex;
    cl::Buffer buffer;
};

struct kernelArgGL{
    std::string kernelName;
    std::string argName;
    argType type;
    int bufferIndex;
    GLuint glId;
    cl::BufferGL glMemory;
};

struct kernelPackage{
    std::string name;
    std::string filename;
    cl::Kernel kernel;
    bool isGLenabled;
    cl::vector<kernelArg> args;
    cl::vector<kernelArgGL> glArgs;
    cl::vector<cl::BufferGL> glArgsMem;
};

#endif	/* KERNELPACKAGE_H */

