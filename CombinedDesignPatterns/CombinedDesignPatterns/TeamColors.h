#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Entity.h"
class TeamColors
{
public:
	TeamColors();
	~TeamColors();
	virtual void Update();
	virtual void Draw(const sf::RenderWindow& renderWindow);


private:
	std::vector<Entity*> m_team;
};

