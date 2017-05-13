#pragma once
#include "ShapeBase.h"
class Triangle :
    public ShapeBase
{
public:
    Triangle(sf::RenderWindow& window, sf::Color& color, float xPos, float yPos, int width, int height);
    ~Triangle();

    void Draw() override;
};

