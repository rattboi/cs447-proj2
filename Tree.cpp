/*
 * Tree.cpp: A class for drawing a parametered tree.
 *
 */


#include "Tree.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Destructor
Tree::~Tree(void)
{
    if ( initialized )
    {
        glDeleteLists(display_list, 1);
        gluDeleteQuadric(qobj);
    }
}


// Initializer. Returns false if something went wrong, like not being able to
// load the texture.
bool
Tree::Initialize(void)
{
    qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);

    display_list = glGenLists(1);
    glNewList(display_list, GL_COMPILE);
        // draw base of tree
        glColor3f(0.54, 0.27, 0.07);
        gluCylinder(qobj, base/5, base/5, height/4, 10, 16);
        glTranslatef(0.0, 0.0, height/4);

        // draw green part of tree
        glColor3f(0.0, 1.0, 0.0);
        glutSolidCone(base,(3*height)/4,10,10);

    glEndList();

    // We only do all this stuff once, when the GL context is first set up.
    initialized = true;

    return true;
}


// Draw just calls the display list we set up earlier.
void
Tree::Draw(void)
{
    glPushMatrix();
    
    // Translate the tree to the point
    glTranslatef(posn[0], posn[1], posn[2]);


    glCallList(display_list);
    glPopMatrix();
}

