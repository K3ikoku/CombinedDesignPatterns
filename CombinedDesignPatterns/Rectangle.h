#pragma once
#include "ShapeBase.h"
class Rectangle :
    public ShapeBase
{
public:
    Rectangle(int& color, int& size);
    ~Rectangle();

    void SetPosition(sf::Vector2f position) override;
    void SetColor(int& color);
    void Draw(sf::RenderWindow& window) override;
    void Scale(float newScale) override;

private:
    sf::RectangleShape m_shape;
    sf::Vector2f m_size;
};

