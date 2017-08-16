#include "ShapeBase.h"
#include "Drawablehandler.h"


ShapeBase::ShapeBase(sf::Shape& shape) :
    m_shape(&shape),
    m_scale(1)
{
    m_position = m_shape->getPosition();
}

ShapeBase::~ShapeBase()
{
}

void ShapeBase::SetPosition(sf::Vector2f position)
{
    m_position = position;
    if (m_shape != nullptr)
        m_shape->setPosition(position.x, position.y);
}

void ShapeBase::Draw(sf::RenderWindow & window)
{
    if (m_shape != nullptr)
    {
        m_shape->setScale(m_scale, m_scale);
        m_shape->setPosition(m_position);
        window.draw(*m_shape);
    }
}

void ShapeBase::SetNewScale(float & newScale)
{
    if (m_shape != nullptr)
    {
        m_scale = newScale;
        m_shape->setScale(newScale, newScale);
    }
}


