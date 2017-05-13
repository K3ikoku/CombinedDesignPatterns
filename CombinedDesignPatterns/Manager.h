#pragma once
#include <SFML\Graphics.hpp>
#include "DrawableHandler.h"
#include "InputManager.h"

class Manager
{
public:
    Manager();
    ~Manager();

    void ProgramLoop();

private:
    sf::RenderWindow m_window;
    DrawableHandler* m_drawableHandler;

    void Gui();
    void Update();
    void Draw();
};

