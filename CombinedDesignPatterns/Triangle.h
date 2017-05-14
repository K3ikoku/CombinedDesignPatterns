#pragma once
#include "ShapeBase.h"
class Triangle :
    public ShapeBase
{
public:
    Triangle(int& color, int& size);
    ~Triangle();

    void SetPosition(sf::Vector2f position);
    void SetColor(int& color);
    void Draw(sf::RenderWindow& window) override;
    void Scale(float newScale);

private:
    sf::CircleShape m_shape;
    float m_size;
};

