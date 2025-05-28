#include "upgrades.hpp"
#include "main.hpp"

vector<Upgrades> upgrades;

sf::Texture upgradeTexture("ship1.png");
sf::Sprite upgradeSprite(upgradeTexture);

sf::FloatRect upgradeHitbox;

sf::CircleShape upgrade;

int s;

void simulateUpgrades(sf::RenderWindow& window, sf::FloatRect shipHitbox) {
	upgradeSprite.setScale(sf::Vector2f(2.f, 2.f));
	upgrade.setRadius(20.f);
	upgradeHitbox.size = sf::Vector2f(40.f, 40.f);
	for (s = upgrades.size() - 1; s >= 0; --s) {
		upgrades[s].Y += 1;
		upgradeTexture.loadFromFile(upgrades[s].upgrade);
		upgradeSprite.setTexture(upgradeTexture);
		upgradeSprite.setPosition(sf::Vector2f(upgrades[s].X + 3.5f, upgrades[s].Y + 3.f));
		upgradeHitbox.position = sf::Vector2f(upgrades[s].X + 10.f, upgrades[s].Y);
		if (upgradeHitbox.findIntersection(shipHitbox)) {
			if (upgrades[s].upgrade == "health.png") { playerHealth++; }
			else { playerShip = upgrades[s].upgrade; }
			upgrades.erase(upgrades.begin() + s);
		}
		else {
			upgrade.setPosition(sf::Vector2f(upgrades[s].X, upgrades[s].Y));
			window.draw(upgrade);
			window.draw(upgradeSprite);
		}
	}
}