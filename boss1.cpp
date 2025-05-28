#include "boss1.hpp"
#include "projectiles.hpp"
#include "bossFunction.hpp"

short boss1hp = 100;
float targetX = 550.f;

float boss1X = 550.f;
float boss1Y = 50.f;

sf::Texture boss1Texture("boss1.png");
sf::Sprite boss1Sprite(boss1Texture);

void simulateBoss1(sf::RenderWindow& window, sf::FloatRect shipHitbox, sf::Vector2f position) {
	if (boss1hp <= 0) { killBoss(); }
	else {
		boss1hp = bossCollision(boss1hp, boss1Sprite, 150.f);
		boss1Sprite.setScale(sf::Vector2f(5.f, 5.f));
		if (generateRandomNumber(1, 20) == 1) {attack(boss1Sprite, 5, 2);}
		if (generateRandomNumber(1, 100) == 1) { targetX = position.x; }

		boss1X = boss1Sprite.getPosition().x + (targetX - boss1Sprite.getPosition().x) * .1f;
		boss1Sprite.setPosition(sf::Vector2f(boss1X, boss1Y));
		window.draw(boss1Sprite);
	}
}