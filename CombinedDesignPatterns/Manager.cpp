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

    //sf::CircleShape m_testCircle(24);
    //m_testCircle.setPosition(m_window.getSize().x / 2, m_window.getSize().y / 2);
    //m_testCircle.setFillColor(sf::Color::Blue);

    //sf::RectangleShape m_testRect(sf::Vector2f(50, 100));
    //m_testRect.setPosition(m_window.getSize().x * 0.5f, m_window.getSize().y * 0.5f);
    //m_testRect.setFillColor(sf::Color::Green);

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
        m_guiShape = m_drawableHandler->TryGetShapeReference(m_inputManager->GetShape(), m_inputManager->GetColor(), m_inputManager->GetSize());
        m_guiShape->Scale(m_guiShapeScale);
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
        m_window.clear(sf::Color::White);
        for (unsigned int i = 0; i < m_drawableHandler->GetShapesSize(); i++)
        {
            ShapeBase* m_shapeToDraw = m_drawableHandler->GetShape(i);
            m_shapeToDraw->Draw(m_window);
        }
    }
}
