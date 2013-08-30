// File and Version Information:   BufferHandlerCLGL.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include <vector>

#include "BufferHandlerCLGL.h"

kernelPackage BufferHandlerCLGL::parseKernelPackage(string argLine, bool glEnable){
    //delete __kernel tag
    int endName = argLine.find("(");
    int endArgs = argLine.find(")");
    // set kernel name
    string kernelName = argLine.substr(1,endName);
    argLine = argLine.substr(endName,endArgs);
    // parse subset and argument names based on () and ,
    char *arg=new char[argLine.size()+1];
    arg[argLine.size()]=0;
    memcpy(arg,argLine.c_str(),argLine.size());
    arg = strtok(arg, ",");
    vector<string> args;
    while(arg){
        args.push_back(string (arg));
        arg = strtok(NULL, ",");
    }
    
    // parse args into types
    string argIn;
    argType typeIn;
    cl::vector<kernelArg> kernelArgs;
    for(int u  = 0; u < args.size();u++){
        argIn = args.at(u);
        if(argIn.find("int") != string::npos){
            typeIn = intArg;
        }else if(argIn.find("float") != string::npos){
            typeIn = floatArg;
        }else if(argIn.find("bool") != string::npos){
            typeIn = boolArg;
        }else if(argIn.find("long") != string::npos){
            typeIn = longArg;
        }else if(argIn.find("double") != string::npos){
            typeIn = doubleArg;
        }else{
            typeIn = stringArg;
        }
        kernelArg argPack;
        argPack.kernelName = kernelName;
        argPack.type = typeIn;
        argPack.argName = argIn;
        kernelArgs.push_back(argPack);
    }
    cl::vector<kernelArgGL> glArg;
    cl::vector<cl::BufferGL> glMem;
    //package kernel and return
    kernelPackage kernelPack;
    kernelPack.name = kernelName;
    kernelPack.args = kernelArgs;
    kernelPack.filename;
    kernelPack.isGLenabled = glEnable;
    kernelPack.glArgs = glArg;
    kernelPack.glArgsMem = glMem;
    
    return kernelPack;
}


void BufferHandlerCLGL::enableGLinArg(kernelPackage kernelPack, string arg){
    cl::vector<kernelArg> kernelArgs = kernelPack.args;
    cl::vector<kernelArg> kernelArgsOut = kernelPack.args;
    kernelArg argIn;
    // find argument in kernel pack while deleting from regular argument list
    for(int u  = 0; u < kernelArgs.size(); u++){
        if(kernelArgs[u].argName == arg){
            argIn = kernelArgs[u];
        }else{
            kernelArgsOut.push_back(kernelArgs[u]);
        }
    }
    
    // add to gl arguments
    kernelArgGL argGL;
    argGL.argName = argIn.argName;
    argGL.kernelName = argIn.kernelName;
    argGL.type = argIn.type;
    argGL.bufferIndex = argIn.bufferIndex;
    kernelPack.glArgs.push_back(argGL);
    kernelPack.args = kernelArgsOut;
    // update kernel packs
    updateKernelPacks(kernelPack);
}    

cl::Kernel BufferHandlerCLGL::findKernel(string kernelname){
    for(int u = 0; u < kernels.size();u++){
        if(kernels[u].name == kernelname){
            return kernels[u].kernel;
        }
    }
    
    return kernels[0].kernel;
}

kernelPackage BufferHandlerCLGL::findKernelPack(string kernelname){
    for(int u = 0; u < kernels.size();u++){
        if(kernels[u].name == kernelname){
            return kernels[u];
        }
    }
    
    return kernels[0];
}


void BufferHandlerCLGL::addBufferToKernelArg(kernelPackage kernelPack,string arg,cl::Buffer buffer, int bufferInd){
    cl::vector<kernelArg> args = kernelPack.args;
    kernelArg argIn;
    int argInd;
    // Find argument in kernel arguments 
    for(int u = 0; u < args.size();u++){
        if(args[u].argName == arg){
            argIn = args[u];
            argInd = u;
        }
    }
    // update buffer
    argIn.buffer = buffer;
    argIn.bufferIndex = bufferInd;
    // update argument pack
    args[argInd] = argIn;
    kernelPack.args = args;
}


void BufferHandlerCLGL::addMemoryToKernelArgGL(kernelPackage kernelPack,string arg,cl::BufferGL mem, int bufferInd, GLuint glId){
    cl::vector<kernelArgGL> args = kernelPack.glArgs;
    kernelArgGL argIn;
    int argInd;
    // Find argument in kernel arguments 
    for(int u = 0; u < args.size();u++){
        if(args[u].argName == arg){
            argIn = args[u];
            argInd = u;
        }
    }
    // update buffer
    argIn.glMemory = mem;
    argIn.bufferIndex = bufferInd;
    argIn.glId = glId;
    // update argument pack
    args[argInd] = argIn;
    kernelPack.glArgs = args;
}

void BufferHandlerCLGL::updateKernelPacks(kernelPackage kernelPack){
    // Find corresponding kernelPack in kernels and update
    for(int u = 0; u < kernels.size();u++){
        if(kernels[u].name == kernelPack.name){
            kernels[u] = kernelPack;
        }
    }
    // sync update in process handler
    //clglHandler.updateKernelPacks(kernelPack);
}

    
void BufferHandlerCLGL::createArgumentBufferInt(std::string kernelname,std::string arg, int size, int readWriteMode){
    // Create memory buffers
    cl::Buffer bufferA;
    if(readWriteMode == 0){
        bufferA = cl::Buffer(context, CL_MEM_READ_ONLY, size * sizeof(int));
    }else if(readWriteMode == 1){
        bufferA = cl::Buffer(context, CL_MEM_WRITE_ONLY, size * sizeof(int));
    }else{
        bufferA = cl::Buffer(context, CL_MEM_READ_WRITE, size * sizeof(int));
    }
    // update kernel packs with new buffer 
    int buffInd;
    kernelPackage kernelPack = findKernelPack(kernelname);
    addBufferToKernelArg(kernelPack,arg,bufferA,buffInd);
    updateKernelPacks(kernelPack);
}   

void BufferHandlerCLGL::createArgumentBufferIntGL(string kernelname, string arg, int size){
    //store the number of particles and the size in bytes of our arrays
    int array_size = size*sizeof(int);
    GLuint glID = glHandler.createVBO(0, array_size, GL_ARRAY_BUFFER, GL_DYNAMIC_DRAW);
    // create OpenCL buffer from GL VBO
    cl::BufferGL bufferCL(context, CL_MEM_READ_WRITE, glID, &err);
    kernelPackage kernelPack = findKernelPack(kernelname);
    // Add to Memory buffers
    int buffId;
    kernelPack.glArgsMem.push_back(bufferCL);
    addMemoryToKernelArgGL(kernelPack,arg,bufferCL,buffId,glID);
    updateKernelPacks(kernelPack);
} 

void BufferHandlerCLGL::createArgumentBufferInt(string kernelname, string arg, vector<int> inVec, int readWriteMode){
    // Create memory buffers    // Copy lists A and B to the memory buffers
    //queue.enqueueWriteBuffer(bufferA, CL_TRUE, 0, size * sizeof(int), A);    
}   





