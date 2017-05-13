#pragma once
#include "ShapeBase.h"
class Rectangle :
    public ShapeBase
{
public:
    Rectangle(sf::RenderWindow& window, sf::Color& color, float xPos, float yPos, int width, int height);
    ~Rectangle();

    void Draw() override;
};

