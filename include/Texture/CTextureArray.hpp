#ifndef CTEXTUREARRAY_HPP_INCLUDED
#define CTEXTUREARRAY_HPP_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <fstream>
//#include <windows.h>

#include <SFML/Graphics.hpp>

using namespace std;

class CTextureArray
{
   public:
    GLuint texId;
    int width;
    int height;
    int size;
    int counter;
    int deepth;

    CTextureArray(string filename, int deepth);
    unsigned char *downloadBMP( string namefile);
    void add(string filename);
    ///CTexture(char* filename, char* filename2 , char* filename3, char* filename4 , char* filename5 , char* filename6 );
};


#endif // CTEXTUREARRAY_HPP_INCLUDED
