#ifndef CGRAPHIC_HPP_INCLUDED
#define CGRAPHIC_HPP_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

//#include "CParameter.hpp"
#include "../BasicTypes.hpp"
#include "../Shader/CShader.hpp"
#include "../Texture/CTexture.hpp"
#include "../Texture/CTextureArray.hpp"
#include "../Shadows/CShadows.hpp"
//#include "CFont.hpp"
#include "../Poster/CPoster.hpp"
#include "../Rudder/CCamera.hpp"
#include "../Character.hpp"

class CGraphic
{
 public:
    Ccamera cam;
    vector<GLuint> scrap;
    vector<GLuint> figure;
    int number_scrap;
    int number_figure;

    GLuint vao;

    CShadows shadow;

    //GLuint Color;
    //GLuint matrix;

    glm::vec4 move;
    glm::vec4 sun;

    glm::mat4 mvp;
    glm::mat4 mvp_depth;
    glm::mat4 Projection;
    glm::mat4 rotate;

    SUniform uniform1;
    SUniform uniform2;

    CShader shader1;
    CShader shader2;
    //CShader shader3;
    CTextureArray tex;
    CTexture hero;

    GLuint map;

    vector<glm::vec3*> position;
    vector<float*> degree;

    ///
    GLuint samp1;
    GLuint samp2;
    GLuint depthtex;

    CPoster post;

    CGraphic();// : tex("tex1.bmp" , "tex2.bmp" , "tex3.bmp" , "tex4.bmp" , "tex5.bmp" , "tex6.bmp" );
    void render();
    void add(Cmodel* added , glm::vec3 pos = glm::vec3(0,0,0));
    void clear();
    void add_model(CCharacter *form);//Cmodel* added , glm::vec3* pos , float* angle);
};

#endif // CGRAPHIC_HPP_INCLUDED
