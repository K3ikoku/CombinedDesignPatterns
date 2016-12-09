#pragma once
#include <SFML\Graphics.hpp>
class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update(const sf::RenderWindow& renderWindow, float elapsedTime) = 0;
	virtual void Collision(Entity* enemies) = 0;
	virtual void Draw(const sf::RenderWindow& renderWindow) = 0;

	virtual void DestroyEnemy(bool isDead) = 0;
	virtual bool IsDead() const { return m_isDead; }


protected:
	bool m_isDead;
	int m_width;
	int m_height;
	float m_speed;
	float m_xPos;
	float m_yPos;

	static sf::Clock m_gameClock;
};

