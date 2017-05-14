#include "InputManager.h"



InputManager::InputManager(sf::RenderWindow& window) :
    m_drawableHandler(DrawableHandler::GetInstance()),
    m_lastColor(DrawableHandler::Color::LastColor - 1),
    m_lastShape(DrawableHandler::Shapes::LastShape - 1),
    m_maxSize(DrawableHandler::Size::LastSize - 1),
    m_color(0),
    m_shape(0),
    m_size(0),
    m_window(window),
    m_shapeFactory(new ShapeFactory(window))
{
}


InputManager::~InputManager()
{
}

void InputManager::HandleInput()
{
    //Check if the player is pressing W or S to increment and decrement the color enum
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        m_color++ % m_lastColor;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        m_color--;

    //Check if the player is pressing D or A to increment and decrement the shape enum
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_shape++ % m_lastShape;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_shape--;

    //Check if the player is pressing E or Q to increment and decrement the size enum
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        m_size++ % m_maxSize;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        m_size--;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        m_drawableHandler->Clear();

    //Reset the variables if they go beyond 0
    if (m_color < 0)
        m_color = m_lastColor;

    if (m_shape < 0)
        m_shape = m_lastShape;

    if (m_size < 0)
        m_size = m_maxSize;

    m_mouseInput.x = sf::Mouse::getPosition(m_window).x;
    m_mouseInput.y = sf::Mouse::getPosition(m_window).y;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        m_shapeFactory->CreateNewShape(m_color, m_shape, m_size, m_mouseInput); 
}

int& InputManager::GetShape()
{
    return m_shape;
}

int& InputManager::GetColor()
{
    return m_color;
}

int& InputManager::GetSize()
{
    return m_size;
}
