#include "DrawableHandler.h"

DrawableHandler* DrawableHandler::m_instance = nullptr;
sf::RenderWindow* DrawableHandler::m_window = nullptr;

const char*  DrawableHandler::ColorString[] =
{
    "Red", "Blue", "Green", "Yellow", "White", "Magenta", "Black"
};

const char* DrawableHandler::ShapesString[] =
{
    "Circle","Rectangle","Square", "Triangle", "Octogon"
};

const char* DrawableHandler::SizeString[] =
{
    "xSmall", "Small","Medium", "Large", "xLarge", "xxLarge"
};

DrawableHandler::DrawableHandler()
{
}

ShapeBase * DrawableHandler::CreateNewSHape(int& shape, int& size, int& color, const char& name)
{
    ShapeBase* m_newShape;
    switch (shape)
    {
    case CircleShape:
        m_newShape = new Circle(color, size);
        break;

    case RectangleShape:
        m_newShape = new Rectangle(color, size);
        break;
    case SquareShape:
        m_newShape = new Square(color, size);
        break;
    case TriangleShape:
        m_newShape = new Triangle(color, size);
        break;
    case OctogonShape:
        m_newShape = new Octagon(color, size);
        break;
    default:
        return nullptr;
        break;
    }

    m_shapes[name] = m_newShape;
    return m_newShape;
}

DrawableHandler * DrawableHandler::GetInstance(sf::RenderWindow& window)
{
    if (m_window == nullptr)
        m_window = &window;

    if (m_instance == nullptr)
        m_instance = new DrawableHandler();

    return m_instance;
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

void DrawableHandler::AddShape(ShapeBase * shape)
{
    m_activeShapes.push_back(shape);
}

void DrawableHandler::Remove(ShapeBase * shape)
{
    for (unsigned int i = 0; i < m_activeShapes.size(); i++)
    {
        if (m_activeShapes[i] == shape)
        {
            delete m_activeShapes[i];
            m_activeShapes.erase(m_activeShapes.begin() + i);
            break;
        }
    }
}

void DrawableHandler::Remove(const int index)
{
    delete m_activeShapes[index];
    m_activeShapes.erase(m_activeShapes.begin() + index);
}

ShapeBase* DrawableHandler::TryGetShapeReference(int& shape, int& size, int& color)
{
    const char* m_name = GetSizeText(size) + *GetColorText(color) + *GetShapeText(shape);
    ShapeBase* m_newShape;

    if (m_shapes.find(*m_name) == m_shapes.end())
        m_newShape = CreateNewSHape(shape, size, color, *m_name);

    else
        m_newShape = m_shapes.at(*m_name);

    return m_newShape;
}

ShapeBase & DrawableHandler::GetShape(const int& index)
{
    return *m_activeShapes[index];
}

int DrawableHandler::GetShapesSize()
{
    return m_activeShapes.size();
}

void DrawableHandler::Clear()
{
    m_activeShapes.clear();
}

const char * DrawableHandler::GetColorText(int value)
{
    //std::cout << ColorString[value];
    return ColorString[value];
}

const char * DrawableHandler::GetShapeText(int value)
{
    //std::cout << ShapesString[value];
    return ShapesString[value];
}

const char * DrawableHandler::GetSizeText(int value)
{
    //std::cout << SizeString[value];
    return SizeString[value];
}
