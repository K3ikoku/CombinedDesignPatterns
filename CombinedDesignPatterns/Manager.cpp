#include "Manager.h"



Manager::Manager():
    m_window(sf::VideoMode(640, 960), "Shape Drawer"),
    m_drawableHandler(DrawableHandler::GetInstance())
{
}


Manager::~Manager()
{
}

void Manager::ProgramLoop()
{
    m_window.setFramerateLimit(60);


    while (m_window.isOpen())
    {
        //Create an event for closing the window
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }




    }
}

void Manager::Gui()
{
    
}

void Manager::Update()
{
}

void Manager::Draw()
{
    m_window.clear(sf::Color::White);
}
