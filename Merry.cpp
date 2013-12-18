/*
 * Merry.cpp: A class for drawing a Merry-go-round hierarchical animated model.
 *
 */

#include "Merry.h"
#include "libtarga.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

// Destructor
Merry::~Merry(void)
{
    if ( initialized )
    {
        glDeleteLists(display_list[0], 1);
        gluDeleteQuadric(qobj[0]);
        gluDeleteQuadric(qobj[1]);
    }
}

// Initializer. Returns false if something went wrong, like not being able to
// load the texture.
bool
Merry::Initialize(void)
{
    for (int i = 0; i < 2; i++)
    {
        qobj[i] = gluNewQuadric();
        gluQuadricNormals(qobj[i], GLU_SMOOTH);
    }

    display_list[0] = glGenLists(1);
    glNewList(display_list[0], GL_COMPILE);
        glColor3f(0.54, 0.27, 0.07);
        gluCylinder(qobj[0], 5, 5, 2, 10, 16);
        glTranslatef(0.0, 0.0, 2);
        gluDisk(qobj[1],2,5,10,10);
    glEndList();

    display_list[1] = glGenLists(1);
    glNewList(display_list[1], GL_COMPILE);
        glColor3f(0, 1, 0);
        glRotated(90,1,0,0);
        glutSolidTeapot(1.5f);
    glEndList();

    // We only do all this stuff once, when the GL context is first set up.
    initialized = true;

    return true;
}


// Draw just calls the display list we set up earlier.
void
Merry::Draw(void)
{
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    
    // Translate the merry-go-round to the point
    glTranslatef(posn[0], posn[1], posn[2]);

    glCallList(display_list[0]);

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(0,0,1);
        glTranslatef(3*cos(baseAngle+((3.14159f/2)*i)),3*sin(baseAngle+((3.14159f/2)*i)),0);
        glRotatef(tpAngle*30,0,0,1);
        glCallList(display_list[1]);
        glPopMatrix();
    }

    glPopMatrix();
    glEnable(GL_CULL_FACE);
}

void
Merry::Update(float angle)
{
    baseAngle += angle;
    tpAngle += angle*2.0f;
}
