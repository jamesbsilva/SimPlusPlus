// File and Version Information:   ProcessHandlerCLGL.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include "ProcessHandlerCLGL.h"

void ProcessHandlerCLGL::initOpenCL(string deviceType, string vendorName=""){
        // Get available platforms
        cl::Platform::get(&platforms);
        uint platformInd = 0;
        if(vendorName == ""){
            if(deviceType.find("GPU") != string::npos || deviceType.find("gpu") != string::npos){
                for(uint u = 0; u < platforms.size();u++){
                    if(doesPlatformHaveGPU(u)){
                        platformInd = u;break;
                    }
                }
            }
        }else{
            platformInd = findPlatformByName(vendorName);
        }
        
        
        // Select the default platform and create a context using this platform and the GPU
        cl_context_properties properties[] =
            { CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[platformInd])(), 0};
        context = cl::Context(CL_DEVICE_TYPE_ALL, properties);

        // Get a list of devices on this platform
        devices = context.getInfo<CL_CONTEXT_DEVICES>();
        printf("Platform has %d devices.\n",devices.size());

        uint dInd=0;
        
        if(deviceType.find("GPU") != string::npos || deviceType.find("gpu") != string::npos ){
            dInd = findMaxFlopsGPU(platformInd);
        }else if(deviceType.find("CPU") != string::npos || deviceType.find("cpu") != string::npos ){
            dInd = findMaxFlopsCPU(platformInd);
        }else{
            dInd = findMaxFlopsDevice(platformInd);
        }
        // Create a command queue and use the first device
        queue = cl::CommandQueue(context, devices[dInd]);
 }

void ProcessHandlerCLGL::printDeviceInfo(cl::Device dev){
        char cBuffer[124];
        uint max;
        std::size_t maxitems[3];
        ulong maxu;
        printf("-----------------------------\n");
        printf("__Device Information______ \n");
        dev.getInfo(CL_DEVICE_VENDOR,&cBuffer);
        printf("Vendor: %s \n",cBuffer);
        cl_device_type dtype;
        dev.getInfo(CL_DEVICE_TYPE,&dtype);
        dev.getInfo(CL_DEVICE_NAME,&cBuffer);
        if(dtype == CL_DEVICE_TYPE_GPU){
                printf("GPU | Device Name: %s \n",cBuffer);
        }else{
                printf("CPU/Accelerator/(NonGPU) |Device Name: %s \n",cBuffer);
        }
        dev.getInfo(CL_DEVICE_MAX_COMPUTE_UNITS,&max);
        printf("Max Compute Units: %i \n",max);
        dev.getInfo(CL_DEVICE_MAX_CLOCK_FREQUENCY,&max);
        printf("Max Clock Frequency: %i \n",max);
        dev.getInfo(CL_DEVICE_MAX_WORK_GROUP_SIZE,&maxitems);
        printf("Max Work Group Size: %i \n",static_cast<uint>(maxitems[0]));
        dev.getInfo(CL_DEVICE_MAX_WORK_ITEM_SIZES,&maxitems);
        printf("Max Work Items Size: %i \n",static_cast<uint>(maxitems[0]));
        dev.getInfo(CL_DEVICE_GLOBAL_MEM_SIZE,&maxu);
        printf("Max Global Memory in Mb: %i \n",static_cast<int>(maxu/(1024*1024)));
        printf("Max L for 2d int array in global memory: %i \n",static_cast<int>(sqrt(maxu/sizeof(int))));
        printf("Max L for 2d float array in global memory: %i \n",static_cast<int>(sqrt(maxu/sizeof(float))));
        printf("-----------------------------\n");
}

bool ProcessHandlerCLGL::doesPlatformHaveGPU(int i){
    cl_context_properties properties[] =
        { CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[i])(), 0};
    cl::Context contextTemp = cl::Context(CL_DEVICE_TYPE_ALL, properties);

    // Get a list of devices on this platform
    cl::vector<cl::Device> devicesTemp = context.getInfo<CL_CONTEXT_DEVICES>();

    for(int u = 0; u < devicesTemp.size();u++){
        cl_device_type dtype;
        devicesTemp[u].getInfo(CL_DEVICE_TYPE,&dtype);
        if(dtype == CL_DEVICE_TYPE_GPU){
            return true;
        }
    }
    return false;
}


int ProcessHandlerCLGL::findMaxFlopsGPU(int i){
    cl_context_properties properties[] =
        { CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[i])(), 0};
    cl::Context contextTemp = cl::Context(CL_DEVICE_TYPE_ALL, properties);
    // Get a list of devices on this platform
    cl::vector<cl::Device> devicesTemp = context.getInfo<CL_CONTEXT_DEVICES>();
    
    char cBuffer[124];
    uint maxFlopsIndex=-1;uint maxFlops=0;int flops;
    uint max;uint units;
    
    for(int u = 0; u < devicesTemp.size();u++){
        cl_device_type dtype;
        devicesTemp[u].getInfo(CL_DEVICE_TYPE,&dtype);
        if(dtype == CL_DEVICE_TYPE_GPU){
            devicesTemp[u].getInfo(CL_DEVICE_NAME,&cBuffer);
            string name(cBuffer);
            devicesTemp[u].getInfo(CL_DEVICE_VENDOR,&cBuffer);
            string vendor(cBuffer);
            // Intel does not make GPUs that are openCL compatible and AMD flags Intel CPUs as GPUs
            if(vendor.find("Intel")!= string::npos || vendor.find("INTEL")!= string::npos ||
                    name.find("Intel")!= string::npos || name.find("INTEL")!= string::npos){
            }else{
                devicesTemp[u].getInfo(CL_DEVICE_MAX_COMPUTE_UNITS,&units);
                devicesTemp[u].getInfo(CL_DEVICE_MAX_CLOCK_FREQUENCY,&max);
                flops = units*max;
                if(flops>maxFlops){
                    maxFlops = flops;
                    maxFlopsIndex = u;
                }
            }
        }    
    }
    return maxFlopsIndex;
}
  
int ProcessHandlerCLGL::findMaxFlopsDevice(int i){
    cl_context_properties properties[] =
        { CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[i])(), 0};
    cl::Context contextTemp = cl::Context(CL_DEVICE_TYPE_ALL, properties);
    // Get a list of devices on this platform
    cl::vector<cl::Device> devicesTemp = context.getInfo<CL_CONTEXT_DEVICES>();
    
    char cBuffer[124];
    uint maxFlopsIndex=-1;uint maxFlops=0;int flops;
    uint max;uint units;
    
    for(int u = 0; u < devicesTemp.size();u++){
        cl_device_type dtype;
        devicesTemp[u].getInfo(CL_DEVICE_MAX_COMPUTE_UNITS,&units);
        devicesTemp[u].getInfo(CL_DEVICE_MAX_CLOCK_FREQUENCY,&max);
        flops = units*max;
        if(flops>maxFlops){
            maxFlops = flops;
            maxFlopsIndex = u;
        }    
    }
    return maxFlopsIndex;
}
    
int ProcessHandlerCLGL::findMaxFlopsCPU(int i){
    cl_context_properties properties[] =
        { CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[i])(), 0};
    cl::Context contextTemp = cl::Context(CL_DEVICE_TYPE_ALL, properties);
    // Get a list of devices on this platform
    cl::vector<cl::Device> devicesTemp = context.getInfo<CL_CONTEXT_DEVICES>();
    
    char cBuffer[124];
    uint maxFlopsIndex=-1;uint maxFlops=0;int flops;
    uint max;uint units;
    
    for(int u = 0; u < devicesTemp.size();u++){
        cl_device_type dtype;
        devicesTemp[u].getInfo(CL_DEVICE_TYPE,&dtype);
        if(dtype == CL_DEVICE_TYPE_CPU){
            devicesTemp[u].getInfo(CL_DEVICE_NAME,&cBuffer);
            string name(cBuffer);
            devicesTemp[u].getInfo(CL_DEVICE_VENDOR,&cBuffer);
            string vendor(cBuffer);
            // NVIDIA and ATI do not make CPUs
            if(vendor.find("ATI")!= string::npos || vendor.find("Ati")!= string::npos ||
                    vendor.find("NVIDIA")!= string::npos || vendor.find("Nvidia")!= string::npos){
            }else{
                devicesTemp[u].getInfo(CL_DEVICE_MAX_COMPUTE_UNITS,&units);
                devicesTemp[u].getInfo(CL_DEVICE_MAX_CLOCK_FREQUENCY,&max);
                flops = units*max;
                if(flops>maxFlops){
                    maxFlops = flops;
                    maxFlopsIndex = u;
                }
            }
        }    
    }
    devicesTemp=0;
    return maxFlopsIndex;
}

int ProcessHandlerCLGL::findPlatformByName(string vendorName){
        uint found = -3;
        char cBuffer[124];
        for(uint i = 0; i < platforms.size();i++){
            cl_context_properties properties[] =
                { CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[i])(), 0};
            cl::Context contextTemp = cl::Context(CL_DEVICE_TYPE_ALL, properties);
            // Get a list of devices on this platform
            cl::vector<cl::Device> devicesTemp = context.getInfo<CL_CONTEXT_DEVICES>();
            string vendor(cBuffer);
            devicesTemp[i].getInfo(CL_DEVICE_VENDOR,&vendor);
            if(vendor.find(vendorName)!= string::npos ){
                found = i;
                return found;
            }
         }        
        return found;
}

void ProcessHandlerCLGL::initOpenCLGL(string vendorName="", string deviceType="GPU"){
        // Get available platforms
        cl::Platform::get(&platforms);
        uint platformUsed = 0;
        if(vendorName == ""){}else{
            platformUsed = findPlatformByName(vendorName);
        }
        if(vendorName == "" && 
                (deviceType.find("GPU") != string::npos || deviceType.find("gpu") != string::npos)){
            for(uint u = 0; u < platforms.size();u++){
                if(doesPlatformHaveGPU(u)){
                    platformUsed = u;break;
                }
            }
        }else{}
        
        // Select the default platform and create a context using this platform and the GPU
        cl_context_properties properties[] =
            { CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[platformUsed])(), 0};
        context = cl::Context(CL_DEVICE_TYPE_ALL, properties);

        // Get a list of devices on this platform
        devices = context.getInfo<CL_CONTEXT_DEVICES>();
        printf("Platform has %d devices.\n",devices.size());

        uint deviceUsed=0;
        
        if(deviceType.find("GPU") != string::npos || deviceType.find("gpu") != string::npos ){
            deviceUsed = findMaxFlopsGPU(platformUsed);
        }else if(deviceType.find("CPU") != string::npos || deviceType.find("cpu") != string::npos ){
            deviceUsed = findMaxFlopsCPU(platformUsed);
        }else{
            deviceUsed = findMaxFlopsDevice(platformUsed);
        }
    
        // Define OS-specific context properties and create the OpenCL context
        // We setup OpenGL context sharing slightly differently on each OS
        // this code comes mostly from NVIDIA's SDK examples
        // we could also check to see if the device supports GL sharing
        // but that is just searching through the properties
        // an example is avaible in the NVIDIA code
        #if defined (__APPLE__) || defined(MACOSX)
            CGLContextObj kCGLContext = CGLGetCurrentContext();
            CGLShareGroupObj kCGLShareGroup = CGLGetShareGroup(kCGLContext);
            cl_context_properties props[] =
            {
                CL_CONTEXT_PROPERTY_USE_CGL_SHAREGROUP_APPLE, (cl_context_properties)kCGLShareGroup,
                0
            };
            //Apple's implementation is weird, and the default values assumed by cl.hpp don't work
            //this works
            //cl_context cxGPUContext = clCreateContext(props, 0, 0, NULL, NULL, &err);
            //these dont
            //cl_context cxGPUContext = clCreateContext(props, 1,(cl_device_id*)&devices.front(), NULL, NULL, &err);
            //cl_context cxGPUContext = clCreateContextFromType(props, CL_DEVICE_TYPE_GPU, NULL, NULL, &err);
            //printf("error? %s\n", oclErrorString(err));
            try{
                context = cl::Context(props);   //had to edit line 1448 of cl.hpp to add this constructor
            }
            catch (cl::Error er) {
                printf("ERROR: %s(%s)\n", er.what(), oclErrorString(er.err()));
            }
        #else
            #if defined WIN32 // Win32
                cl_context_properties props[] =
                {
                    CL_GL_CONTEXT_KHR, (cl_context_properties)wglGetCurrentContext(),
                    CL_WGL_HDC_KHR, (cl_context_properties)wglGetCurrentDC(),
                    CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[platformUsed])(),
                    0
                };
                //cl_context cxGPUContext = clCreateContext(props, 1, &cdDevices[uiDeviceUsed], NULL, NULL, &err);
                try{
                    context = cl::Context(CL_DEVICE_TYPE_GPU, props);
                }
                catch (cl::Error er) {
                    printf("ERROR: %s(%s)\n", er.what(), oclErrorString(er.err()));
                }
            #else
                cl_context_properties props[] =
                {
                    CL_GL_CONTEXT_KHR, (cl_context_properties) glXGetCurrentContext(),
                    CL_GLX_DISPLAY_KHR, (cl_context_properties) glXGetCurrentDisplay(),
                    CL_CONTEXT_PLATFORM, (cl_context_properties)(platforms[platformUsed])(),
                    0
                };
                
                //cl_context cxGPUContext = clCreateContext(props, 1, &cdDevices[uiDeviceUsed], NULL, NULL, &err);
                try{
                    context = cl::Context(CL_DEVICE_TYPE_GPU, props);
                }
                catch (cl::Error er) {
                    printf("ERROR: %s(%s)\n", er.what(), oclErrorString(er.err()));
                }
            #endif
        #endif

        //create the command queue we will use to execute OpenCL commands
        try{
            queue = cl::CommandQueue(context, devices[deviceUsed], 0, &err);
        }
        catch (cl::Error er) {
            printf("ERROR: %s(%d)\n", er.what(), er.err());
        }
}

void ProcessHandlerCLGL::initOpenGL(int argc, char** argv){
    glHandler->init_gl(argc,argv);
}

void ProcessHandlerCLGL::popCorn(string filename){
    //printf("in popCorn\n");
    cl::Program program = loadProgram(getSourceString(filename,true));
    int kernelInd = kernels.size();
    cl::Kernel kernelNew;
    //initialize our kernel from the program
    try{
        kernelNew = cl::Kernel(program, kernels[kernelInd].name.c_str(), &err);
    }catch (cl::Error er) {
        printf("ERROR: %s(%s)\n", er.what(), oclErrorString(er.err()));
    }
    
    //set the arguments of our kernel
    try{
        cl::vector<kernelArg> args = kernels[kernelInd].args;
        for(int u = 0; u < args.size();u++){
            err = kernelNew.setArg(args[u].bufferIndex, args[u].buffer);
        } 
    }catch (cl::Error er) {
        printf("ERROR: %s(%s)\n", er.what(), oclErrorString(er.err()));
    }
    //Wait for the command queue to finish these commands before proceeding
    queue.finish();
}

void ProcessHandlerCLGL::setKernel(string kernelName){
    for(int u = 0; u < kernels.size(); u++){
        if(kernels[u].name == kernelName){
            currKernel = kernels[u].kernel;
            currArgs = kernels[u].args;
            currGlArgsMem = kernels[u].glArgsMem;
        }
    }
}


void ProcessHandlerCLGL::runCurrentKernel(int num = 64){    
    if(useGL){
        //this will update our system by calculating new velocity and updating the positions of our particles
        //Make sure OpenGL is done using our VBOs
        glFinish();
        // map OpenGL buffer object for writing from OpenCL
        //this passes in the vector of VBO buffer objects (position and color)
        err = queue.enqueueAcquireGLObjects(&currGlArgsMem, NULL, &event);
        //printf("acquire: %s\n", oclErrorString(err));
    }
    queue.finish();

    float dt = .01f;
    
    //execute the kernel
    err = queue.enqueueNDRangeKernel(currKernel, cl::NullRange, cl::NDRange(num), cl::NullRange, NULL, &event); 
    //printf("clEnqueueNDRangeKernel: %s\n", oclErrorString(err));
    queue.finish();

    if(useGL){
        //Release the VBOs so OpenGL can play with them
        err = queue.enqueueReleaseGLObjects(&currGlArgsMem, NULL, &event);
        //printf("release gl: %s\n", oclErrorString(err));
        queue.finish();
    }
}

void ProcessHandlerCLGL::runKernel(string kernelName){
    setKernel(kernelName);
    runCurrentKernel();
}

cl::Program ProcessHandlerCLGL::loadProgram(string kernel_source){
    // Program Setup
    int pl;
    //size_t program_length;
    printf("load the program\n");
    cl::Program program;
    int ks = kernel_source.size();
    try{
        cl::Program::Sources source(1,
            make_pair(kernel_source.c_str(), ks));
        program = cl::Program(context, source);
    }catch (cl::Error er){
        printf("ERROR: %s(%s)\n", er.what(), oclErrorString(er.err()));
    }

    printf("build program\n");
    try{
        err = program.build(devices);
    }catch (cl::Error er){
        printf("program.build: %s\n", oclErrorString(er.err()));
    }
    
    printf("done building program\n");
	std::cout << "Build Status: " << program.getBuildInfo<CL_PROGRAM_BUILD_STATUS>(devices[deviceIdUsed[0]]) << std::endl;
	std::cout << "Build Options:\t" << program.getBuildInfo<CL_PROGRAM_BUILD_OPTIONS>(devices[deviceIdUsed[0]]) << std::endl;
	std::cout << "Build Log:\t " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(devices[deviceIdUsed[0]]) << std::endl;
        
        return program;
}

string ProcessHandlerCLGL::getSourceString(string filename,bool addKernel){
    cl::vector<string> file = cl::vector<string>();
    ifstream myfile (filename.c_str());
    string kernelArgLine("");
    bool stillSavingKernelLine = false;
    if (myfile.is_open()){
        while ( myfile.good()){
            string line;
            getline (myfile,line);
            // Dont bother including comments if possible
            if(line.find("//") < 5){
            }else{
            file.push_back(line);}
            
            if(stillSavingKernelLine){
                kernelArgLine.append(line);
            }
            if(stillSavingKernelLine && (line.find(")") != string::npos)){
                stillSavingKernelLine = false;
            }
            if(line.find("__kernel") != string::npos){
                kernelArgLine.append(line);
                stillSavingKernelLine = true;
            }
        }
        myfile.close();
    }
    string source("");
    
    // addNew
    if(addKernel){
        kernelPackage newKern = buffHandler->parseKernelPackage(kernelArgLine);
        kernels.push_back(newKern);
    }
    
    for(int u = 0; u < file.size();u++){
        source.append(file[u]);
    }
    
    return source;
}


// Helper function to get error string from NVIDIA SDK
// *********************************************************************
const char* ProcessHandlerCLGL::oclErrorString(cl_int error){
    static const char* errorString[] = {
        "CL_SUCCESS",
        "CL_DEVICE_NOT_FOUND",
        "CL_DEVICE_NOT_AVAILABLE",
        "CL_COMPILER_NOT_AVAILABLE",
        "CL_MEM_OBJECT_ALLOCATION_FAILURE",
        "CL_OUT_OF_RESOURCES",
        "CL_OUT_OF_HOST_MEMORY",
        "CL_PROFILING_INFO_NOT_AVAILABLE",
        "CL_MEM_COPY_OVERLAP",
        "CL_IMAGE_FORMAT_MISMATCH",
        "CL_IMAGE_FORMAT_NOT_SUPPORTED",
        "CL_BUILD_PROGRAM_FAILURE",
        "CL_MAP_FAILURE",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "CL_INVALID_VALUE",
        "CL_INVALID_DEVICE_TYPE",
        "CL_INVALID_PLATFORM",
        "CL_INVALID_DEVICE",
        "CL_INVALID_CONTEXT",
        "CL_INVALID_QUEUE_PROPERTIES",
        "CL_INVALID_COMMAND_QUEUE",
        "CL_INVALID_HOST_PTR",
        "CL_INVALID_MEM_OBJECT",
        "CL_INVALID_IMAGE_FORMAT_DESCRIPTOR",
        "CL_INVALID_IMAGE_SIZE",
        "CL_INVALID_SAMPLER",
        "CL_INVALID_BINARY",
        "CL_INVALID_BUILD_OPTIONS",
        "CL_INVALID_PROGRAM",
        "CL_INVALID_PROGRAM_EXECUTABLE",
        "CL_INVALID_KERNEL_NAME",
        "CL_INVALID_KERNEL_DEFINITION",
        "CL_INVALID_KERNEL",
        "CL_INVALID_ARG_INDEX",
        "CL_INVALID_ARG_VALUE",
        "CL_INVALID_ARG_SIZE",
        "CL_INVALID_KERNEL_ARGS",
        "CL_INVALID_WORK_DIMENSION",
        "CL_INVALID_WORK_GROUP_SIZE",
        "CL_INVALID_WORK_ITEM_SIZE",
        "CL_INVALID_GLOBAL_OFFSET",
        "CL_INVALID_EVENT_WAIT_LIST",
        "CL_INVALID_EVENT",
        "CL_INVALID_OPERATION",
        "CL_INVALID_GL_OBJECT",
        "CL_INVALID_BUFFER_SIZE",
        "CL_INVALID_MIP_LEVEL",
        "CL_INVALID_GLOBAL_WORK_SIZE",
    };

    const int errorCount = sizeof(errorString) / sizeof(errorString[0]);

    const int index = -error;

    return (index >= 0 && index < errorCount) ? errorString[index] : "";

}
