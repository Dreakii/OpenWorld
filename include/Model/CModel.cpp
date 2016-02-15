//CModel.cpp

#include"CModel.hpp"

void Header::print()
{
    cout << "v_num  : " << v_num << endl;
    cout << "vt_num : " << vt_num << endl;
    cout << "f_num  : " << f_num << endl;
    cout << endl;
}
Cmodel::Cmodel() // kreator pustego obiektu
{
    head.v_num = 0;
    head.vt_num = 0;
    head.f_num = 0;
}

void Cmodel::SetFromFile(string filename)
{
    fstream file( filename , ios::in);
    SetFromFile(file);
}

void Cmodel::SetFromFile( fstream &file, int pos)
{
    file.seekg( pos , ios::beg ); // ustawia na czytanie danych
    file.read( (char*)&head , sizeof(Header) ); // czyta naglowek

    vector<glm::vec3> VecBuf; // bufor vectorow
    glm::vec3 Vtmp; // tymczasowy vector
    for(int i = 0 ; i < head.v_num ; i++) // przechodzi przez wszystki glm::vec3 w pliku
    {
        file.read( (char*)&Vtmp , sizeof(glm::vec3)); // laduje vector do tymczasowej zmiennej
        VecBuf.push_back(Vtmp);
    }

    vector<glm::vec3> UVBuf; // bufor UV
    glm::vec3 UVtmp;
    for(int i = 0 ; i < head.vt_num ; i++) // przechodzi przez wszystki UV w pliku
    {
        file.read( (char*)&UVtmp , sizeof(glm::vec3)); // laduje UV do tymczasowej zmiennej
        UVBuf.push_back(UVtmp);
    }
    vector<mesh_index> Vmesh(head.f_num); // vector indeksow meshow
    vector<mesh_index> UVmesh(head.f_num); // vector indeksow UV

    file.read( (char*)&Vmesh.front() , sizeof(mesh_index) * head.f_num ); // laduje meshe indeksow
    file.read( (char*)&UVmesh.front() , sizeof(mesh_index) * head.f_num ); // laduje indeksy UV

    for(int i = 0 ; i < head.f_num ; i++) // przechodzi przez wszystkie zaladowane meshow indeksow
    {
        mesh.push_back(glm::mat3x3( VecBuf[Vmesh[i].a] , VecBuf[Vmesh[i].b] , VecBuf[Vmesh[i].c] ));
    }

    for(int i = 0 ; i < head.f_num ; i++)
    {
        UVpos.push_back(glm::mat3x3( UVBuf[UVmesh[i].a] , UVBuf[UVmesh[i].b] , UVBuf[UVmesh[i].c] ));
    }
}
Cmodel::Cmodel(const Cmodel& old)
{
    head = old.head;

    mesh = old.mesh;
    UVpos = old.UVpos;
}
Cmodel& Cmodel::operator=(const Cmodel& rm)
{
    head = rm.head;

    mesh = rm.mesh;
    UVpos = rm.UVpos;

    return *this;
}
Cmodel::~Cmodel()
{
    mesh.clear();
    UVpos.clear();
}

void Cmodel::print() // wypisuje stan modelu na konsole
{
    //head.print();
    int i = 0;
    head.print();
    for(glm::mat3x3& X : mesh)
    {
        cout << X[0][0]<< " " << X[0][1] << " " << X[0][2] << endl;
        cout << X[1][0]<< " " << X[1][1] << " " << X[1][2] << endl;
        cout << X[2][0]<< " " << X[2][1] << " " << X[2][2] << endl;
    }
    for(glm::mat3x3& X : UVpos)
    {
        cout << X[0][0]<< " " << X[0][1] << " " << X[0][2] << endl;
        cout << X[1][0]<< " " << X[1][1] << " " << X[1][2] << endl;
        cout << X[2][0]<< " " << X[2][1] << " " << X[2][2] << endl;
    }
}
void Cmodel::add(Cmodel &added , const glm::vec3 vec)
{
    for(glm::mat3x3& X : added.mesh)
    {
        mesh.push_back(glm::mat3x3(X[0]+vec,X[1]+vec,X[2]+vec));
        //mesh.push_back(glm::mat3x3(glm::translate(glm::mat4x4(X),vec)));
    }
    for(glm::mat3x3& X : added.UVpos)
    {
        UVpos.push_back(X);
    }
}
/*void Cmodel::remove( Cmodel &removed , const glm::vec3 &vec ) /// funkcja wymaga napisania od nowa!
{
    for(mesh_prt<glm::vec3> &X : removed.fb)
    {
        list<mesh_prt<UV>>::iterator Z = tb.begin();
        for(list<mesh_prt<glm::vec3>>::iterator Y = fb.begin() ; Y != fb.end() ; Y++ , Z++ )
        {
            if( (X.move(vec)) == ( (*Y).move(glm::vec3(0,0,0))) )
            {
                fb.erase(Y);
                tb.erase(Z);
                Y = fb.begin();
                Z = tb.begin();
            }
        }
    }

    head.v_num = vecb.size();
    head.vt_num = vtb.size();
    head.f_num = fb.size();
}*/

/*GLfloat* Cmodel::GetVertexArray()
{
    static vector<GLfloat> array;
    array.clear();
    array.reserve(head.v_num * 3);
    for(Cvector X : vecb)
    {
        array.push_back(X.x);
        array.push_back(X.y);
        array.push_back(X.z);
    }
    return &array.front();
}*/

/*GLfloat* Cmodel::GetUVArray()
{
    static vector<GLfloat> array;
    array.clear();
    array.reserve(head.vt_num * 2);
    for(UV X : vtb)
    {
        array.push_back(X.u);
        array.push_back(X.v);
    }
    return &array.front();
}*/

/*GLuint* Cmodel::GetIndexArray()
{
    static vector<GLuint> array;
    array.clear();
    array.reserve(head.f_num * 3);

    int i;
    for( list<mesh_prt<Cvector>>::iterator X = fb.begin() ; X != fb.end() ; X++)//for(mesh_prt<Cvector> X : fb)
    {
        i = 0;
        for(Cvector Y : vecb)
        {
            if( (*((*X).a)) == Y)
                break;
            i++;
        }
        array.push_back(i);

        i = 0;
        for(Cvector Y : vecb)
        {
            if( (*((*X).b)) == Y)
                break;
            i++;
        }
        array.push_back(i);

        i = 0;
        for(Cvector Y : vecb)
        {
            if( (*((*X).c)) == Y)
                break;
            i++;
        }
        array.push_back(i);
    }
    return &array.front();
}*/

/*GLuint* Cmodel::GetUVIndexArray()
{
    static vector<GLuint> array;
    array.clear();
    array.reserve(head.f_num * 3);

    int i;
    for( list<mesh_prt<UV>>::iterator X = tb.begin() ; X != tb.end() ; X++)//for(mesh_prt<Cvector> X : fb)
    {
        i = 0;
        for(UV Y : vtb)
        {
            if( (*((*X).a)) == Y)
                break;
            i++;
        }
        array.push_back(i);

        i = 0;
        for(UV Y : vtb)
        {
            if( (*((*X).b)) == Y)
                break;
            i++;
        }
        array.push_back(i);

        i = 0;
        for(UV Y : vtb)
        {
            if( (*((*X).c)) == Y)
                break;
            i++;
        }
        array.push_back(i);
    }
    return &array.front();
}*/

GLfloat* Cmodel::GetData( glm::vec3 vec)
{
    static vector<GLfloat> array;
    array.clear();
    array.reserve(mesh.size() * 18);

    // vec( (pos%16)*16 , ((pos/16)%16)*16 , ((pos/256)%16)*16 );

    for(glm::mat3x3& X : mesh)
    {
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                array.push_back(X[i][j] + vec[j]);
    }

    for(glm::mat3x3& X : UVpos)
    {
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                array.push_back(X[i][j]);
    }

    glm::vec3 vec1;
    glm::vec3 vec2;
    glm::vec3 vec3;

    for( glm::mat3x3 &X : mesh)
    {
        vec1[0] = X[1][0] - X[0][0];
        vec1[1] = X[1][1] - X[0][1];
        vec1[2] = X[1][2] - X[0][2];

        vec2[0] = X[2][0] - X[0][0];
        vec2[1] = X[2][1] - X[0][1];
        vec2[2] = X[2][2] - X[0][2];

        vec3 = glm::normalize(glm::cross(glm::normalize(vec2) , glm::normalize(vec1)));
        for(int i = 0 ; i < 3 ; i++)
        {
            array.push_back(vec3[0]);
            array.push_back(vec3[1]);
            array.push_back(vec3[2]);
        }
    }
    return &array.front();
}

GLuint* Cmodel::GetIndexData()
{
    static vector<GLuint> array;
    array.clear();
    array.reserve(mesh.size()*3);
    int end = mesh.size() *3;
    for(int i = 0 ; i < end ; i++)
        array.push_back(i);
    return &array.front();
}

void Cmodel::rotate(float z , glm::vec3 axis)
{
    glm::mat4 matrix = glm::rotate(glm::mat4(1.0f), z , glm::vec3(axis.x, axis.y, axis.z));
    glm::vec4 tmp;
    for(glm::mat3x3& X : mesh)
    {
        tmp = glm::vec4(X[0],0);
        tmp = tmp * matrix;
        X[0] = glm::vec3(tmp);
        tmp = glm::vec4(X[1],0);
        tmp = tmp * matrix;
        X[1] = glm::vec3(tmp);
        tmp = glm::vec4(X[2],0);
        tmp = tmp * matrix;
        X[2] = glm::vec3(tmp);
    }
}

void Cmodel::mirrorY()
{
    for(glm::mat3x3& X : mesh)
    {
        for(int i = 0 ; i < 3 ; i++)
            X[i][1] *= -1;
    }
}
