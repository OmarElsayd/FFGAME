#include "Item.h"

Item::Item(string name, int level) {
	itemName = name;
	itemLevel = level;
	upgrade = 10 * itemLevel; // Can assume any value
}

int Item::getItemLevel()
{
	return itemLevel;
}
void Item::getItemInfo()
{
	cout << this->itemName << " : Level " << this->itemLevel << endl;
}

int Item::upgradeItem(int money)
{
	if (upgrade > money) {
		cout << "Upgrade costs " << upgrade << " , but you only have " << money << " coins. Try again later." << endl;
		return 0;
	}
	else {
		itemLevel += 1;
		int itemMoney = upgrade;
		upgrade = 10 * itemLevel; // More money required for next upgrade
		cout << "Item upgraded " << endl;
		return itemMoney;
	}
}