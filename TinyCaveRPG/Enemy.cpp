// Daniyar Aubekerov
// 5/12/2019
#include "Enemy.h"
#include "Hero.h"
#include "Map.h"

int Enemy::numEnemies = 0;

Enemy* Enemy::deserialize(fstream &is) {
	int enemyID;
	is.read(reinterpret_cast<char*>(&enemyID), sizeof(int));
	switch (enemyID) {
	case 1: return new Thief(is); break;
	case 2: return new Bear(is); break;
	case 3: return new Zombie(is); break;
	case 4: return new Orc(is); break;
	default: return nullptr; break;
	}
}

Enemy::Enemy(string newName, int damage, int maxHP, Weapon* weapon) {
	setName(newName);
	setDamage(damage);
	setMaxHealth(maxHP);
	setWeapon(weapon);
	numEnemies++;
}

Enemy::Enemy(string newName, Position pos, int damage, int curHP, int maxHP, Weapon* weapon) {
	setName(newName);
	setPosition(pos);
	setDamage(damage);
	setHealth(curHP);
	setMaxHealth(maxHP);
	setWeapon(weapon);
	numEnemies++;
}

Enemy::~Enemy() {
	numEnemies--;
}

void Enemy::setHealth(int health) { 
	if (health < 0)
		health = 0;
	currentHealth = health;
}

string Enemy::attack(Hero &myHero) {
	string combatInfo = "";
	myHero.setCurrentHP(myHero.getCurrentHealth() - damage);
	combatInfo += name + " hits you for " + to_string(damage) + " damage!\n" +
		"Current health: " + to_string(myHero.getCurrentHealth()) + "/" + to_string(myHero.getMaxHealth()) + ".\n";
	if (myHero.getIsDead())
		combatInfo += "You have died!!!\n";

	return combatInfo;
}

string Enemy::dropWeapon(Map &map) {
	map.addItem(weapon);
	return weapon->getDescription();
}

int Enemy::randBetween(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}