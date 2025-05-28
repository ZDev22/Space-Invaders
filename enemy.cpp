#include "enemy.hpp"
#include "main.hpp"
#include "wave.hpp"
#include "projectiles.hpp"
#include "particles.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

std::vector<Enemy> enemies;
sf::FloatRect enemyHitbox;

void createEnemy(string texture, float X, float Y) {
    Enemy enemy;
    enemy.texture = texture;
    enemy.X = X;
    enemy.Y = Y;
    if (texture == "enemy1.png" || texture == "enemy4.png") { enemy.health = 1; }
    else if (texture == "enemy2.png") { enemy.health = 3; }
    else if (texture == "enemy3.png") { enemy.health = 8; }
    
    enemy.dead = false;
    enemy.speedX = 1;
    enemy.startX = X;
    enemy.speedY = 0;
    enemy.startY = Y;
    enemy.hitPlayer = false;

    enemies.push_back(enemy);
}

void spawnProjectile(auto enemy) {
    Projectiles projectile;
    projectile.X = enemy.X;
    projectile.Y = enemy.Y;
    projectile.damage = 1;
    projectile.speed = 5;
    projectile.texture = "projectile1.png";
    projectile.isEnemy = true;

    projectiles.push_back(projectile);
}

void simulateEnemies(sf::RenderWindow& window, sf::FloatRect shipHitbox, sf::Sprite& enemySprite, sf::Texture& enemyTexture) {

    enemySprite.setScale(sf::Vector2f(2.f, 2.f));

    if (enemies.size() == 0) {startWave();}

    for (auto& enemy : enemies) {

        if (!enemy.dead) {

            enemy.X += enemy.speedX;
            enemy.speedY--;

            if (enemy.speedY <= 0 && enemy.Y == enemy.startY) { enemy.speedY = 0; enemy.hitPlayer = false; }
            enemy.Y += enemy.speedY;

            if (enemy.X <= enemy.startX) { enemy.speedX = -enemy.speedX; }
            if(enemy.X >= enemy.startX + 70.f) { enemy.speedX = -enemy.speedX; }

            enemySprite.setPosition(sf::Vector2f(enemy.X, enemy.Y));
            enemyTexture.loadFromFile(enemy.texture);
            enemySprite.setTexture(enemyTexture);

            window.draw(enemySprite);

            if (enemy.texture == "enemy3.png") {

                if (generateRandomNumber(1, 100) == 100) { spawnProjectile(enemy); }
                if (generateRandomNumber(1, 1000) == 100 && enemy.Y == enemy.startY) { enemy.speedY = 25;}

                if ((!(enemy.speedY <= 0 && enemy.Y == enemy.startY)) && !enemy.hitPlayer) {

                    enemyHitbox.position = sf::Vector2f(enemy.X, enemy.Y + 7.5f);
                    enemyHitbox.size = sf::Vector2f(30.f, 30.f);

                    if (enemyHitbox.findIntersection(shipHitbox)) {

                        enemy.hitPlayer = true;
                        playerHealth -= 1;

                        Particle particle;
                        particle.X = shipHitbox.position.x;
                        particle.Y = shipHitbox.position.y;
                        particle.life = 30;
                        particle.speed = 4;
                        particle.texture = "particleObject.png";
                        particle.scale = sf::Vector2f(3.f, 3.f);

                        particle.dir = 20.f;
                        particles.push_back(particle);
                        particle.dir = 65.f;
                        particles.push_back(particle);
                        particle.dir = 110.f;
                        particles.push_back(particle);
                        particle.dir = 155.f;
                        particles.push_back(particle);
                        particle.dir = 200.f;
                        particles.push_back(particle);
                        particle.dir = 245.f;
                        particles.push_back(particle);
                        particle.dir = 290.f;
                        particles.push_back(particle);
                        particle.dir = 335.f;
                        particles.push_back(particle);
                    }
                }
            }
            else if (enemy.texture == "enemy4.png") { if (generateRandomNumber(1, 80) == 1) { spawnProjectile(enemy); } }
            else if (generateRandomNumber(1, 600) == 100) { spawnProjectile(enemy); }
        }
    }
}