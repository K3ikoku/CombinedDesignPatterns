#pragma once
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Octagon.h"
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

    void AddShape(ShapeBase* shape);
    void Remove(ShapeBase* shape);
    void Remove(const int index);

    ShapeBase* TryGetShapeReference(int& shape, int& size, int& color);

    ShapeBase* GetShape(const int& index);

    int GetShapesSize();

    void Clear();
    
    const char* GetColorText(int value);
    const char* GetShapeText(int value);
    const char* GetSizeText(int value);

private:
    DrawableHandler();
    ShapeBase * CreateNewSHape(int& shape, int& size, int& color, const char& name);
    static DrawableHandler* m_instance;
    static sf::RenderWindow* m_window;
    std::vector<ShapeBase*> m_activeShapes;
    std::map<const char, ShapeBase*> m_shapes;

    static const char* ColorString[];
    static const char* ShapesString[];
    static const char* SizeString[];

};

