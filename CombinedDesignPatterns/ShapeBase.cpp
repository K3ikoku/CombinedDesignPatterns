#include "ShapeBase.h"
#include "Drawablehandler.h"



ShapeBase::ShapeBase(int& color, int& size) 
{
}

ShapeBase::ShapeBase()
{
}

ShapeBase::~ShapeBase()
{
}

void ShapeBase::SetColor(int & color)
{
    switch (color)
    {
    case DrawableHandler::Color::Red:
        m_color = sf::Color::Red;
        break;
    case DrawableHandler::Color::Blue:
        m_color = sf::Color::Blue;
        break;
    case DrawableHandler::Color::Green:
        m_color = sf::Color::Green;
        break;
    case DrawableHandler::Color::Yellow:
        m_color = sf::Color::Yellow;
        break;
    case DrawableHandler::Color::White:
        m_color = sf::Color::White;
        break;
    case DrawableHandler::Color::Magenta:
        m_color = sf::Color::Magenta;
        break;
    case DrawableHandler::Color::Black:
        m_color = sf::Color::Black;
        break;
    default:
        break;
    }
}

