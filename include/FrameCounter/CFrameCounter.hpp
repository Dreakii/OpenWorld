#ifndef CFRAMECOUNTER_HPP_INCLUDED
#define CFRAMECOUNTER_HPP_INCLUDED

#include <iostream>
#include <SFML/Window.hpp>

using namespace std;

class CFrameCounter
{
 public:
    sf::Clock fpscounter;
    sf::Time seconds;
    short frames;

    CFrameCounter();
    void count();
};
#endif //CFRAMECOUNTER_HPP_INCLUDED
