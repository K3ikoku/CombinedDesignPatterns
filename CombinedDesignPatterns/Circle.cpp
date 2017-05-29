#include "Circle.h"
#include "DrawableHandler.h"


Circle::Circle(int& color, int& size)
{
    m_shape = sf::CircleShape(75);

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

Circle::~Circle()
{
}

void Circle::SetPosition(sf::Vector2f position)
{
    m_shape.setPosition(position.x, position.y);
}

void Circle::SetColor(int & color)
{
    ShapeBase::SetColor(color);

    m_shape.setFillColor(m_color);
}

void Circle::Draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
}

void Circle::Scale(float newScale)
{
    m_shape.scale(newScale, newScale);
}
