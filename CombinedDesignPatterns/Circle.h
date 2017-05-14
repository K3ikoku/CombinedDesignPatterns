#pragma once
#include "ShapeBase.h"
class Circle :
    public ShapeBase
{
public:
    Circle(int& color, int& size);
    ~Circle();

    void SetPosition(sf::Vector2f position) override;
    void SetColor(int& color) override;
    void Draw(sf::RenderWindow& window) override;
    void Scale(float newScale) override;

private:
    sf::CircleShape m_shape;
    float m_size;
};

