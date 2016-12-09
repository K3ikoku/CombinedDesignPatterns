#include "Entity.h"

Entity::Entity() :
	m_width(0),
	m_height(0),
	m_speed(0),
	m_xPos(0),
	m_yPos(0)
{
}

Entity::~Entity() {
}

sf::Clock Entity::m_gameClock = sf::Clock();