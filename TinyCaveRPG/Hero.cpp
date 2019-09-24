// Chad Sutherland
// 5/12/2019
#include "Hero.h"
#include "Map.h"

Hero::Hero() {
	Position pos(2, 1);
	setLevel(1);
	setMaxHP(10);
	setCurrentHP(10);
	setCurrentEXP(0);
	setMaxEXP(4);
	setBaseDamage(1);
	setDamage(getBaseDamage());
	setPosition(pos);
	inventoryPosition = Position(0, 0);
	isEquipped = false;
	isDead = false;
}

Hero::Hero(int maxHP, int currentHP, Position currentPos) {
	setLevel(1);
	setMaxHP(maxHP);
	setCurrentHP(currentHP);
	setCurrentEXP(0);
	setMaxEXP(0);
	setBaseDamage(1);
	setDamage(getBaseDamage());
	setPosition(currentPos);
	inventoryPosition = Position(0, 0);
	isEquipped = false;
	isDead = false;
}

void Hero::setCurrentHP(int hp) {
	if (hp < 0)
		hp = 0;
	currentHealth = hp;
	if (currentHealth == 0) 
		isDead = true;
	if (hp > getMaxHealth())
		currentHealth = maxHealth;
}

void Hero::setCurrentEXP(int exp) {
	if (exp < 0)
		currentEXP = currentEXP % maxEXP;
	else currentEXP = exp;
}

string Hero::showInventory(Map &map) {
	return map.getPositionDescription(inventoryPosition);
}

void Hero::move(Map &map, Direction dir) {
	try {
		currentPosition.setPosition(map, dir);
	}
	catch (Position::InvalidPositionexception) {
		throw Position::InvalidPositionexception();
	}
}

bool Hero::pickup(Map &map, string input) {
	bool pickedUp = false;
	if (map.moveItem(currentPosition, inventoryPosition, input)) {
		pickedUp = true;
	}
	return pickedUp;
}

bool Hero::drop(Map &map, string input) {
	bool dropped = false;
	if (map.moveItem(inventoryPosition, currentPosition, input)) {
		unequip();
		dropped = true;
	}
	return dropped;
}

bool Hero::equip(Map &map, string input) {
	Item* searchResult = nullptr;
	Weapon* weaponConversion;

	searchResult = map.findItem(inventoryPosition, input);
	weaponConversion = dynamic_cast<Weapon*>(searchResult);

	if (weaponConversion != nullptr) {
		if (isEquipped)
			unequip();
		setDamage(getBaseDamage() + weaponConversion->getValue());
		isEquipped = true;
	}
	return isEquipped;
}

bool Hero::unequip() {
	if (isEquipped) {
		setDamage(getBaseDamage());
		isEquipped = false;
		return true;
	}
	else
		return false;
}

string Hero::eat(Map &map, string input) {
	string info;
	Food* food = nullptr;
	Item* searchResult = nullptr;

	if (!(searchResult = map.findItem(inventoryPosition, input))) {
		info = "You don't have that item.";
	}
	else if (!(food = dynamic_cast<Food*>(searchResult))) {
		info = "You cannot eat that.";
	} else {
		setCurrentHP(getCurrentHealth() + food->getValue());
		map.deleteItem(food);
		info = "You ate " + input + ".";
	}
	return info;
}

string Hero::drink(Map &map, string input) {
	string info;
	Drink* drink = nullptr;
	Item* searchResult = nullptr;

	if (!(searchResult = map.findItem(inventoryPosition, input))) {
		info = "You don't have that item.";
	}
	else if (!(drink = dynamic_cast<Drink*>(searchResult))) {
		info = "You cannot drink that.";
	} else {
		setCurrentHP(getCurrentHealth() + drink->getValue());
		map.deleteItem(drink);
		info = "You drank " + input + ".";
	}
	return info;
}

bool Hero::levelUp() {
	bool levelUp = false;
	while (currentEXP >= maxEXP) {
		level++;
		maxEXP += 5;
		maxHealth += 5;
		baseDamage += 1;
		damage += 1;
		currentHealth = maxHealth;		
		setCurrentEXP(currentEXP - maxEXP);
		levelUp = true;
	}
	return levelUp;
}

string Hero::attack(Map &map, string input) {
	Spell* newSpell = nullptr;
	string combatInfo;
	Enemy* target = nullptr;
	target = map.findEnemy(currentPosition, input);
	
	if (target != nullptr) {
		target->setHealth(target->getCurrentHealth() - getDamage());
		combatInfo += "You hit " + target->getName() + " for " + to_string(getDamage()) + " damage!\n";

		if (target->getCurrentHealth() == 0) {
			currentEXP += target->getMaxHealth();
			combatInfo += target->getName() + " died! " + to_string(target->getMaxHealth()) + " experience points earned.\n";
			combatInfo += target->getName() + " dropped a " + target->dropWeapon(map) + ".\n";
			map.deleteEnemy(target);
			if (levelUp()) {
				combatInfo += "Level up! Your max health is now " + to_string(maxHealth) + " and your base damage is now " + to_string(baseDamage) + ".\n";

				switch (level) {
				case 2: newSpell = new Spell("Magic Missile", 3, getInventoryPosition()); break;
				case 4: newSpell = new Spell("Fireball", 5, getInventoryPosition()); break;
				case 6: newSpell = new Spell("Disintegrate", 8, getInventoryPosition()); break;
				}
				if (newSpell != nullptr) {
					map.learnSpell(*newSpell);
					combatInfo += "You learned a new spell " + newSpell->getDescription() + "!\n";
				}
			}
		
		}
		else {
			combatInfo += target->attack(*this) + "\n";
		}
	}
	else {
		combatInfo += "That enemy doesn't exist here.\n";
	}
	return combatInfo;
}


string Hero::cast(Map &map, string input) {
	string combatInfo;
	Spell* newSpell = nullptr;
	Enemy* target = nullptr;
	target = map.findEnemy(currentPosition, input);

		if (target != nullptr) {
			try {
				Spell spell = map.castSpell();
				target->setHealth(target->getCurrentHealth() - spell.getValue());
				combatInfo += "You cast " + spell.getDescription() + " on " + target->getName() + " dealing " + to_string(spell.getValue()) + " damage!\n";

				if (target->getCurrentHealth() == 0) {
					currentEXP += target->getMaxHealth();
					combatInfo += target->getName() + " died! " + to_string(target->getMaxHealth()) + " experience points earned.\n";
					combatInfo += target->getName() + " dropped a " + target->dropWeapon(map) + ".\n";
					map.deleteEnemy(target);
					if (levelUp()) {
						combatInfo += "Level up! Your max health is now " + to_string(maxHealth) + " and your base damage is now " + to_string(baseDamage) + ".\n";

						switch (level) {
						case 2: newSpell = new Spell("Magic Missile", 3, getInventoryPosition()); break;
						case 4: newSpell = new Spell("Fireball", 5, getInventoryPosition()); break;
						case 6: newSpell = new Spell("Disintegrate", 8, getInventoryPosition()); break;
						}
						if (newSpell != nullptr) {
							map.learnSpell(*newSpell);
							combatInfo += "You learned a new spell " + newSpell->getDescription() + "!\n";
						}
					}
				}
				else {
					combatInfo += target->attack(*this) + "\n";
				}
			}
			catch (Map::OOBexception) {
				combatInfo += "You are out of spells!";
			}
		}
		else {
			combatInfo += "That enemy doesn't exist here.\n";
		}
	
	return combatInfo;
}