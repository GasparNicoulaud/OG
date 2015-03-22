#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include <cstdio>
#include <string>
#include <algorithm>

#include "objload.h"

float carrot;

GLuint obj_array[3];

void reshape(int w,int h)
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
   //glOrtho(-25,25,-2,2,0.1,100);
   glMatrixMode(GL_MODELVIEW);
}


void drawCar()
{
   glPushMatrix();
   glTranslatef(0,-5.00,-30);
   glColor3f(1.0,0.23,0.27);
   glScalef(0.1,0.1,0.1);
   glRotatef(carrot,0,1,0);
   glCallList(obj_array[0]);
   glCallList(obj_array[1]);
   glCallList(obj_array[2]);
   glPopMatrix();
   carrot=carrot+0.6;
   if(carrot>360)carrot=carrot-360;
}


void display(void)
{
glClearColor (0.0,0.0,0.0,1.0);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
drawCar();
glutSwapBuffers(); //swap the buffers
}


int main(int argc,char **argv)
{




glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(800,450);
glutInitWindowPosition(20,20);
glutCreateWindow("ObjLoader");
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutIdleFunc(display);
loadObj("/var/www/DEV/3dgen/objets/dchair_obj.obj",obj_array,0);//replace porsche.obj with radar.obj or any other .obj to display it
loadObj("/var/www/DEV/3dgen/objets/ladybird.obj",obj_array,1);//replace porsche.obj with radar.obj or any other .obj to display it
loadObj("/var/www/DEV/3dgen/objets/lelelelelel.obj",obj_array,2);//replace porsche.obj with radar.obj or any other .obj to display it
glutMainLoop();
return 0;
}
