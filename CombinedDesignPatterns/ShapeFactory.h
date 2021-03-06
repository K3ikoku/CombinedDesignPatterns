#pragma once
#include "DrawableHandler.h"

class ShapeFactory
    {
public:
    ShapeFactory(sf::RenderWindow& window);
    ~ShapeFactory();

    void CreateNewShape(int& color, int& shape, int& size, sf::Vector2f position);

private:
    sf::RenderWindow& m_window;
    DrawableHandler* m_drawableHandler;
    ShapeBase* m_newShape;

    ShapeBase* GetShape(int& shape, int& size, int& color, sf::Vector2f position);
};

