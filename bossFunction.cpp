#include "bossFunction.hpp"
#include "projectiles.hpp"
#include "particles.hpp"
#include "enemy.hpp"
#include "main.hpp"
#include "boss1.hpp"
#include "boss2.hpp"
#include <iostream>

sf::FloatRect bossHitbox;
sf::FloatRect projectileHitbox;

int a;

void simulateBosses(sf::RenderWindow& window, sf::FloatRect shipHitbox, short boss, sf::Vector2f position) {
	switch (boss) {
	case 1:
		simulateBoss1(window, shipHitbox, position);
		break;
	case 2:
		simulateBoss2(window, shipHitbox, position);
		break;
	}
}

short bossCollision(short hp, sf::Sprite bossSprite, float size) {
	bossHitbox.position = (sf::Vector2f(bossSprite.getPosition().x, bossSprite.getPosition().y - 46.f));
	bossHitbox.size = (sf::Vector2f(size, size));
	for (a = projectiles.size() - 1; a >= 0; --a) {
		if (!projectiles[a].isEnemy) {
			projectileHitbox.position = (sf::Vector2f(projectiles[a].X, projectiles[a].Y));
			projectileHitbox.size = (sf::Vector2f(2.f, 2.f));
			if (bossHitbox.findIntersection(projectileHitbox)) {

				Particle particle;
				particle.X = projectiles[a].X;
				particle.Y = projectiles[a].Y;
				particle.life = 30;
				particle.speed = 4;
				particle.texture = "particleProjectile.png";
				particle.scale = sf::Vector2f(2.f, 2.f);

				particle.dir = 0.f;
				particles.push_back(particle);
				particle.dir = 45.f;
				particles.push_back(particle);
				particle.dir = 90.f;
				particles.push_back(particle);
				particle.dir = 135.f;
				particles.push_back(particle);
				particle.dir = 180.f;
				particles.push_back(particle);
				particle.dir = 225.f;
				particles.push_back(particle);
				particle.dir = 270.f;
				particles.push_back(particle);
				particle.dir = 315.f;
				particles.push_back(particle);

				projectiles.erase(projectiles.begin() + a);
				if (playerShip == "ship1.png") { hp -= 1; }
				else if (playerShip == "ship2.png") { hp -= 2; }
				else if (playerShip == "ship3.png") { hp -= 3; }
			}
		}
	}
	return hp;
}

void killBoss() {
	for (auto boss = enemies.begin(); boss != enemies.end(); ++boss) {
		if (boss->texture == "boss.png") {
			enemies.erase(boss);
			bossAlive = false;
			break;
		}
	}
}

void attack(sf::Sprite boss, short speed, short damage) {

	Projectiles projectile;
	projectile.X = boss.getPosition().x + 70.f;
	projectile.Y = boss.getPosition().y + 20.f;
	projectile.isEnemy = true;
	projectile.texture = "bossAttack.png";
	projectile.speed = speed;
	projectile.damage = damage;

	projectiles.push_back(projectile);
}