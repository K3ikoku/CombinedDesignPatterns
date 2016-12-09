#pragma once
#include "TeamColors.h"
class GreenTeam :
	public TeamColors
{
public:
	GreenTeam();
	~GreenTeam();

	void Update() override;

	void Draw(const sf::RenderWindow& renderWindow) override;


private:
	std::vector<Entity*> m_team;
};
