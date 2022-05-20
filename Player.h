#ifndef Player_h
#define Player_h
#include "Item.h"

using namespace std;

class Player {
private:
	Item* attackItem;
	Item* defenseItem;
	Item* maxHealth;
	int money;
public:
	string player;
	Player(string name, int attackItemLevel, int defenseItemLevel, int maxHealthLevel, int money);
	int fightWinningCriteria(Player* p);


	void fightPlayer(Player enemy);
	void upgradePlayerItem(string item);
	void printStats();
	void saveGame();

};
#endif
