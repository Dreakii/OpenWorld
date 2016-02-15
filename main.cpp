#define GLEW_STATIC
#include <GL/glew.h>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int Window_width = 800;
int Window_height = 600;

#include "include/Game/Cgame.hpp"
#include "include/Window/CWindow.hpp"
#include <thread>

#include "include/Builder/builder.hpp"
#include "include/Generator/CContinent.hpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <X11/Xlib.h>

using namespace std;
int main()
{
    XInitThreads();
    srand(time(NULL));
    CWindow win;
    win.glew();
    CGame game;

    thread a(builder, &game, &win);
    win.renderIntro(&game.adding);

    game.generate();

    win.gameTool(&game);
}
