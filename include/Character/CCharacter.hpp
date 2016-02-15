#ifndef CCHARACTER_HPP_INCLUDED
#define CCHARACTER_HPP_INCLUDED

#include<cmath>
#include<string>
//#include"../Graphics.hpp"
//#include"../World/CWorld.hpp"
#include "../BasicTypes.hpp"
#include "../Model/CModel.hpp"

class CCharacter
{
   public:
    glm::vec3 pos;
    Cmodel model;
    float angle;

    CCharacter();
    void download( string filename);
    CCharacter GetBasic();
    //void proggress();
};

#endif // CCHARACTER_HPP_INCLUDED
