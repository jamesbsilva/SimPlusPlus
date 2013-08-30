#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Source/Measurer/Accumulator.o \
	${OBJECTDIR}/Source/OpenCV/HelperOpenCV.o \
	${OBJECTDIR}/Source/OpenGLCL/BufferHandlerCLGL.o \
	${OBJECTDIR}/Source/OpenGLCL/GLHandlerIO.o \
	${OBJECTDIR}/Source/OpenGLCL/ProcessHandlerCLGL.o \
	${OBJECTDIR}/Source/Representations/Lattice2DRep.o \
	${OBJECTDIR}/Source/Representations/LatticeRepGL.o \
	${OBJECTDIR}/Source/SimSystem/LatticeSq2D.o \
	${OBJECTDIR}/Source/Util/Files/DataFileMaker.o \
	${OBJECTDIR}/Source/Util/Files/DirHandler.o \
	${OBJECTDIR}/Source/Util/Files/DragDropFileName.o \
	${OBJECTDIR}/Source/Util/Parameters.o \
	${OBJECTDIR}/Source/Util/ParserHelper.o \
	${OBJECTDIR}/Source/Util/Video/VidMaker.o \
	${OBJECTDIR}/Source/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` 
CXXFLAGS=`wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`wx-config --libs`  `pkg-config --libs glew` `pkg-config --libs gl`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f1

${TESTDIR}/TestFiles/f1: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Source/Measurer/Accumulator.o: Source/Measurer/Accumulator.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Measurer
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Measurer/Accumulator.o Source/Measurer/Accumulator.cpp

${OBJECTDIR}/Source/OpenCV/HelperOpenCV.o: Source/OpenCV/HelperOpenCV.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/OpenCV
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/OpenCV/HelperOpenCV.o Source/OpenCV/HelperOpenCV.cpp

${OBJECTDIR}/Source/OpenGLCL/BufferHandlerCLGL.o: Source/OpenGLCL/BufferHandlerCLGL.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/OpenGLCL
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/OpenGLCL/BufferHandlerCLGL.o Source/OpenGLCL/BufferHandlerCLGL.cpp

${OBJECTDIR}/Source/OpenGLCL/GLHandlerIO.o: Source/OpenGLCL/GLHandlerIO.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/OpenGLCL
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/OpenGLCL/GLHandlerIO.o Source/OpenGLCL/GLHandlerIO.cpp

${OBJECTDIR}/Source/OpenGLCL/ProcessHandlerCLGL.o: Source/OpenGLCL/ProcessHandlerCLGL.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/OpenGLCL
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/OpenGLCL/ProcessHandlerCLGL.o Source/OpenGLCL/ProcessHandlerCLGL.cpp

${OBJECTDIR}/Source/Representations/Lattice2DRep.o: Source/Representations/Lattice2DRep.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Representations
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Representations/Lattice2DRep.o Source/Representations/Lattice2DRep.cpp

${OBJECTDIR}/Source/Representations/LatticeRepGL.o: Source/Representations/LatticeRepGL.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Representations
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Representations/LatticeRepGL.o Source/Representations/LatticeRepGL.cpp

${OBJECTDIR}/Source/SimSystem/LatticeSq2D.o: Source/SimSystem/LatticeSq2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/SimSystem
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/SimSystem/LatticeSq2D.o Source/SimSystem/LatticeSq2D.cpp

${OBJECTDIR}/Source/Util/Files/DataFileMaker.o: Source/Util/Files/DataFileMaker.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Util/Files
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Util/Files/DataFileMaker.o Source/Util/Files/DataFileMaker.cpp

${OBJECTDIR}/Source/Util/Files/DirHandler.o: Source/Util/Files/DirHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Util/Files
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Util/Files/DirHandler.o Source/Util/Files/DirHandler.cpp

${OBJECTDIR}/Source/Util/Files/DragDropFileName.o: Source/Util/Files/DragDropFileName.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Util/Files
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Util/Files/DragDropFileName.o Source/Util/Files/DragDropFileName.cpp

${OBJECTDIR}/Source/Util/Parameters.o: Source/Util/Parameters.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Util
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Util/Parameters.o Source/Util/Parameters.cpp

${OBJECTDIR}/Source/Util/ParserHelper.o: Source/Util/ParserHelper.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Util
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Util/ParserHelper.o Source/Util/ParserHelper.cpp

${OBJECTDIR}/Source/Util/Video/VidMaker.o: Source/Util/Video/VidMaker.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source/Util/Video
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/Util/Video/VidMaker.o Source/Util/Video/VidMaker.cpp

${OBJECTDIR}/Source/main.o: Source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -I../../NVIDIA_GPU_Computing_SDK/shared/inc/GL -I. `pkg-config --cflags glew` `pkg-config --cflags gl`  `wx-config --cxxflags` `wx-config --libs` `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/main.o Source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
