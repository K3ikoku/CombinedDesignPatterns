#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "TeamColors.h"
class GameManager
{
public:
	GameManager();
	~GameManager();

	void GameLoop(sf::RenderWindow& renderWindow);

private:
	void Draw(sf::RenderWindow& renderWindow);
	void Creator();

	std::vector<TeamColors*> m_teams;

};

