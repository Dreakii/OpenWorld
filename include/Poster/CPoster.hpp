#ifndef CPOSTER_HPP_INCLUDED
#define CPOSTER_HPP_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../Shader/CShader.hpp"

class CPoster
{
 public:
    GLuint buf;
    GLuint buf1;
    float x;
    float y;
    float width;
    float height;
    CShader shader;
    SUniform uniform;
    GLuint texId;

    CPoster( float _x , float _y , float _width , float _height );
    void draw();
};



#endif // CPOSTER_HPP_INCLUDED
