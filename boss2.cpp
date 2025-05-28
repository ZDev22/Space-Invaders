#include "boss2.hpp"
#include "projectiles.hpp"
#include "bossFunction.hpp"
#include "enemy.hpp"

short boss2hp = 250;

float boss2X = 0.f;
float boss2Y = -1000.f;

short bossWave = 0;

sf::Texture boss2Texture("boss2.png");
sf::Sprite boss2Sprite(boss2Texture);

void simulateBoss2(sf::RenderWindow& window, sf::FloatRect shipHitbox, sf::Vector2f position) {
	if (boss2hp <= 0) { killBoss(); }
	else {
		boss2Sprite.setScale(sf::Vector2f(13.f, 13.f));
		if (generateRandomNumber(1, 20) == 1) { 
			if (generateRandomNumber(1, 2) == 1) { boss2Sprite.setPosition(sf::Vector2f(-50.f, boss2Y - 100.f)); }
			else { boss2Sprite.setPosition(sf::Vector2f(1180.f, boss2Y - 100.f)); }

			attack(boss2Sprite, 5, 2);
		}

		if (enemies.size() == 1) {
			bossWave++;
			switch (bossWave) {
			case 1:
				createEnemy("enemy3.png", 300.f, 250.f);
				createEnemy("enemy3.png", 350.f, 250.f);
				createEnemy("enemy3.png", 400.f, 250.f);
				createEnemy("enemy3.png", 450.f, 250.f);
				createEnemy("enemy3.png", 500.f, 250.f);
				createEnemy("enemy3.png", 550.f, 250.f);
				createEnemy("enemy3.png", 600.f, 250.f);
				createEnemy("enemy3.png", 650.f, 250.f);
				createEnemy("enemy3.png", 700.f, 250.f);
				createEnemy("enemy3.png", 750.f, 250.f);
				createEnemy("enemy3.png", 800.f, 250.f);
				createEnemy("enemy3.png", 850.f, 250.f);
				break;
			case 2:
				createEnemy("enemy2.png", 150.f, 250.f);
				createEnemy("enemy2.png", 200.f, 250.f);
				createEnemy("enemy2.png", 250.f, 250.f);
				createEnemy("enemy2.png", 300.f, 250.f);
				createEnemy("enemy2.png", 350.f, 250.f);
				createEnemy("enemy2.png", 400.f, 250.f);
				createEnemy("enemy2.png", 450.f, 250.f);
				createEnemy("enemy2.png", 500.f, 250.f);
				createEnemy("enemy2.png", 550.f, 250.f);
				createEnemy("enemy2.png", 600.f, 250.f);
				createEnemy("enemy2.png", 650.f, 250.f);
				createEnemy("enemy2.png", 700.f, 250.f);
				createEnemy("enemy2.png", 750.f, 250.f);
				createEnemy("enemy2.png", 800.f, 250.f);
				createEnemy("enemy2.png", 850.f, 250.f);
				createEnemy("enemy2.png", 900.f, 250.f);
				createEnemy("enemy2.png", 950.f, 250.f);
				createEnemy("enemy2.png", 1000.f, 250.f);
				break;
			case 3:
				createEnemy("enemy1.png", 150.f, 250.f);
				createEnemy("enemy1.png", 200.f, 250.f);
				createEnemy("enemy1.png", 250.f, 250.f);
				createEnemy("enemy1.png", 300.f, 250.f);
				createEnemy("enemy1.png", 350.f, 250.f);
				createEnemy("enemy1.png", 400.f, 250.f);
				createEnemy("enemy1.png", 450.f, 250.f);
				createEnemy("enemy1.png", 500.f, 250.f);
				createEnemy("enemy1.png", 550.f, 250.f);
				createEnemy("enemy1.png", 600.f, 250.f);
				createEnemy("enemy1.png", 650.f, 250.f);
				createEnemy("enemy1.png", 700.f, 250.f);
				createEnemy("enemy1.png", 750.f, 250.f);
				createEnemy("enemy1.png", 800.f, 250.f);
				createEnemy("enemy1.png", 850.f, 250.f);
				createEnemy("enemy1.png", 900.f, 250.f);
				createEnemy("enemy1.png", 950.f, 250.f);
				createEnemy("enemy1.png", 1000.f, 250.f);
				break;
			case 4:
				bossWave--;
				boss2Y = boss2Sprite.getPosition().y + (-525.f - boss2Sprite.getPosition().y) * .1f;
				if (generateRandomNumber(1, 4) == 1) {
					boss2Sprite.setPosition(sf::Vector2f(generateRandomNumber(20, 1000), boss2Y));
					attack(boss2Sprite, 5, 2);
					boss2hp = bossCollision(boss2hp, boss2Sprite, 1000.f);
				}
				if (shipHitbox.getCenter().y <= 200.f) {playerHealth--;}
				break;
			}
		}
		boss2Sprite.setPosition(sf::Vector2f(boss2X, boss2Y));
		window.draw(boss2Sprite);
	}
}