#ifndef CRUDDER_HPP_INCLUDED
#define CRUDDER_HPP_INCLUDED

#include <SFML/Window.hpp>

#include "CCamera.hpp"
#include "../Character.hpp"

class CRudder
{
 private:
    Ccamera* cam;
    CControllableCharacter* hero;

 public:
    CRudder(Ccamera* cam , CControllableCharacter* hero);
    void Reaction();

    void Button_D();
    void Button_A();
    void Button_W();
    void Button_S();
    void Button_Q();
    void Button_E();
    void Button_LSHIFT();
    void Button_SPACE();
    void Button_UP();
    void Button_DOWN();
    void Button_LEFT();
    void Button_RIGHT();
};

#endif // CRUDDER_HPP_INCLUDED
