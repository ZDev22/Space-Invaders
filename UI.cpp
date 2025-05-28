#include "UI.hpp"

sf::Texture shipUITexture("ship1.png");
sf::Sprite shipUISprite(shipUITexture);
sf::Font UIFont("airstrikeb3d.ttf");
sf::Text UIText(UIFont);

void simulateUI(sf::RenderWindow& window) {
	shipUISprite.setPosition(sf::Vector2f(10.f, 10.f));
	shipUISprite.setScale(sf::Vector2f(3.f, 3.f));
	shipUITexture.loadFromFile(playerShip);
	shipUISprite.setTexture(shipUITexture);
	UIText.setString("X" + std::to_string(playerHealth));
	UIText.setPosition(sf::Vector2f(50.f, -10.f));
	UIText.setScale(sf::Vector2f(2.f, 2.f));
	window.draw(UIText);
	window.draw(shipUISprite);
}