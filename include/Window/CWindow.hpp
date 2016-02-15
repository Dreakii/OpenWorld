#ifndef CWINDOW_HPP_INCLUDED
#define CWINDOW_HPP_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>

#include <SFML/Window.hpp>


#include "../Game/Cgame.hpp"
#include "../FrameCounter/CFrameCounter.hpp"

extern int Window_width;
extern int Window_height;

class CWindow
{
 public:
    sf::Window window;
    sf::Event event;
    bool exit;

    CWindow();
    void glew();
    void pollEvent();
    void renderIntro(bool *done);
    void gameTool(CGame *game);
};


#endif // CWINDOW_HPP_INCLUDED
