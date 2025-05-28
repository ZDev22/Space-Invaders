#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

struct Enemy {
	string texture;
	float X;
	float Y;
	float startX;
	float startY;
	short health;
	short speedX;
	short speedY;
	bool dead;
	bool hitPlayer;
};

extern std::vector<Enemy> enemies;

void createEnemy(string textureFile, float X, float Y);
void simulateEnemies(sf::RenderWindow& window, sf::FloatRect shipHitbox, sf::Sprite& enemySprite, sf::Texture& texture);

#endif