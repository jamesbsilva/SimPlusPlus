// File and Version Information:   GLHandlerIO.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>
#include "GLHandlerIO.h"

//----------------------------------------------------------------------
void GLHandlerIO::winRender(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //this updates the particle system by calling the kernel
    //clglHandler.runKernel(currKernel);

    representation.windowUpdate();
    
    glutSwapBuffers();
}

//----------------------------------------------------------------------
void GLHandlerIO::init_gl(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition (glutGet(GLUT_SCREEN_WIDTH)/2 - window_width/2, 
                            glutGet(GLUT_SCREEN_HEIGHT)/2 - window_height/2);

    
    stringstream ss;
    ss << "SciKit Window " << std::ends;
    glutWindowHandle = glutCreateWindow(ss.str().c_str());

    glutDisplayFunc(winRender); //main rendering function
    glutTimerFunc(30, timerCB, 30); //determine a minimum time between frames
    glutKeyboardFunc(winKeyboard);
    glutMouseFunc(winMouse);
    glutMotionFunc(winMotion);

    //Initialize GLEW.
    GLenum glew_err = glewInit();
    if(glew_err!=GLEW_OK){
        fprintf(stderr,"GLEW Error: %s\n",glewGetErrorString(glew_err));
    }

    // Do initialization for particular representation
    representation.initRep();
}


//----------------------------------------------------------------------
void GLHandlerIO::winDestroy(){
    //this makes sure we properly cleanup our OpenCL context
    if(glutWindowHandle)glutDestroyWindow(glutWindowHandle);
    printf("about to exit!\n");

    exit(0);
}


//----------------------------------------------------------------------
void GLHandlerIO::timerCB(int ms){
    //this makes sure the winRender function is called every ms miliseconds
    glutTimerFunc(ms, timerCB, ms);
    glutPostRedisplay();
}


//----------------------------------------------------------------------
void GLHandlerIO::winKeyboard(unsigned char key, int x, int y){
    //this way we can exit the program cleanly
    switch(key)
    {
        case '\033': // escape quits
        case '\015': // Enter quits    
        case 'Q':    // Q quits
        case 'q':    // q (or escape) quits
            // Cleanup up and quit
            winDestroy();
            break;
    }
}


//----------------------------------------------------------------------
void GLHandlerIO::winMouse(int button, int state, int x, int y){
    //handle mouse interaction for rotating/zooming the view
    if (state == GLUT_DOWN) {
        mouse_buttons |= 1<<button;
    } else if (state == GLUT_UP) {
        mouse_buttons = 0;
    }

    mouse_old_x = x;
    mouse_old_y = y;
}


//----------------------------------------------------------------------
void GLHandlerIO::winMotion(int x, int y){
    //hanlde the mouse motion for zooming and rotating the view
    float dx, dy;
    dx = x - mouse_old_x;
    dy = y - mouse_old_y;

    if (mouse_buttons & 1) {
        rotate_x += dy * 0.2;
        rotate_y += dx * 0.2;
    } else if (mouse_buttons & 4) {
        translate_z += dy * 0.1;
    }

    mouse_old_x = x;
    mouse_old_y = y;

    // set view matrix
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, translate_z);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
}

//----------------------------------------------------------------------
void GLHandlerIO::switchDefaultRepresentation(RepresentationGL rep){
    representation = rep;    
}


//----------------------------------------------------------------------
GLuint GLHandlerIO::createVBO(const void* data, int dataSize, GLenum target, GLenum usage){
    GLuint id = 0;  // 0 is reserved, glGenBuffersARB() will return non-zero id if success

    glGenBuffers(1, &id);                        // create a vbo
    glBindBuffer(target, id);                    // activate vbo id to use
    glBufferData(target, dataSize, data, usage); // upload data to video card

    // check data size in VBO is same as input array, if not return 0 and delete VBO
    int bufferSize = 0;
    glGetBufferParameteriv(target, GL_BUFFER_SIZE, &bufferSize);
    if(dataSize != bufferSize)
    {
        glDeleteBuffers(1, &id);
        id = 0;
        //cout << "[createVBO()] Data size is mismatch with input array\n";
        printf("[createVBO()] Data size is mismatch with input array\n");
    }
    //this was important for working inside blender!
    glBindBuffer(target, 0);
    return id;      // return VBO id
}
