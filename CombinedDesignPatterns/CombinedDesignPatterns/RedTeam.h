#pragma once
#include "TeamColors.h"
class RedTeam :
	public TeamColors
{
public:
	RedTeam();
	~RedTeam();

	void Update() override;

	void Draw(const sf::RenderWindow& renderWindow) override;

private:
	std::vector<Entity*> m_team;
};

