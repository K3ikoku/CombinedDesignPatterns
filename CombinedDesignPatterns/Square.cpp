#include "Square.h"
#include "DrawableHandler.h"



Square::Square(int& color, int& size)
{
    m_shape.setPointCount(4);
    switch (size)
    {
    case DrawableHandler::Size::xSmall:
        m_size = 25;
        break;
    case DrawableHandler::Size::Small:
        m_size = 50;
        break;
    case DrawableHandler::Size::Medium:
        m_size = 75;
        break;
    case DrawableHandler::Size::Large:
        m_size = 100;
        break;
    case DrawableHandler::Size::xLarge:
        m_size = 125;
        break;
    case DrawableHandler::Size::xxLarge:
        m_size = 150;
        break;
    default:
        break;
    }

    m_shape.setRadius(m_size);
    
    SetColor(color);
}


Square::~Square()
{
}

void Square::SetPosition(sf::Vector2f position)
{
    m_position = position;
}

void Square::SetColor(int & color)
{
    ShapeBase::SetColor(color);
    m_shape.setFillColor(m_color);
}

void Square::Draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
}

void Square::Scale(float newScale)
{
    m_shape.scale(newScale, newScale);
}
