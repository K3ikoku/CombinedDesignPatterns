#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "TeamColors.h"
#include "RedTeam.h"
#include "BlueTeam.h"
#include "MagentaTeam.h"
#include "GreenTeam.h"
class GameManager
{
public:
	GameManager();
	~GameManager();

	void GameLoop();

private:
	void Creator();
	void Update();
	void Collision();
	void Draw();

	float m_elapsedTime;
	std::vector<TeamColors*> m_teams;
	sf::RenderWindow m_window;

};

