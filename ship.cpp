#include "ship.hpp"
#include <SFML/Graphics.hpp>
#include "enemy.hpp"
#include "particles.hpp"
#include <iostream>
#include "projectiles.hpp"
#include "upgrades.hpp"
#include "bossFunction.hpp"
#include "UI.hpp"

sf::Texture shipTexture("ship1.png");
sf::Sprite ship(shipTexture);

sf::Texture enemyTexture("enemy1.png");
sf::Sprite randomSprite(enemyTexture);

sf::Texture deathTexture("death.png");
sf::Sprite deathSprite(deathTexture);

sf::FloatRect hitbox;

sf::Clock shootTimer;

float speedX = 0.f;
float speedY = 0.f;

float X = 640.f;
float Y = 660.f;

short autoFireRate = 225;

bool shooting = false;

vector<Projectiles> projectiles;

void simulateShip(sf::RenderWindow& window) {

	shootTimer.start();

	simulateUpgrades(window, hitbox);
	simulateEnemies(window, hitbox, randomSprite, enemyTexture);

	ship.setScale(sf::Vector2f(1.5f, 1.5f));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { speedY -= .1f; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { speedY += .1f; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) { speedX -= .1f; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) { speedX += .1f; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		if (!shooting || shootTimer.getElapsedTime().asMilliseconds() >= autoFireRate) {

			if (shooting) { shootTimer.reset(); }

			shooting = true;

			Projectiles projectile;
			projectile.X = X + 7.5f;
			projectile.Y = Y;
			if (playerShip == "ship1.png") { 
				projectile.texture = "projectile1.png";
				projectile.damage = 1;
				projectile.speed = 5;
				autoFireRate = 225;
			}
			else if (playerShip == "ship2.png") {
				projectile.texture = "projectile2.png"; 
				projectile.damage = 2;
				projectile.speed = 7;
				autoFireRate = 250;
			}
			else if (playerShip == "ship3.png") { 
				projectile.texture = "projectile3.png";
				projectile.damage = 3;
				projectile.speed = 10;
				autoFireRate = 300;
			}
			
			projectile.isEnemy = false;

			projectiles.push_back(projectile);
		}
	}
	else { shooting = false; }

	hitbox.size = (sf::Vector2f(5.f, 5.f));
	hitbox.position = (sf::Vector2f(X + 7.5f, Y));

	simulateProjectiles(window, hitbox);

	if (playerHealth <= 0) {
		deathSprite.setScale(sf::Vector2f(.5f, .5f));
		window.draw(deathSprite);
	}
	else {
		speedX *= 0.99f;
		speedY *= 0.99f;

		X += speedX;
		if (X > 1255.f) {
			X = 1255.f;
			speedX = 0.f;
		}
		if (X < 0.f) {
			X = 0.f;
			speedX = 0.f;
		}
		Y += speedY;
		if (Y > 695.f) {
			Y = 695.f;
			speedY = 0.f;
		}
		if (Y < 0.f) {
			Y = 0.f;
			speedY = 0.f;
		}

		shipTexture.loadFromFile(playerShip);
		ship.setTexture(shipTexture);
		ship.setPosition(sf::Vector2f(X, Y));

		if (bossAlive) {
			switch (wave) {
			case 4:
				simulateBosses(window, hitbox, 1, ship.getPosition());
				break;
			case 6:
				simulateBosses(window, hitbox, 2, ship.getPosition());
				break;
			}
		}

		window.draw(ship);

		simulateUI(window);

		simulateParticles(window);
	}
}