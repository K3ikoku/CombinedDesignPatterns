#include "ShapeBase.h"
#include "Drawablehandler.h"



ShapeBase::ShapeBase(sf::Shape& shape) :
    m_shape(shape)
{
}

ShapeBase::~ShapeBase()
{
}

void ShapeBase::SetPosition(sf::Vector2f position)
{
    m_position = position;
    m_shape->setPosition(position.x, position.y);
}

void ShapeBase::Draw(sf::RenderWindow & window)
{
    window.draw(*m_shape);
}

void ShapeBase::SetNewScale(float & newScale)
{
    m_shape->setScale(newScale, newScale);
}


