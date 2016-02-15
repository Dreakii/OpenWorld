//CRudder.cpp

#include"CRudder.hpp"

CRudder::CRudder(Ccamera* cam , CControllableCharacter* hero) : cam(cam) , hero(hero){}

void CRudder::Reaction()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        Button_A();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        Button_D();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        Button_W();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        Button_S();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        Button_Q();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        Button_E();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        Button_LSHIFT();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        Button_SPACE();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        Button_UP();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        Button_DOWN();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        Button_LEFT();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        Button_RIGHT();
}

void CRudder::Button_D() { cam->target_right(); }

void CRudder::Button_A(){ cam->target_left(); }

void CRudder::Button_W(){ cam->front(); }

void CRudder::Button_S(){ cam->back(); }

void CRudder::Button_Q(){ hero->foward_left = true; }

void CRudder::Button_E(){ hero->foward_right = true; }

void CRudder::Button_LSHIFT(){ cam->down(); }

void CRudder::Button_SPACE(){ cam->up();}

void CRudder::Button_UP() { hero->going_up = true; }

void CRudder::Button_DOWN() { hero->going_down = true; }

void CRudder::Button_LEFT() { hero->going_left = true; }

void CRudder::Button_RIGHT() { hero->going_right = true; }
