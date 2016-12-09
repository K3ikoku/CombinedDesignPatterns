#pragma once
#include "TeamColors.h"
class MagentaTeam :
	public TeamColors
{
public:
	MagentaTeam();
	~MagentaTeam();

	void Update() override;

	void Draw(const sf::RenderWindow& renderWindow) override;

private:
	std::vector<Entity*> m_team;
};

