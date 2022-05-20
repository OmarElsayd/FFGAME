#ifndef Item_h
#define Item_h
#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
using namespace std;

class Item {
private:
	string itemName;
	int itemLevel;
	int upgrade;

public:
	// Constructor
	Item(string name, int level);
	int getItemLevel();
	void getItemInfo();
	int upgradeItem(int money);

};
#endif
