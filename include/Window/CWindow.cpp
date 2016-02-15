//CWindow.cpp

#include"CWindow.hpp"

CWindow::CWindow() : window(sf::VideoMode(800, 600), "OpenWorld", sf::Style::Default, sf::ContextSettings(32))
{
    exit = false;
    window.setFramerateLimit(610);
}

void CWindow::glew()
{
    GLenum err = glewInit();
    if( GLEW_OK != err)
        fprintf(stderr , "blad: %s\n" , glewGetString(err));
}

void CWindow::pollEvent()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            exit = true;  // koniec programu
        }
        else if (event.type == sf::Event::Resized)
        {
            Window_width = event.size.width;
            Window_height = event.size.height;
            glViewport(0, 0, Window_width,Window_height ); // zmiana wielkosci okna
        }
    }
}

void CWindow::renderIntro(bool *done)
{
    static CPoster post(-1,1,2,2);
    post.texId = CTexture("texture/intro.bmp").texId;

    while(!*done and !exit)
    {
        post.draw();
        pollEvent();
        window.display();
    }
}

void CWindow::gameTool(CGame *game)
{
    static CFrameCounter counter;
    while(!exit)
    {
        pollEvent();
        game->GameTool(); //wywoluje tylko rendering, nie moze byc w osobnym watku!!!!!!!
        window.display();
        ///counter.count();
    }
}
