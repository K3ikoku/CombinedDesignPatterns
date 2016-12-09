#pragma once
#include "GreenTeam.h"

GreenTeam::GreenTeam()
{
}

GreenTeam::~GreenTeam()
{
}

void GreenTeam::Update()
{
	for (unsigned int i = 0; i < m_team.size(); i++)
	{
		m_team[i]->Update();
	}
}

void GreenTeam::Draw(const sf::RenderWindow& renderWindow)
{
	for (unsigned int i = 0; i < m_team.size(); i++)
	{
		m_team[i]->Draw(renderWindow);
	}
}
