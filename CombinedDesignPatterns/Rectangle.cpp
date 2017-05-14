#include "Rectangle.h"
#include "DrawableHandler.h"



Rectangle::Rectangle(int& color, int& size)
{
    switch (size)
    {
    case DrawableHandler::Size::xSmall:
        m_size = sf::Vector2f(25, 12.5f);
        break;
    case DrawableHandler::Size::Small:
        m_size = sf::Vector2f(50, 25);
        break;
    case DrawableHandler::Size::Medium:
        m_size = sf::Vector2f(75, 37.5f);
        break;
    case DrawableHandler::Size::Large:
        m_size = sf::Vector2f(100, 50);
        break;
    case DrawableHandler::Size::xLarge:
        m_size = sf::Vector2f(125, 62.5f);
        break;
    case DrawableHandler::Size::xxLarge:
        m_size = sf::Vector2f(150, 75);
        break;
    default:
        break;
    }

    m_shape.setSize(m_size);

    SetColor(color);
}


Rectangle::~Rectangle()
{
}

void Rectangle::SetPosition(sf::Vector2f position)
{
    m_position = position;
}

void Rectangle::SetColor(int & color)
{
    ShapeBase::SetColor(color);
}

void Rectangle::Draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
}

void Rectangle::Scale(float newScale)
{
    m_shape.scale(newScale, newScale);
}
