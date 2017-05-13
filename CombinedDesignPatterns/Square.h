#pragma once
#include "ShapeBase.h"
class Square :
    public ShapeBase
{
public:
    Square(sf::RenderWindow& window, sf::Color& color, float xPos, float yPos, int width, int height);
    ~Square();

    void Draw() override;
};

