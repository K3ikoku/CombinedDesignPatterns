#include "DrawableHandler.h"

DrawableHandler* DrawableHandler::m_instance = nullptr;

DrawableHandler::DrawableHandler()
{
}


DrawableHandler* DrawableHandler::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new DrawableHandler();

    return m_instance;
}

DrawableHandler::~DrawableHandler()
{
}

void DrawableHandler::Add(ShapeBase * shape)
{
    m_shapes.push_back(shape);
}

void DrawableHandler::Remove(ShapeBase * shape)
{
    for (unsigned int i = 0; i < m_shapes.size(); i++)
    {
        if (m_shapes[i] == shape)
        {
            delete m_shapes[i];
            m_shapes.erase(m_shapes.begin() + i);
            break;
        }
    }
}

void DrawableHandler::Remove(const int index)
{
    delete m_shapes[index];
    m_shapes.erase(m_shapes.begin() + index);
}

ShapeBase & DrawableHandler::GetShape(const int index)
{
    return *m_shapes[index];
}

int DrawableHandler::GetSize()
{
    return 0;
}

void DrawableHandler::Clear()
{
    m_shapes.clear();
}
