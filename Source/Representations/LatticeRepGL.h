#ifndef LATTICEREPGL_H
#define	LATTICEREPGL_H


/* 
 * @(#) RepresentationGL.h
 */
//OpenGL stuff
#include <GL/glew.h>
#if defined __APPLE__ || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "../OpenGLCL/ProcessHandlerCLGL.h"



/* 
 * File:   LatticeRepGL.h
 * 
 *              @class LatticeRepGL
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on October 24, 2012, 12:57 AM
 * 
 * * $Header $
 */
using namespace std; 
*
class LatticeRepGL : public RepresentationGL{
    public:
        void updateWindow();
        void initRep();
        
    private:
                //GL related variables
        int window_width = 800;
        int window_height = 600;
        int glutWindowHandle = 0;
        float translate_z = -1.f;
        // mouse controls
        int mouse_old_x, mouse_old_y;
        int mouse_buttons = 0;
        float rotate_x = 0.0, rotate_y = 0.0;
        int N;
        int c_vbo;
        int p_vbo;
        
        ProcessHandlerCLGL * clglHandler;
};

#endif	/* LATTICEREPGL_H */

