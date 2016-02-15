// CPoster.cpp

#include"CPoster.hpp"

CPoster::CPoster( float _x , float _y , float _width , float _height ) : x(_x) ,  y(_y) ,  width(_width) ,  height(_height)
{
    shader.addShaders("shader/2d.vs" , "shader/2d.fs");
    shader.set("shader/smod1",uniform);
    glGenBuffers(1, &buf);
    glBindBuffer(GL_ARRAY_BUFFER, buf);
    glGenBuffers(1, &buf1);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf1);

    glEnableVertexAttribArray(0);

    GLfloat box[4][4] =
    {
        { x + width , y - height , 1 , 0},
        { x + width , y          , 1 , 1},
        { x         , y - height , 0 , 0},
        { x         , y          , 0 , 1},
    };
    GLuint box1[6] = {0,1,2,1,2,3};

    glBindBuffer(GL_ARRAY_BUFFER, buf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , buf1); // wybiera bufor
    glBufferData(GL_ELEMENT_ARRAY_BUFFER , 6 * sizeof(GLuint) , box1, GL_STATIC_DRAW);
}

void CPoster::draw()
{
    glDisable(GL_DEPTH_TEST);
    glUseProgram(shader.GetProgram()); // wybiera shader
    //glUniform1i(uniform.Color, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D , texId);
    glBindBuffer(GL_ARRAY_BUFFER, buf);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf1);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //rysuje geometrie
    glEnable(GL_DEPTH_TEST);
}
