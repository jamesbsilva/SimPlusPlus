#ifndef GLHANDLERIO_H
#define	GLHANDLERIO_H


/* 
 * @(#) GLHandlerIO.h
 */

#include <sstream> 
#include <iostream> 
#include <fstream>
#include "GlewGlut.h"
#include "../Representations/RepresentationGL.h"

/* 
 * File:   GLHandlerIO.h
 * 
 *              @class GLHandlerIO
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on October 24, 2012, 9:38 PM
 * 
 * * $Header $
 */
using namespace std;

class GLHandlerIO{
    public:
        void init_gl(int,char**);
        static void winRender();
        void switchDefaultRepresentation(RepresentationGL);
        static void winDestroy();
        GLuint createVBO(const void*, int, GLenum, GLenum);
        
    private:
        //GL related variables
        int window_width;
        int window_height;
        static int glutWindowHandle;
        static float translate_z;
        // mouse controls
        static int mouse_old_x, mouse_old_y;
        static int mouse_buttons;
        static string currKernel;
        static float rotate_x, rotate_y;

        static void winMotion(int, int);
        static void winMouse(int,int, int, int);
        static void winKeyboard(unsigned char, int, int);
        static void timerCB(int);
        
        static RepresentationGL representation;
};

#endif	/* GLHANDLERIO_H */

