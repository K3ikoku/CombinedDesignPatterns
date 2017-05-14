#pragma once
#include <SFML\Graphics.hpp>
class DrawableHandler;
class ShapeBase
{
public:
    
    ShapeBase(int& color, int& size);
    ShapeBase();
    ~ShapeBase();
    virtual void SetPosition(sf::Vector2f position) = 0;
    virtual void SetColor(int& color);
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual void Scale(float newScale) = 0;

protected:
    int m_width;
    int m_height;
    sf::Vector2f m_position;
    sf::Color m_color;
};

