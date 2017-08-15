#pragma once
#include <vector>
#include "ShapeBase.h"
#include <iostream>

class DrawableHandler
{

public:
    enum Color
    {
        Red,
        Blue,
        Green,
        Yellow,
        White,
        Magenta,
        Black,
        LastColor
    };


    enum Shapes
    {
        CircleShape,
        RectangleShape,
        SquareShape,
        TriangleShape,
        OctogonShape,
        LastShape
    };

    enum Size
    {
        xSmall,
        Small,
        Medium,
        Large,
        xLarge,
        xxLarge,
        LastSize
    };

    static DrawableHandler* GetInstance(sf::RenderWindow& window);
    static DrawableHandler* GetInstance();
    ~DrawableHandler();

    void AddShapeBase(ShapeBase* shape);
    void RemoveShapeBase(ShapeBase* shape);
    void Remove(const int index);

    sf::Shape* TryGetShapeReference(int& shape, int& size, int& color);

    ShapeBase* GetShape(const int& index);

    int GetShapesSize();

    void Clear();

    const char* GetColorText(int value);
    const char* GetShapeText(int value);
    const char* GetSizeText(int value);

private:
    DrawableHandler();
    sf::Shape * CreateNewShape(int& shape, int& size, int& color, std::string name);
    sf::Shape * GetNewShape(int& shape, float& size);
    float GetNewSize(int& size);
    sf::Color GetNewColor(int& color);
    static DrawableHandler* m_instance;
    static sf::RenderWindow* m_window;
    std::vector<ShapeBase*> m_activeShapeBases;
    std::map < std::string, sf::Shape *> m_shapes;

    static const char* ColorString[];
    static const char* ShapesString[];
    static const char* SizeString[];

};

