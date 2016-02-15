#ifndef CCONTROLLABLECHARACTER_HPP_INCLUDED
#define CCONTROLLABLECHARACTER_HPP_INCLUDED

class CWorld;

#include "CCharacter.hpp"
#include "../World/CWorld.hpp"

using namespace std;

class CControllableCharacter : public CCharacter
{
   public:
    bool moving;
    CWorld* world;
    float speed;
    float foward_x;
    float foward_y;
    bool going_up;
    bool going_left;
    bool going_down;
    bool going_right;

    bool foward_right;
    bool foward_left;

    bool falling;

    CControllableCharacter();
    void proggress();
};

#endif // CCONTROLLABLECHARACTER_HPP_INCLUDED
