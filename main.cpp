#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <gd.h>
#include <sys/types.h>
#include <dirent.h>

#include <glm.h>

#include "exporter.h"
#include "objload.h"

float carrot;

bool exported=false;

GLuint obj_array[10];

GLMmodel *model[10];
float rnd[10][3];

int nbmodel,nbfi;
char files[1000][256];


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
   glTranslatef(0,0,-10);
   glColor3f(1.0,0.23,0.27);
   glScalef(0.1,0.1,0.1);
   glRotatef(carrot,0,1,0);
   /*
   glCallList(obj_array[0]);
   glCallList(obj_array[1]);
   glCallList(obj_array[2]);
   */
   for(int i = 0; i<nbmodel;i++){
   glTranslatef(rnd[nbmodel][0],rnd[nbmodel][1],rnd[nbmodel][2]);
   glRotatef(1,rnd[nbmodel][0],rnd[nbmodel][1],rnd[nbmodel][2]);
        glmDraw(model[i],0);
        }
   glPopMatrix();
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
if(exported == false){ export_scene("/var/www/DEV/3dgen/OG/bin/Debug/lol.png"); exported = true;}
glutPostRedisplay();
}


int main(int argc,char **argv){
printf("ogbegin");
srand (time (NULL));
nbmodel = rand()%10;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(800,450);
glutInitWindowPosition(20,20);
glutCreateWindow("ObjLoader");
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutIdleFunc(display);

glEnable(GL_DEPTH_TEST);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
GLint poss[4] = {1.00,1.00,1.00,1.00};
glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,poss);
/*
loadObj("/var/www/DEV/3dgen/objets/dchair_obj.obj",obj_array,0);//replace porsche.obj with radar.obj or any other .obj to display it
loadObj("/var/www/DEV/3dgen/objets/ladybird.obj",obj_array,1);//replace porsche.obj with radar.obj or any other .obj to display it
loadObj("/var/www/DEV/3dgen/objets/lelelelelel.obj",obj_array,2);//replace porsche.obj with radar.obj or any other .obj to display it
*/
nbfi = 0;
DIR *dp;
  struct dirent *ep;

  dp = opendir ("/var/www/DEV/3dgen/OG/objets/glm-data");
  if (dp != NULL)
    {
      while (ep = readdir (dp))
      {
      if(strstr(ep->d_name,".obj")!=0)
      {
        sprintf(files[nbfi],"/var/www/DEV/3dgen/OG/objets/glm-data/%s",ep->d_name);
        printf("%s\n",files[nbfi],GLM_FLAT);

        nbfi++;
        }
        }
      (void) closedir (dp);
    }
  else
    perror ("Couldn't open the directory");

for(int i = 0; i<nbmodel;i++){

    rnd[i][0] = rand()%200;
    rnd[i][2] = rand()%200;
    rnd[i][3] = rand()%200;
    model[i] = glmReadOBJ(files[rand()%nbfi]);
    printf("model %i", i);
}

GLfloat pos[4] = {1.50,1.00,10.00,0.00};
glLightfv(GL_LIGHT0, GL_POSITION,pos);
glutMainLoop();
return 0;
}
