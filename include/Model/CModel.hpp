#ifndef CMODEL_HPP_INCLUDED
#define CMODEL_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>

#include <GL/glew.h>
#include <GL/gl.h>

#include "../BasicTypes.hpp"
//#include "basic_graphic_types.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

struct Header // naglowek Cmodel
{
    int v_num;
    int vt_num;
    int f_num;

    void print();
};

class Cmodel // obiekt 3d
{
 public:
    Header head; // naglowek

    //set<glm::vec3> vecb; // tablica vectorow
    //set<UV> vtb; // tablica punktow tekstur
    list<glm::mat3x3> mesh; // tablica scian
    list<glm::mat3x3> UVpos; // tablica scian tekstur

    Cmodel(); // kreator pustego obiektu
    void SetFromFile(string filename);
    void SetFromFile( fstream &file, int pos = 0);
    Cmodel(const Cmodel& old);
    Cmodel& operator=(const Cmodel& rm); /// wymaga dodania zmiany wartosci wskaznikow
    ~Cmodel();
    void print(); // wypisuje stan modelu na konsole
    void add(Cmodel &added , const glm::vec3 = glm::vec3(0,0,0) );
    void remove( Cmodel &removed , const glm::vec3 &vec = glm::vec3(0,0,0) ); /// funkcja wymaga napisania od nowa
    GLfloat* GetVertexArray();
    GLfloat* GetUVArray();
    GLuint* GetIndexArray();
    GLuint* GetUVIndexArray();
    GLfloat* GetData( glm::vec3 vec);
    GLuint* GetIndexData();
    GLfloat* GetComplyUVArray();
    int GetIndex(mesh_prt<glm::vec3> X);
    GLfloat* GetNormal();
    void rotate(float z , glm::vec3 axis);
    void mirrorY();
    void mirrorZ();
};

#endif // CMODEL_HPP_INCLUDED
