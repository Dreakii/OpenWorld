#ifndef CSHADER_HPP_INCLUDED
#define CSHADER_HPP_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <fstream>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

struct SUniform
{
    GLuint Color;
    GLuint Shad;
    GLuint matrix;
    GLuint move;
    GLuint rotate;
    GLuint sun;
    GLuint matrix_depth;
    GLuint flow;
};

class CShader
{
   public:
    GLuint Program;
    GLint testVal;
    GLuint Vshader;
    GLuint Fshader;

    CShader();

    void addShaders(string vShader , string fShader);
    string DownloadFile(string ShaderFile);
    GLuint GetProgram();
    void set(string filename , SUniform& uni);
};


#endif // CSHADER_HPP_INCLUDED
