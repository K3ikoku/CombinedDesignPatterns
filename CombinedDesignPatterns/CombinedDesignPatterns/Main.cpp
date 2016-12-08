#include <SFML\Graphics.hpp>
#include "GameManager.h"


int main()
{


	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works");
	GameManager* m_gameManager = new GameManager;

	m_gameManager->GameLoop(window);
	//sf::CircleShape shape(100.f);

	//shape.setFillColor(sf::Color::Green);

	//while (window.isOpen())
	//{
	//	sf::Event m_event;

	//	while (window.pollEvent(m_event))
	//	{
	//		if (m_event.type == sf::Event::Closed)
	//		{
	//			window.close();
	//		}

	//		window.clear();
	//		window.draw(shape);
	//		window.display();
	//	}
	//}

	return 0;
}