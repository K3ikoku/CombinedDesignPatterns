#pragma once
#include "ShapeBase.h"
class Octagon :
    public ShapeBase
{
public:
    Octagon(int& color, int& size);
    ~Octagon();

    void SetPosition(sf::Vector2f position);
    void SetColor(int& color);
    void Draw(sf::RenderWindow& window) override;
    void Scale(float newScale) override;

private:
    sf::CircleShape m_shape;
    float m_size;
};

