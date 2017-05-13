#pragma once
#include "DrawableHandler.h"
class InputManager
{
public:
    InputManager(sf::RenderWindow window);
    ~InputManager();

    void HandleInput();

private:
    DrawableHandler* m_drawableHandler;
    sf::RenderWindow& m_window;
    int m_shape;
    int m_lastShape;
    int m_color;
    int m_lastColor;
    int m_size;
    int m_maxSize;

    sf::Vector2i m_mouseInput;
};
