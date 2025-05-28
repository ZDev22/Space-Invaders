#ifndef BOSSFUNCTION_HPP
#define BOSSFUNCTION_HPP

#include <SFML/Graphics.hpp>

void simulateBosses(sf::RenderWindow& window, sf::FloatRect shipHitbox, short boss, sf::Vector2f position);
short bossCollision(short hp, sf::Sprite bossSprite, float size);
void killBoss();
void attack(sf::Sprite boss, short speed, short damage);

#endif