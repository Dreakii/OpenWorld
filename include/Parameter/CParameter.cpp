// CParameter.cpp

#include"CParameter.hpp"

CParameter::CParameter() : layer(1,1,1,1,1)
{
    conecting = false;
    for(int i = 0 ; i < 6 ; i++)
    {
        part[i] = Cmodel();
        con[i] = false;
        conAB[i] = false;
        conA[i] = false;
        conB[i] = false;
    }
}

CParameter::~CParameter(){}

CParameter& CParameter::operator=(const CParameter& rm)
{
     conecting = rm.conecting;

     for(int i = 0 ; i < 6 ; i++)
     {
         part[i] = rm.part[i];
         con[i] = rm.con[i]; //con.set(i , rm.con[i]);
         conAB[i] = rm.conAB[i]; //conAB.set(i , rm.conAB[i] );
         conA[i] = rm.conA[i]; //conA.set(i , rm.conA[i] );
         conB[i] = rm.conB[i]; //conB.set( i , rm.conB[i]);
     }

     return *this;
}

void CParameter::SetFromFile( string filename, int pos)
{
    fstream file( filename.c_str() , ios::in | ios::binary); //FILE *file; // zmienna pliku
    file.seekg( pos , ios::beg ); // ustawia na czytanie danych

    file.read( (char*)&conecting , sizeof(bool) );
    file.read( (char*)&con , sizeof(bool) * 6 );
    file.read( (char*)&conAB , sizeof(bool) * 6  );
    file.read( (char*)&conA , sizeof(bool) * 6  );
    file.read( (char*)&conB , sizeof(bool) * 6  );

    pos = file.tellg();

    for(int i = 0 ; i < 6 ; i++)
    {
        part[i].SetFromFile(file, file.tellg());
    }
}

void CParameter::DownloadFromFile( string filename , int id)
{
    fstream file( filename.c_str() , ios::in | ios::binary);
    int el_num;
    file.read((char*)&el_num , sizeof(int));

    int el_id;
    int el_size;
    for(int i = 0 ; i < el_num ; i++)
    {
        file.read((char*)&el_id , sizeof(int));
        file.read((char*)&el_size , sizeof(int));

        if(el_id == id)
        {
            SetFromFile( filename.c_str() , file.tellg() );
            break;
        }
        else
        {
            file.seekg( el_size , ios::cur);
        }
    }
}

void CParameter::RorateZ90(bool mod)
{
    CParameter tmp; // tymczasoy parametr

    tmp.conecting = conecting;

    tmp.part[0] = part[1]; tmp.con[0] = con[1]; tmp.conAB[0] = conAB[1]; tmp.conA[0] = conA[1]; tmp.conB[0] = conB[1];
    tmp.part[0].rotate(90,glm::vec3(0,0,1));
    tmp.part[1] = part[3]; tmp.con[1] = con[3]; tmp.conAB[1] = conAB[3]; tmp.conA[1] = conA[3]; tmp.conB[1] = conB[3];
    tmp.part[1].rotate(90,glm::vec3(0,0,1));
    tmp.part[2] = part[2]; tmp.con[2] = con[2]; tmp.conAB[2] = conAB[2]; tmp.conA[2] = conA[2]; tmp.conB[2] = conB[2];
    tmp.part[2].rotate(90,glm::vec3(0,0,1));
    tmp.part[3] = part[4]; tmp.con[3] = con[4]; tmp.conAB[3] = conAB[4]; tmp.conA[3] = conA[4]; tmp.conB[3] = conB[4];
    tmp.part[3].rotate(90,glm::vec3(0,0,1));
    tmp.part[4] = part[0]; tmp.con[4] = con[0]; tmp.conAB[4] = conAB[0]; tmp.conA[4] = conA[0]; tmp.conB[4] = conB[0];
    tmp.part[4].rotate(90,glm::vec3(0,0,1));
    tmp.part[5] = part[5]; tmp.con[5] = con[5]; tmp.conAB[5] = conAB[5]; tmp.conA[5] = conA[5]; tmp.conB[5] = conB[5];
    tmp.part[5].rotate(90,glm::vec3(0,0,1));

    conecting = tmp.conecting;

    for(int i = 0 ; i < 6 ; i++)
    {
        part[i] = tmp.part[i];
        con[i] = tmp.con[i]; //con.set(i , rm.con[i]);
        conAB[i] = tmp.conAB[i]; //conAB.set(i , rm.conAB[i] );
        conA[i] = tmp.conA[i]; //conA.set(i , rm.conA[i] );
        conB[i] = tmp.conB[i]; //conB.set( i , rm.conB[i]);
        if(mod)
            if(con[i] == true and conAB[i] == false)
            {
                bool tmp = conA[i];
                conA[i] = conB[i];
                conB[i] = tmp;
            }
    }
}

void CParameter::RorateZ180(bool mod)
{
    CParameter tmp; // tymczasoy parametr

    tmp.conecting = conecting;

    tmp.part[0] = part[3]; tmp.con[0] = con[3]; tmp.conAB[0] = conAB[3]; tmp.conA[0] = conA[3]; tmp.conB[0] = conB[3];
    tmp.part[0].rotate(180,glm::vec3(0,0,1));
    tmp.part[1] = part[4]; tmp.con[1] = con[4]; tmp.conAB[1] = conAB[4]; tmp.conA[1] = conA[4]; tmp.conB[1] = conB[4];
    tmp.part[1].rotate(180,glm::vec3(0,0,1));
    tmp.part[2] = part[2]; tmp.con[2] = con[2]; tmp.conAB[2] = conAB[2]; tmp.conA[2] = conA[2]; tmp.conB[2] = conB[2];
    tmp.part[2].rotate(180,glm::vec3(0,0,1));
    tmp.part[3] = part[0]; tmp.con[3] = con[0]; tmp.conAB[3] = conAB[0]; tmp.conA[3] = conA[0]; tmp.conB[3] = conB[0];
    tmp.part[3].rotate(180,glm::vec3(0,0,1));
    tmp.part[4] = part[1]; tmp.con[4] = con[1]; tmp.conAB[4] = conAB[1]; tmp.conA[4] = conA[1]; tmp.conB[4] = conB[1];
    tmp.part[4].rotate(180,glm::vec3(0,0,1));
    tmp.part[5] = part[5]; tmp.con[5] = con[5]; tmp.conAB[5] = conAB[5]; tmp.conA[5] = conA[5]; tmp.conB[5] = conB[5];
    tmp.part[5].rotate(180,glm::vec3(0,0,1));

    conecting = tmp.conecting;

    for(int i = 0 ; i < 6 ; i++)
    {
        part[i] = tmp.part[i];
        con[i] = tmp.con[i]; //con.set(i , rm.con[i]);
        conAB[i] = tmp.conAB[i]; //conAB.set(i , rm.conAB[i] );
        conA[i] = tmp.conA[i]; //conA.set(i , rm.conA[i] );
        conB[i] = tmp.conB[i]; //conB.set( i , rm.conB[i]);
        if(mod)
            if(con[i] == true and conAB[i] == false)
            {
                bool tmp = conA[i];
                conA[i] = conB[i];
                conB[i] = tmp;
            }
    }
}

void CParameter::RorateZ270(bool mod)
{
    RorateZ180();
    RorateZ90(mod);
}

bool CParameter::IsConecting() // sprawdza chcec laczenia sie obiektu
{
    return conecting;
}

void CParameter::print()
{
    cout << conecting << endl;
    cout << con[0] << con[1] << con[2] << con[3] << con[4] << con[5] << endl;
    cout << conAB[0] << conAB[1] << conAB[2] << conAB[3] << conAB[4] << conAB[5] << endl;
    cout << conA[0] << conA[1] << conA[2] << conA[3] << conA[4] << conA[5] << endl;
    cout << conB[0] << conB[1] << conB[2] << conB[3] << conB[4] << conB[5] << endl;

    for(int i = 0 ; i < 6 ; i++)
    {
        part[i].print();
    }
}
