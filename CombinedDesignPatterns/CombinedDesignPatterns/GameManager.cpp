#include "GameManager.h"



GameManager::GameManager() :
	m_window(sf::VideoMode(900, 900), "Window"),
	m_elapsedTime(0)

{
	//Remove all teams from vector in in case there are any
	for (unsigned int i = m_teams.size(); i <= 0; i--)
	{
		if (m_teams.size() == 0)
		{
			break;
		}
		else
		{
			delete m_teams[i];
			m_teams.erase(m_teams.begin() + i);
		}
	}

	//Create all teams and put them in vector
	RedTeam* redTeam = new RedTeam;
	GreenTeam* greenTeam = new GreenTeam;
	BlueTeam* blueTeam = new BlueTeam;
	MagentaTeam* magentaTeam = new MagentaTeam;
	m_teams.push_back(redTeam);
	m_teams.push_back(greenTeam);
	m_teams.push_back(blueTeam);
	m_teams.push_back(magentaTeam);

}


GameManager::~GameManager()
{
}

void GameManager::GameLoop()
{
	sf::Clock clock;
	m_window.setFramerateLimit(128);


	while (m_window.isOpen())
	{
		sf::Event m_event;
		while (m_window.pollEvent(m_event))
		{
			if (m_event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}
	}
	Creator();
	Update();
	Draw();

	m_elapsedTime = clock.restart().asSeconds;
}

void GameManager::Creator()
{
}

void GameManager::Update()
{
	for (unsigned int i = 0; i < m_teams.size(); i++)
	{
		m_teams[i]->Update();
	}
}

void GameManager::Collision()
{
	for (unsigned int i = 0; i < m_teams.size(); i++)
	{
		m_teams[i]->Collision();
	}
}


void GameManager::Draw()
{
	for (unsigned int i = 0; i < m_teams.size(); i++)
	{
		m_teams[i]->Draw(m_window);
	}
}
