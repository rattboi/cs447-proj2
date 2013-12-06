/*
 * Ground.h: Header file for a class that draws the ground.
 *
 * (c) 2001-2002: Stephen Chenney, University of Wisconsin at Madison.
 */


#ifndef _TREE_H_
#define _TREE_H_

#include <FL/gl.h>
#include <GL/glu.h>

class Tree {
  private:
    GLubyte     display_list;   // The display list that does all the work.
    GLdouble    height;
    GLdouble    base;
    float       posn[3];
    GLUquadric  *qobj;
    bool        initialized;    // Whether or not we have been initialised.

  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Tree(void) { display_list = 0; initialized = false; height = 10.0; base = 3.0; posn[0] = posn[1] = posn[2] = 0.0f; };
    Tree(GLdouble my_height, GLdouble my_base, float x, float y, float z) { 
        display_list = 0; initialized = false; 
        height = my_height; base = my_base;
        posn[0] = x;
        posn[1] = y;
        posn[2] = z;
    };

    // Destructor. Frees the display lists and texture object.
    ~Tree(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);
};


#endif
