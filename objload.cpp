#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
//other functions and main
//.obj loader code

#include "objload.h"


void loadObj(char *fname, GLuint* obj_nb,int id){
        printf("loadObj go\n");

        GLfloat x, y, z;
        GLfloat **vertice;

        FILE *fp;

        int read;
        int v1,v2,v3,v4,balec1,balec2,balec3,balec4;
        char ch;

        int i =0;
        int nbvertex = 0;

        obj_nb[id]=glGenLists(1);

        fp=fopen(fname,"r");

        if(fp != NULL){printf("reading %s\n\n",fname);}
        else{printf("fp est null\n\n");}


        while(!(feof(fp))) {

                read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
                //printf("%c\n",&ch);
                if(read==4&&ch=='v') {
                        nbvertex++;
                }

        }

       // fclose(fp);

        vertice = new GLfloat* [ nbvertex ];//[3];

        for(int j = 0; j< nbvertex; j++) {
                vertice[j] = new GLfloat[3];
                //printf("nb vertex = %i\nOK : %i\n",nbvertex,j);
        }

       fseek(fp,0,SEEK_SET);

        while(!(feof(fp))) {
        //printf("\nscanff2\n");
                read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
                if(read==4&&ch=='v' && i < nbvertex) {
                            vertice[i][0] = x;
                            vertice[i][1] = y;
                            vertice[i][2] = z;
                            i++;
                }
        }

        fseek(fp,0,SEEK_SET);
        glNewList(obj_nb[id], GL_COMPILE);
        glBegin(GL_TRIANGLES);

        while(!(feof(fp))) {

            read=fscanf(fp,"%c %i/%i %i/%i %i/%i",&ch,&v1,&balec1,&v2,&balec2,&v3,&balec3);

            if(read==7&&ch=='f') {
                    glVertex3f(vertice[v1-1][0],vertice[v1-1][1],vertice[v1-1][2]);
                    glVertex3f(vertice[v2-1][0],vertice[v2-1][1],vertice[v2-1][2]);
                    glVertex3f(vertice[v3-1][0],vertice[v3-1][1],vertice[v3-1][2]);
                    //printf("tri\n");
            }
        }

        glEnd();

        fseek(fp,0,SEEK_SET);


        printf("print_loadobj_fin");

   ////////////aaaaaaficchaaaaaaaaaaaage   quadtrilatere
        glBegin(GL_QUADS);
        while(!(feof(fp))) {

            read=fscanf(fp,"%c %i/%i %i/%i %i/%i %i/%i",&ch,&v1,&balec1,&v2,&balec2,&v3,&balec3,&v4,&balec4);
            if(read==9&&ch=='f'){
                    glVertex3f(vertice[v1-1][0],vertice[v1-1][1],vertice[v1-1][2]);
                    glVertex3f(vertice[v2-1][0],vertice[v2-1][1],vertice[v2-1][2]);
                    glVertex3f(vertice[v3-1][0],vertice[v3-1][1],vertice[v3-1][2]);
                    glVertex3f(vertice[v4-1][0],vertice[v4-1][1],vertice[v4-1][2]);
                    //printf("quad\n");
            }
        }

        glEnd();

        glEndList();
        fclose(fp);
}
////////////////////////////////////////////////////////////////////////////////////:

//.obj loader code ends here
