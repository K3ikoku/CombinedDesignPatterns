#pragma once
#include "ShapeBase.h"
class Octagon :
    public ShapeBase
{
public:
    Octagon(sf::RenderWindow& window, sf::Color& color, float xPos, float yPos, int width, int height);
    ~Octagon();

    void Draw() override;
};

