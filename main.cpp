#include "Item.h"
#include "Player.h"
#include <istream>
#include <cstdlib>
#include <string>


using namespace std;


void print()
{
        cout<<"Welcome to Omar's FANTASY FIGHTING GAME."<<endl;
	    cout<<"In this game, you will have 2 weapons."<<endl;
	    cout<<"You will have a sword as an attack weapon"<<endl;
	    cout<<"and shield as a defance weapon."<<endl;
	    cout<<"you can upgrad items from the store whenever you want as well as you can upgrad your health"<<endl;
	    cout<<"using the moeny you will gain from the fight."<<endl;
	    cout<<"Also, if you are a new player, you will get 300 gold pice (Use them Wisly! ;) )"<<endl;
	    cout<<"Are you ready?"<<endl;
}
void gameMenu(Player p) {
	int choice;
	do {
	    
		cout << "______GAME MENU_______ \n 1. Upgrade Items \n 2. Fight \n 3. Save Game \n 4. Get Player Stats \n5. Quit\n Choose one option: ";
		cin >> choice;
		if (choice == 1) {
			int option;
			do {
				cout << " What do you want to buy : \n 1.Sowrd attack Item \n 2.Shield defense Item \n 3. Health \n 4. Back \nChoose : ";
				cin >> option;
				if (option == 1) {
					p.upgradePlayerItem("Attack");
				}
				else if (option == 2) {
					p.upgradePlayerItem("Defense");
				}
				else if (option == 3) {
					p.upgradePlayerItem("Health");
				}
				else if (option == 4) break;
				else cout << "Invalid choice. Try again" << endl;
			} while (option >= 0 && option <= 4);
		}
		else if (choice == 2) {
			cout << "Each game will cost you 50 coins" << endl;
			cout << "Starting game \n" << endl;
			// Create a random enemy with level 1 - 5 items and random coins 1-100
			Player enemy("Enemy", rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 100 + 1);
			p.fightPlayer(enemy);
		}
		else if (choice == 3) {
			cout << "Saving game." << endl;
			p.saveGame();
			cout << "Game saved." << endl;
		}
		else if (choice == 4) {
			p.printStats();
		}
		else if (choice == 5) {
			break; // Go the main menu
		}
		else {
			cout << "Invalid choice. Try again " << endl;
		}
	} while (choice >= 1 && choice <= 5);
}

void newGame() {
	cout << "Enter player Name: ";
	string name;
	cin >> name;
	Player p(name, 1, 1, 5, 300); // Initially, attack and defense are level 1, health is level 5 and the amount of money 
	gameMenu(p);                    // each player will start with 300 coins 
}

void loadGame(string savedName) {
	ifstream myfile;
	myfile.open((savedName + ".txt").c_str());
	if (myfile.is_open()) {
		cout << "Saved Game loaded" << endl;
		string line;
		getline(myfile, line);
		const char* delimiter = ",";
		string name = strtok((char*)line.c_str(), delimiter);
		char* attckLvl = strtok(NULL, delimiter);
		char* defenseLvl = strtok(NULL, delimiter);
		char* healthLvl = strtok(NULL, delimiter);
		char* money = strtok(NULL, delimiter);

		Player p(name, atoi(attckLvl), atoi(defenseLvl), atoi(healthLvl), atoi(money));
		gameMenu(p);
	}
	else {
		cout << "Not Found" << endl;
	}
}

void simulateGame() {
    print();
	int option;
	do {
		cout << "------ MAIN MENU ------- \n 1. New Game \n 2. Load Game \n3. Quit\n Choose one option:";
		cin >> option;
		if (option == 1) {
			newGame();
		}
		else if (option == 2) {
			cout << "Type Saved Player's Name: ";
			string savedName;
			cin >> savedName;
			loadGame(savedName);
		}
		else if (option == 3) {
			break;
		}
		else {
			cout << "Invalid option." << endl;
		}
	} while (option != 1 || option != 2 || option != 3);
}

int main() {
	simulateGame();
	return 0;
}