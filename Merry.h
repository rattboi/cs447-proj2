/*
 * Merry.h: Header file for a class that draws the ground.
 *
 * (c) 2001-2002: Stephen Chenney, University of Wisconsin at Madison.
 */


#ifndef _MERRY_H_
#define _MERRY_H_

#include <FL/gl.h>
#include <GL/glu.h>

class Merry{
  private:
    GLubyte     display_list[2];   // The display list that does all the work.
    float       posn[3];
    GLUquadric  *qobj[2];
    bool        initialized;    // Whether or not we have been initialised.
    double      baseAngle;
    double      tpAngle;

  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Merry(void) { for (int i = 0; i < 5; i++) display_list[i] = 0; initialized = false; posn[0] = posn[1] = posn[2] = 0.0f; };
    Merry(float x, float y, float z) { 
        for (int i = 0; i < 2; i++)
            display_list[i] = 0; 
        initialized = false; 
        posn[0] = x;
        posn[1] = y;
        posn[2] = z;
    };

    // Destructor. Frees the display lists and texture object.
    ~Merry(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);
    void    Update(float);      // Updates the location of the merry-go-round
};


#endif
