/*
Tejus
Institution: JSSATE, Bangalore
Semester: 6
Year: 2011
www.objinopengl.blogspot.com
*/
//header


#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include <cstdio>
#include <string>
#include <algorithm>

//globals


GLuint car;
float carrot;


//other functions and main
//.obj loader code


void loadObj(char *fname){
printf("print_1");
   std::string strlel;

   GLfloat **vertice;
   FILE *fp;
   int read;
   GLfloat x, y, z;
   int v1,v2,v3,balec1,balec2,balec3;
   char ch;
   car=glGenLists(1);

    int i =0;
   int nbvertex = 0;

   fp=fopen(fname,"r");
   if (!fp) {
        printf("can't open file %s\n", fname);
        exit(1);
    }

   glPointSize(2.0);
   glNewList(car, GL_COMPILE);

    while(!(feof(fp))) {
        read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
        if(read==4&&ch=='v') {
                nbvertex++;
        }
   }

   glEndList();
   fclose(fp);

    vertice = new GLfloat* [ nbvertex ];//[3];
    for(int i = 0; i< nbvertex; i++)
    {
        vertice[i] = new GLfloat[3];
    }

   fp=fopen(fname,"r");

   glPointSize(2.0);
   glNewList(car, GL_COMPILE);


    while(!(feof(fp))) {
        read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
        if(read==4&&ch=='v' && i >nbvertex) {
                vertice[i][0] = x;
                vertice[i][1] = y;
                vertice[i][2] = z;
                i++;
        }
   }

   glEndList();
   fclose(fp);

   ////////////aaaaaaficchaaaaaaaaaaaage   trianglex


   fp=fopen(fname,"r");

   glPointSize(2.0);
   glNewList(car, GL_COMPILE);


    //glPushMatrix();
    glBegin(GL_TRIANGLES);
    while(!(feof(fp))) {
        char cline[500];

        fgets (cline , 124 , fp);
        strlel = cline;
        int espnum = std::count(strlel.begin(), strlel.end(), ' ');
        fseek (fp, strlel.size(), SEEK_CUR );
        read=fscanf(fp,"%c %i %i %i %i %i %i",&ch,&v1,&balec1,&v2,&balec2,&v3,&balec3);
        if(read==7&&ch=='f' && espnum == 3) {
                glVertex3f(vertice[v1][0],vertice[v1][1],vertice[v1][2]);
                glVertex3f(vertice[v2][0],vertice[v2][1],vertice[v2][2]);
                glVertex3f(vertice[v3][0],vertice[v3][1],vertice[v3][2]);
        }
   }

   glEnd();

   //glPopMatrix();
   glEndList();
   fclose(fp);

   /*///////////aaaaaaficchaaaaaaaaaaaage   quadtrilatere

    fp=fopen(fname,"r");
   if (!fp) {
        printf("can't open file %s\n", fname);
        exit(1);
    }

   glPointSize(2.0);
   glNewList(car, GL_COMPILE);


    //glPushMatrix();
    glBegin(GL_QUADS);
    while(!(feof(fp))) {
        fgets (strlel , 124 , fp);
        int espnum = std::count(strlel.begin(), strlel.end(), ' ');
        fseek (fp, strlel.size(), SEEK_CUR );
        //read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
        if(read==4&&ch=='f'&& espnum==4) {
                vertice[i][0] = x;
                vertice[i][1] = y;
                vertice[i][2] = z;
        }
   }

   glEnd();

   //glPopMatrix();
   glEndList();
   fclose(fp);
   */
}
////////////////////////////////////////////////////////////////////////////////////:

//.obj loader code ends here
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
   glTranslatef(0,-0.00,-15);
   glColor3f(1.0,0.23,0.27);
   glScalef(0.1,0.1,0.1);
   glRotatef(carrot,0,1,0);
   glCallList(car);
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
printf("ok");
/*glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(800,450);
glutInitWindowPosition(20,20);
glutCreateWindow("ObjLoader");
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutIdleFunc(display);
loadObj("objets/dchair_obj.obj");//replace porsche.obj with radar.obj or any other .obj to display it
glutMainLoop();*/
return 0;
}
