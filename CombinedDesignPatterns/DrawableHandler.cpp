#include "DrawableHandler.h"

#include <string>

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

sf::Shape * DrawableHandler::CreateNewShape(int& shape, int& size, int& color, std::string name)
{
    float m_size = GetNewSize(size);
    sf::Shape* m_newShape = GetNewShape(shape, m_size);
    m_newShape->setFillColor(GetNewColor(color));

    m_shapes[name] = m_newShape;
    return m_newShape;
}

sf::Shape * DrawableHandler::GetNewShape(int & shape, float & size)
{
    sf::Shape * m_newShape;
    switch (shape)
    {
    case CircleShape:
        m_newShape = new sf::CircleShape(size);
        break;

    case RectangleShape:
        m_newShape = new sf::RectangleShape(sf::Vector2f(size, (size / 2)));
        break;
    case SquareShape:
        m_newShape = new sf::CircleShape(size, 4);
        break;
    case TriangleShape:
        m_newShape = new sf::CircleShape(size, 3);
        break;
    case OctogonShape:
        m_newShape = new sf::CircleShape(size, 8);
        break;
    default:
        m_newShape = new sf::CircleShape(size);
        break;
    }
    return m_newShape;
}

float DrawableHandler::GetNewSize(int & size)
{
    float m_size = 75;
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
    return m_size;
}

sf::Color DrawableHandler::GetNewColor(int & color)
{
    sf::Color m_color = sf::Color::Red;
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
    return m_color;
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

void DrawableHandler::AddShapeBase(ShapeBase *shape)
{
    m_activeShapeBases.push_back(shape);
}

void DrawableHandler::RemoveShapeBase(ShapeBase * shape)
{
    for (unsigned int i = 0; i < m_activeShapeBases.size(); i++)
    {
        if (m_activeShapeBases[i] == shape)
        {
            delete m_activeShapeBases[i];
            m_activeShapeBases.erase(m_activeShapeBases.begin() + i);
            break;
        }
    }
}

void DrawableHandler::Remove(const int index)
{
    delete m_activeShapeBases[index];
    m_activeShapeBases.erase(m_activeShapeBases.begin() + index);
}

sf::Shape* DrawableHandler::TryGetShapeReference(int& shape, int& size, int& color)
{
    std::string sizeText = GetSizeText(size);
    std::string colorText = GetColorText(color);
    std::string shapeText = GetShapeText(shape);

    std::string m_name = sizeText + colorText + shapeText;
    sf::Shape* m_newShape;
    if (m_shapes.find(m_name) == m_shapes.end())
        m_newShape = CreateNewShape(shape, size, color, m_name);

    else
        m_newShape = m_shapes.at(m_name);

    return m_newShape;
}

ShapeBase * DrawableHandler::GetShape(const int& index)
{
    return m_activeShapeBases[index];
}

int DrawableHandler::GetShapesSize()
{
    return m_activeShapeBases.size();
}

void DrawableHandler::Clear()
{
    m_activeShapeBases.clear();
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
