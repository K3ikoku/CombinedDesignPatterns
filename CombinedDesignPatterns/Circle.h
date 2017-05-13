#pragma once
#include "ShapeBase.h"
class Circle :
    public ShapeBase
{
public:
    Circle(sf::RenderWindow& window, sf::Color& color, float xPos, float yPos, int width, int height);
    ~Circle();

    void Draw() override;
};

