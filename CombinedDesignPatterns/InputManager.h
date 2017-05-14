#pragma once
#include "DrawableHandler.h"
#include "ShapeFactory.h"
class InputManager
{
public:
    InputManager(sf::RenderWindow& window);
    ~InputManager();

    void HandleInput();
    int& GetShape();
    int& GetColor();
    int& GetSize();

private:
    DrawableHandler* m_drawableHandler;
    ShapeFactory* m_shapeFactory;
    sf::RenderWindow& m_window;
    int m_shape;
    int m_lastShape;
    int m_color;
    int m_lastColor;
    int m_size;
    int m_maxSize;

    sf::Vector2f m_mouseInput;
};
