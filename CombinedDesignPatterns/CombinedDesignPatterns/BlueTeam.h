#pragma once
#include "TeamColors.h"
class BlueTeam :
	public TeamColors
{
public:
	BlueTeam();
	~BlueTeam();

	void Update() override;

	void Draw(const sf::RenderWindow& renderWindow) override;


private:
	std::vector<Entity*> m_team;
};

