#pragma once
#include "DrawableHandler.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Octagon.h"

class ShapeFactory
    {
public:
    ShapeFactory(sf::RenderWindow& window);
    ~ShapeFactory();

    void CreateShape(int color, int shape, int size, sf::Vector2i position);

private:
    sf::RenderWindow& m_window;
    DrawableHandler* m_drawableHandler;
    ShapeBase* m_newShape;
    sf::Color* m_newColor;
    sf::Vector2i m_position;
    int m_height;
    int m_width;

    ShapeBase* GetShape(int& shape);
    sf::Color* GetColor(int& color);
    void GetSize(int& size, int& shape);
};

