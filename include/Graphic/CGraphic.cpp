//CGraphic.cpp

#include "CGraphic.hpp"

CGraphic::CGraphic() : tex("texture/tex1.bmp", 7) , hero("texture/hero.bmp") , post(0,0,1,1)
{
    tex.add("texture/tex2.bmp");
    tex.add("texture/tex3.bmp");
    tex.add("texture/tex4.bmp");
    tex.add("texture/tex5.bmp");
    tex.add("texture/tex6.bmp");
    tex.add("texture/tex6.bmp");
    number_scrap = 0;
    number_figure = 0;
    int a;
    glEnable(GL_DEPTH_TEST);
    shader1.addShaders("shader/3d.vs" , "shader/3da.fs");
    shader2.addShaders("shader/3dmove.vs" , "shader/3dmove.fs");
    shader1.set("shader/smod1",uniform1);
    shader2.set("shader/smod2",uniform2);
    Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 1000.0f);

    sun[0] = 1;
    sun[1] = 1;
    sun[2] = 1;
    sun[3] = 1;
}
void CGraphic::render()
{
    static float flow(0);
    if(flow < 1)
        flow += 0.05;
    else
        flow = 0;
    static float angle(0);
    angle +=0.1;
    sun = glm::vec4(1,1,1,1) * glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
    shadow.map(number_scrap,scrap,sun);
    depthtex = shadow.depthTexture;

    cam.set(); // pobiera koordynaty kamery
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // czysci bufor koloru i glebi*/
    glUseProgram(shader1.GetProgram()); // wybiera shader

    glUniform1i(uniform1.Color, 0);
    glUniform1i(uniform1.Shad, 1);

    mvp = glm::mat4(1.f); // macierz modelowania
    mvp = mvp * Projection * cam.GetView(); // obliczanie macierzy modelowania
    mvp_depth = glm::mat4(1.0f) * glm::ortho<float>(-1400,1400,-1400,1400,-1500,1500) * glm::lookAt(glm::vec3(sun[0],sun[1],sun[2]), glm::vec3(0,0,0), glm::vec3(0,0,1));
    //mvp = mvp_depth;
    //glUniform4fv( uniform1.Color , 1 , vac); // ustawia dane uniform
    glUniformMatrix4fv( uniform1.matrix , 1 , GL_FALSE , &mvp[0][0]); // ustawia macierz
    glUniformMatrix4fv( uniform1.matrix_depth , 1 , GL_FALSE , &mvp_depth[0][0]);
    glUniform4fv( uniform1.sun , 1 , &sun[0] );
    glUniform1f( uniform1.flow , flow);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY , tex.texId); // wybiera teksture
    //glBindSampler(0, samp1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D , depthtex); // wybiera teksture
    //glBindSampler(1, samp1);

    for(int i = 0 ; i < number_scrap ; i += 3)
    {
        glBindBuffer(GL_ARRAY_BUFFER , scrap[i]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , scrap[i+1]); // wybiera bufor

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)( scrap[i+2] * sizeof(GLfloat) * 3 ));
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)( scrap[i+2] * sizeof(GLfloat) * 6 ));

        glDrawElements(GL_TRIANGLES, scrap[i+2], GL_UNSIGNED_INT, 0); //rysuje geometrie
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0);
        glBindBuffer(GL_ARRAY_BUFFER , 0);
    }

    glUseProgram(shader2.GetProgram()); // wybiera shader

    //glUniform4fv( uniform2.Color , 1 , vac); // ustawia dane uniform

    //glUniformMatrix4fv( uniform2.matrix , 1 , GL_FALSE , &mvp[0][0]); // ustawia macierz
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY , hero.texId); // wybiera teksture

    for(int i = 0 ; i < number_figure ; i += 3)
    {
        //mvp = glm::rotate(mvp , *degree[(number_figure/3)-1] , glm::vec3(0,0,-1));

        glm::vec3 vec = *position[(i/3)];
        move = glm::vec4(vec.x,vec.y,vec.z,0);

        rotate = glm::rotate(glm::mat4(1.0f), *degree[(i/3)], glm::vec3(0.0f, 0.0f, 1.0f));

        glUniformMatrix4fv( uniform2.matrix , 1 , GL_FALSE , &mvp[0][0]); // ustawia macierz
        glUniformMatrix4fv( uniform2.rotate , 1 , GL_FALSE , &rotate[0][0] );
        glUniform4fv( uniform2.move , 1 , &move[0]); // ustawia macierz
        glUniform4fv( uniform2.sun , 1, &sun[0] );

        glBindBuffer(GL_ARRAY_BUFFER , figure[i]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , figure[i+1]); // wybiera bufor

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)( figure[i+2] * sizeof(GLfloat) * 3 ));
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)( figure[i+2] * sizeof(GLfloat) * 6 ));

        glDrawElements(GL_TRIANGLES, figure[i+2], GL_UNSIGNED_INT, 0); //rysuje geometrie
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0);
        glBindBuffer(GL_ARRAY_BUFFER , 0);
    }
}

void CGraphic::add(Cmodel* added , glm::vec3 pos)
{
    if(added->mesh.size() != 0)
    {
        GLuint buffer[2];
        glGenBuffers(2,buffer);
        scrap.push_back(buffer[0]);
        scrap.push_back(buffer[1]);

        glBindBuffer(GL_ARRAY_BUFFER , scrap[number_scrap++]);
        glBufferData(GL_ARRAY_BUFFER , ( added->mesh.size() * sizeof(GLfloat) * 27 ) , added->GetData( pos ) , GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , scrap[number_scrap++]);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER , added->UVpos.size() * sizeof(GLuint) * 3 , added->GetIndexData(), GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER ,0);
        glBindBuffer(GL_ARRAY_BUFFER ,0);

        scrap.push_back(added->mesh.size()*3);
        number_scrap++;
    }
}

void CGraphic::clear()
{
    for(int i = 0 ; i < number_scrap ; i += 3)
    {
        glBindBuffer(GL_ARRAY_BUFFER , scrap[i]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , scrap[i+1]); // wybiera bufor

        GLuint tab[2] = {scrap[i],scrap[i+1]};
        glDeleteBuffers(2,tab);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , 0);
        glBindBuffer(GL_ARRAY_BUFFER , 0);
    }
    scrap.clear();
    number_scrap = 0;
}

void CGraphic::add_model(CCharacter* form)//Cmodel* added , glm::vec3* pos , float* angle)
{
    if(form->model.mesh.size() != 0)
    {
        position.push_back(&form->pos);
        degree.push_back(&form->angle);
        GLuint buffer[2];
        glGenBuffers(2,buffer);
        figure.push_back(buffer[0]);
        figure.push_back(buffer[1]);
        //figure.push_back(buffer[2]);

        glBindBuffer(GL_ARRAY_BUFFER , figure[number_figure++]);
        glBufferData(GL_ARRAY_BUFFER , ( form->model.mesh.size() * sizeof(GLfloat) * 24 ) , form->model.GetData( glm::vec3(0,0,0) ) , GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER ,0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , figure[number_figure++]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , form->model.mesh.size() * sizeof(GLuint) * 3 , form->model.GetIndexData(), GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER ,0);

        glBindBuffer(GL_ARRAY_BUFFER ,0);

        figure.push_back(form->model.mesh.size()*3);
        number_figure++;
    }
}
