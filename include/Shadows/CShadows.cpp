//CShadows.cpp

#include"CShadows.hpp"

CShadows::CShadows()
{
    shader.addShaders("shader/shadows.vs" , "shader/shadows.fs");
    shader.set("shader/smod3",uniform);

    glGenFramebuffers(1,&Framebuffer);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER,Framebuffer);

    glGenTextures(1, &depthTexture);
    glBindTexture(GL_TEXTURE_2D, depthTexture);
    glTexImage2D(GL_TEXTURE_2D, 0,GL_DEPTH_COMPONENT32, 4096, 4096, 0,GL_DEPTH_COMPONENT, GL_FLOAT, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,GL_TEXTURE_2D,depthTexture,0);
    glDrawBuffer(GL_NONE);

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER,0);

    Projection = glm::ortho<float>(-1400,1400,-1400,1400,-1500,1500);
    //depthViewMatrix = glm::lookAt(glm::vec3(0.5f,2,32), glm::vec3(35,0,0), glm::vec3(0,0,1));

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        cout << "brak Framebuffersa" << endl;

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //glDrawBuffer(GL_FRONT_AND_BACK);
 }

 void CShadows::map( int number_scrap , vector<GLuint> &scrap ,glm::vec4 sun)
 {
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER,Framebuffer);
    static const GLenum fboBuffs[] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
    glViewport(0,0,4096,4096);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // czysci bufor koloru i glebi

    glUseProgram(shader.GetProgram()); // wybiera shader

    mvp = glm::mat4(1.0f) * Projection * glm::lookAt(glm::vec3(sun[0],sun[1],sun[2]), glm::vec3(0,0,0), glm::vec3(0,0,1));

    glUniformMatrix4fv( uniform.matrix , 1 , GL_FALSE , &mvp[0][0]); // ustawia macierz

    glBindTexture(GL_TEXTURE_2D , 0); // wybiera teksture

    for(int i = 0 ; i < number_scrap ; i += 3)
    {
        glBindBuffer(GL_ARRAY_BUFFER , scrap[i]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , scrap[i+1]); // wybiera bufor

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawElements(GL_TRIANGLES, scrap[i+2], GL_UNSIGNED_INT, 0); //rysuje geometrie
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0);
        glBindBuffer(GL_ARRAY_BUFFER , 0);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //glDrawBuffer(GL_FRONT_AND_BACK);
    glViewport(0,0,Window_width,Window_height);
 }
