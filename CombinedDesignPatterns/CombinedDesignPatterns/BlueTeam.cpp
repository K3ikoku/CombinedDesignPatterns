#include "BlueTeam.h"



BlueTeam::BlueTeam()
{
}


BlueTeam::~BlueTeam()
{
}

void BlueTeam::Update()
{
	for (unsigned int i = 0; i < m_team.size(); i++)
	{
		m_team[i]->Update();
	}
}

void BlueTeam::Draw(const sf::RenderWindow& renderWindow)
{
	for (unsigned int i = 0; i < m_team.size(); i++)
	{
		m_team[i]->Draw(renderWindow);
	}
}
