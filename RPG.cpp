#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Character;
class Monster;
class Item;

class Item {
public:
    string name;
    int value;

    Item(string _name, int _value) : name(_name), value(_value) {}
};

class Character {
public:
    string name;
    int health;
    int attack;

    Character(string _name, int _health, int _attack) : name(_name), health(_health), attack(_attack) {}

    void attackCharacter(Character& target) {
        int damage = rand() % attack;
        cout << name << " attacks " << target.name << " for " << damage << " damage." << endl;
        target.health -= damage;
    }

    // Function to check if the character is alive
    bool isAlive() {
        return health > 0;
    }

   
    void displayInfo() {
        cout << "Name: " << name << "\nHealth: " << health << "\nAttack: " << attack << endl;
    }
};


class Monster : public Character {
public:
    Monster(string _name, int _health, int _attack) : Character(_name, _health, _attack) {}
};

// Function to handle battles between characters
void battle(Character& player, Monster& monster) {
    while (player.isAlive() && monster.isAlive()) {
        player.attackCharacter(monster);
        if (monster.isAlive()) {
            monster.attackCharacter(player);
        }
    }

    if (player.isAlive()) {
        cout << "You defeated the " << monster.name << "!" << endl;
    } else {
        cout << "You were defeated by the " << monster.name << ". Game Over!" << endl;
        exit(0);
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    
    Character player("Player", 100, 20);


    Monster monster1("Goblin", 30, 10);
    Monster monster2("Dragon", 100, 30);

    cout << "Welcome to the Text-Based RPG!" << endl;
    player.displayInfo();

 
    while (player.isAlive()) {
        cout << "Choose an action:" << endl;
        cout << "1. Battle a monster" << endl;
        cout << "2. Quit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            int randomMonster = rand() % 2;
            if (randomMonster == 0) {
                battle(player, monster1);
            } else {
                battle(player, monster2);
            }
        } else if (choice == 2) {
            cout << "Thanks for playing!" << endl;
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
