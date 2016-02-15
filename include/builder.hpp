#ifndef SANDO_TESTING_H_INCLUDED
#define SANDO_TESTING_H_INCLUDED

#include "Game/Cgame.hpp"
#include "include/Window/CWindow.hpp"
#include <thread>

void builder(CGame* game, CWindow* win)
{
    game->World.build();
    game->adding = true;
    while(!win->exit){
        game->Reactor();
        std::this_thread::sleep_for( std::chrono::milliseconds(10) );
    }
}

#endif SANDO_TESTING_H_INCLUDED
