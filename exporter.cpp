
#include "exporter.h"


void export_scene(char *filename){
    int width = glutGet(GLUT_SCREEN_WIDTH);
    int height = glutGet( GLUT_SCREEN_HEIGHT);
    FILE *png;
    GLubyte *OpenGLimage, *p;
    gdImagePtr image;
    unsigned int r, g, b;
    int i,j,rgb;

    png = fopen(filename, "wb");

    if (png == NULL) {
        printf("*** warning:  unable to write to %s\n",filename);
    }

    OpenGLimage = (GLubyte *) malloc(width * height * sizeof(GLubyte) * 3);
    if(OpenGLimage == NULL){
        printf("error allocating image:%s\n",filename);
        exit(1);
    }

    printf("Saving to: %s .\n",filename);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadBuffer( GL_FRONT);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, OpenGLimage);
    p = OpenGLimage;
    image = gdImageCreateTrueColor(width,height);

    for (i = height-1 ; i>=0; i--) {
        for(j=0;j<width;j++){
                r=*p++; g=*p++; b=*p++;
                rgb = (r<<16)|(g<<8)|b;
                //printf("the rgb color %d\n", rgb );
                gdImageSetPixel(image,j,i,rgb);
        }
    }

    gdImagePng(image,png);
    fclose(png);
    gdImageDestroy(image);

}
