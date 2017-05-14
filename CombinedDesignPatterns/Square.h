#pragma once
#include "ShapeBase.h"
class Square :
    public ShapeBase
{
public:
    Square(int& color, int& size);
    ~Square();

    void SetPosition(sf::Vector2f position);
    void SetColor(int& color);
    void Draw(sf::RenderWindow& window) override;
    void Scale(float newScale) override;

private:
    sf::CircleShape m_shape;
    float m_size;
};

