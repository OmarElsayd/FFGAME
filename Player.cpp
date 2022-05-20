#include "Player.h"
using namespace std;

Player::Player(string name, int attackItemLevel, int defenseItemLevel, int maxHealthLevel, int money) {
	player = name;
	attackItem = new Item("Sword", attackItemLevel);
	defenseItem = new Item("Shield", defenseItemLevel);
	maxHealth = new Item("Health", maxHealthLevel);
	this->money = money;
}

int Player::fightWinningCriteria(Player* p) {
	// You can choose any criteria for fighting
	return (p->attackItem->getItemLevel() + p->defenseItem->getItemLevel() + p->maxHealth->getItemLevel());
}

void Player::fightPlayer(Player enemy) {
	// You can choose any criteria for fighting
	if ((attackItem->getItemLevel() + defenseItem->getItemLevel() + maxHealth->getItemLevel()) > (enemy.attackItem->getItemLevel() + enemy.defenseItem->getItemLevel() + enemy.maxHealth->getItemLevel())) {
		cout << "You won the fight. You won 50 coins" << endl;
		this->money += 50; //Assuming each win earns this much money
		if (enemy.money > 50) enemy.money -= 50; // Assuming each lose costs this much money
		else enemy.money = 0;
	}
	else if ((attackItem->getItemLevel() + defenseItem->getItemLevel() + maxHealth->getItemLevel()) < (enemy.attackItem->getItemLevel() + enemy.defenseItem->getItemLevel() + enemy.maxHealth->getItemLevel())) {
		cout << "You lost the fight. You lost 50 coins" << endl;
		if (this->money > 50) this->money -= 50;
		else this->money = 0;
		enemy.money += 50;
	}
	else {
		cout << "It's a tie" << endl;
	}
}

void Player::upgradePlayerItem(string item) {
	if (item == "Attack") {
		money -= attackItem->upgradeItem(money);
	}
	if (item == "Defense") {
		money -= defenseItem->upgradeItem(money);
	}
	if (item == "Health") {
		money -= maxHealth->upgradeItem(money);
	}
}

void Player::printStats() {
	cout << " \n\n Player Name :" << player;
	cout << " --- Items --- ";
	attackItem->getItemInfo();
	defenseItem->getItemInfo();
	maxHealth->getItemInfo();
	cout << " Money : " << money << " coins \n\n" << endl;
}

void Player::saveGame() {
	ofstream file;
	file.open((player + ".txt").c_str());
	file << player << "," << attackItem->getItemLevel() << "," << defenseItem->getItemLevel() << "," << maxHealth->getItemLevel() << "," << money;
	file.close();
}
