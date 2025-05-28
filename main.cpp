#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "main.hpp"
#include <random>

using namespace std;

short wave = 0;
short playerHealth = 5;

bool bossAlive = false;

string playerShip = "ship1.png";

int generateRandomNumber(short min, short max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}


int main() {

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Space Invaders");
	window.setFramerateLimit(60);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {if (event->is<sf::Event::Closed>()) { window.close(); }}

        window.clear();

		simulateShip(window);

        window.display();
    }
	return 0;
}