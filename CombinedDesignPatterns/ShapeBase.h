#pragma once
#include <SFML\Graphics.hpp>
class ShapeBase
{
public:
    ShapeBase(sf::RenderWindow& window, sf::Color& color, float xPos, float yPos, int width, int height);
    ShapeBase();
    ~ShapeBase();

    virtual void Draw() = 0;

protected:
    int width;
    int height;
    sf::Vector2i position;

};

