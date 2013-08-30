#ifndef GLEWGLUT_H
#define	GLEWGLUT_H


/* 
 * @(#) GlewGlut.h
 */


// Mac OS X
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// Windows
#elif _WIN32
#include <stdlib.h>
#include <glew.h>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Unix
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#endif


/* 
 * File:   GlewGlut.h
 * 
 *              @class GlewGlut
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on January 16, 2013, 10:14 PM
 * 
 * * $Header $
 */


#endif	/* GLEWGLUT_H */

