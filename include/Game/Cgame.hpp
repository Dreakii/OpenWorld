#ifndef CGAME_HPP_INCLUDED
#define CGAME_HPP_INCLUDED

#include "../World/CWorld.hpp"
#include "../Rudder/CRudder.hpp"
#include "../Graphic/CGraphic.hpp"

#include <iostream>
#include <mutex>

using namespace std;

class CGame
{
public:
    mutex m;
    CGraphic graphic; // obiekt grafiki
    CRudder Rudder; // obiekt sterowania
    CWorld World; // obiekt mechaniki fizyki
    CControllableCharacter hero; // glowny bohater
    CRemoteCharacterBase other_characters; // zdalni bohaterowie
    bool rendering;
    bool adding;

    CGame();
    void generate();
    void GameTool();
    void Reactor();
};

#endif // CGAME_HPP_INCLUDED
