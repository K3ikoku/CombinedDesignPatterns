#include "ShapeFactory.h"



ShapeFactory::ShapeFactory(sf::RenderWindow& window) :
    m_window(window),
    m_drawableHandler(DrawableHandler::GetInstance()),
    m_newColor(nullptr)
{
}


ShapeFactory::~ShapeFactory()
{
}

void ShapeFactory::CreateShape(int color, int shape, int size, sf::Vector2i position)
{
    m_position = position;
    GetSize(size, shape);
    m_newColor = GetColor(color);
    m_newShape = GetShape(shape);
    
    m_drawableHandler->Add(m_newShape);
}

ShapeBase * ShapeFactory::GetShape(int& shape)
{
    ShapeBase* m_tempUnit;
    switch (shape)
    {
    case DrawableHandler::Shapes::Circle:
        return m_tempUnit = new Circle(m_window, *m_newColor, m_position.x, m_position.y, m_width, m_height);
        break;

    case DrawableHandler::Shapes::Rectangle:
        return m_tempUnit = new Rectangle(m_window, *m_newColor, m_position.x, m_position.y, m_width, m_height);
        break;

    case DrawableHandler::Shapes::Square:
        return m_tempUnit = new Square(m_window, *m_newColor, m_position.x, m_position.y, m_width, m_height);
        break;

    case DrawableHandler::Shapes::Triangle:
        return m_tempUnit = new Triangle(m_window, *m_newColor, m_position.x, m_position.y, m_width, m_height);
        break;

    case DrawableHandler::Shapes::Octogon:
        return m_tempUnit = new Octagon(m_window, *m_newColor, m_position.x, m_position.y, m_width, m_height);
        break;

    default:
        break;
    }
    return m_newShape;
}

sf::Color * ShapeFactory::GetColor(int& color)
{
    return m_newColor;
}

void ShapeFactory::GetSize(int& size, int& shape)
{
}
