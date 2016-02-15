#ifndef CSHADOWS_HPP_INCLUDED
#define CSHADOWS_HPP_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "../Shader/CShader.hpp"

extern int Window_width;
extern int Window_height;

using namespace std;

class CShadows
{
 public:
     GLuint Framebuffer;
     GLuint depthTexture;

     CShader shader;
     SUniform uniform;

    glm::mat4 mvp;
    glm::mat4 depthViewMatrix;
    glm::mat4 Projection;
    ///
    CShader shd2d;
    CShadows();
    void map( int number_scrap , vector<GLuint> &scrap ,glm::vec4 sun);
};


#endif // CSHADOWS_HPP_INCLUDED
