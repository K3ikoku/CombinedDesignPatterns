#include "ShapeFactory.h"



ShapeFactory::ShapeFactory(sf::RenderWindow& window) :
    m_window(window),
    m_drawableHandler(DrawableHandler::GetInstance())
{
}


ShapeFactory::~ShapeFactory()
{
}

void ShapeFactory::CreateNewShape(int& color, int& shape, int& size, sf::Vector2f position)
{
    m_newShape = GetShape(shape, size, color, position);
    
    m_drawableHandler->AddShape(m_newShape);
}

ShapeBase * ShapeFactory::GetShape(int& shape, int& size, int& color, sf::Vector2f position)
{
    ShapeBase* m_tempUnit = m_drawableHandler->TryGetShapeReference(shape, size, color);
    m_tempUnit->SetPosition(position);
    return m_newShape;
}
