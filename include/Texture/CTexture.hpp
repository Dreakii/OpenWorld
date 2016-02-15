#ifndef CTEXTURE_HPP_INCLUDED
#define CTEXTURE_HPP_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <fstream>
//#include <windows.h>

#include <SFML/Graphics.hpp>

using namespace std;

class CTexture
{
   public:
    GLuint texId;
    int width;
    int height;
    int size;

    CTexture(void);
    unsigned char *downloadBMP( char* namefile);
    CTexture(char* filename);
    CTexture(char* filename, char* filename2 , char* filename3, char* filename4 , char* filename5 , char* filename6 );
};

#endif // CTEXTURE_HPP_INCLUDED
