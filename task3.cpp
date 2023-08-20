#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Item {
public:
    Item(const std::string& name, int power) : name(name), power(power) {}

    std::string getName() const {
        return name;
    }

    int getPower() const {
        return power;
    }

private:
    std::string name;
    int power;
};

class Character {
public:
    Character(const std::string& name, int health, int damage) : name(name), health(health), damage(damage), experience(0) {}

    void attack(Character& target) {
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!" << std::endl;
        target.takeDamage(damage);
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health <= 0) {
            std::cout << name << " has been defeated!" << std::endl;
        }
    }

    void gainExperience(int amount) {
        experience += amount;
        std::cout << name << " gains " << amount << " experience points!" << std::endl;
    }

    void addItem(const Item& item) {
        inventory.push_back(item);
        std::cout << name << " collects " << item.getName() << "!" << std::endl;
    }

    std::string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getExperience() const {
        return experience;
    }

    void showInventory() const {
        if (inventory.empty()) {
            std::cout << name << "'s inventory is empty." << std::endl;
        } else {
            std::cout << name << "'s inventory:" << std::endl;
            for (const Item& item : inventory) {
                std::cout << "- " << item.getName() << " (Power: " << item.getPower() << ")" << std::endl;
            }
        }
    }

private:
    std::string name;
    int health;
    int damage;
    int experience;
    std::vector<Item> inventory;
};

int main() {
    srand(time(nullptr));

    Character player("Hero", 100, 20);
    Character monster("Dragon", 150, 30);

    Item sword("Sword", 10);
    Item potion("Potion", 0);

    player.addItem(sword);
    monster.addItem(potion);

    std::cout << "Welcome to the Text RPG!" << std::endl;
    std::cout << "You, " << player.getName() << ", have encountered a " << monster.getName() << "!" << std::endl;

    while (player.getHealth() > 0 && monster.getHealth() > 0) {
        player.attack(monster);
        if (monster.getHealth() > 0) {
            monster.attack(player);
        }
    }

    if (player.getHealth() <= 0) {
        std::cout << "Game Over! " << player.getName() << " has been defeated." << std::endl;
    } else {
        std::cout << "Congratulations! You have defeated the " << monster.getName() << " and gained experience!" << std::endl;
        player.gainExperience(50);
        player.showInventory();
    }

    return 0;
}
