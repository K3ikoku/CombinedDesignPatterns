#pragma once
#include <vector>
#include "ShapeBase.h"

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
        Last
    };

    enum Shapes
    {
        Circle,
        Rectangle,
        Square,
        Triangle,
        Octogon,
        Last
    };

    enum Size
    {
        xSmall,
        Small,
        Medium,
        Large,
        xLarge,
        xxLarge,
        Last
    };

    static DrawableHandler* GetInstance();
    ~DrawableHandler();

    void Add(ShapeBase* shape);
    void Remove(ShapeBase* shape);
    void Remove(const int index);

    ShapeBase& GetShape(const int index);

    int GetSize();

    void Clear();

private:
    DrawableHandler();
    static DrawableHandler* m_instance;

    std::vector<ShapeBase*> m_shapes;


};

