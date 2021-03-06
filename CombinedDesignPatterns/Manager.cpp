#include "Manager.h"



Manager::Manager() :
    m_window(sf::VideoMode(640, 640), "Shape Drawer"),
    m_drawableHandler(DrawableHandler::GetInstance()),
    m_inputManager(new InputManager(m_window))
{
}


Manager::~Manager()
{
}

void Manager::ProgramLoop()
{
    m_window.setFramerateLimit(60);
    while (m_window.isOpen())
    {
        //Create an event for closing the window
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }
        m_window.clear(sf::Color::Black);
        Gui();
        Update();
        Draw();
        m_window.display();
    }
}

void Manager::Gui()
{
    if (m_inputManager->GetNewGuiShape() == true)
    {
        m_guiShape = new ShapeBase(*m_drawableHandler->TryGetShapeReference(m_inputManager->GetShape(), m_inputManager->GetSize(), m_inputManager->GetColor()));
        m_guiShape->SetNewScale(m_guiShapeScale);
        m_guiShape->SetPosition(sf::Vector2f(0, 0));
    }
    m_guiShape->Draw(m_window);
}

void Manager::Update()
{
    m_inputManager->HandleInput();
}

void Manager::Draw()
{
    if (m_drawableHandler->GetShapesSize() > 0)
    {
        for (unsigned int i = 0; i < m_drawableHandler->GetShapesSize(); i++)
        {
            ShapeBase* m_shapeToDraw = m_drawableHandler->GetShape(i);
            m_shapeToDraw->Draw(m_window);
        }
    }
}
