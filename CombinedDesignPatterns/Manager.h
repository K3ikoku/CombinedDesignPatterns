#pragma once
#include <SFML\Graphics.hpp>
#include "DrawableHandler.h"
#include "InputManager.h"

class Manager
{
public:
    Manager();
    ~Manager();

    void ProgramLoop();

private:
    sf::RenderWindow m_window;
    DrawableHandler* m_drawableHandler;
    InputManager* m_inputManager;
    ShapeBase* m_guiShape;
    float m_guiShapeScale = 0.5f;

    void Gui();
    void Update();
    void Draw();
};

