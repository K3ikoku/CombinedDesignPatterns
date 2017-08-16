#pragma once
#include <SFML\Graphics.hpp>
class DrawableHandler;
class ShapeBase
{
public:

    ShapeBase(sf::Shape& shape);
    ~ShapeBase();

    void SetPosition(sf::Vector2f position);
    void Draw(sf::RenderWindow& window);
    void SetNewScale(float& newScale);

private:
    int m_width;
    int m_height;
    float m_scale;
    sf::Vector2f m_position;
    sf::Color m_color;
    sf::Shape* m_shape;
    //DrawableHandler* m_drawableHandler;
};

