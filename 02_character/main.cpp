//
//  main.cpp
//  02_character
//
//  Created by Zheng Jasper on 13/09/2023.
//

#include <iostream>
#include <vector>
using namespace std;


class Item {
public:
    Item(){};
};


class Character {
private:
    long int hp, ad, ar;
    vector<Item> items;
public:
    string name;
    Character(string name, int hp, int ad, int ar);
    void respawn();
};

class Computer : public Character{
public:
    Computer(string name, int hp, int ad, int ar);
};



int main() {
    Character bob("bob", 2000, 400, 100);
    Character alice("alice", 1000, 300, 200);
    bob.respawn();
    alice.respawn();
    
    Computer james("james", 1000, 300, 200);
    james.respawn();
    
    return 0;
}


Character::Character(string name, int hp, int ad, int ar){
    // some code for initialisation..
    this->name = name;
    this->hp = hp;
    this->ad = ad;
    this->ar = ar;
    cout << "character: " << name << " created" << endl;
}
Computer::Computer(string name, int hp, int ad, int ar): Character(name, hp, ad, ar){
    this->name = name + "(computer)";
    cout << "computer: " << this->name << " created" << endl;
};


void Character::respawn() {
    // some code for respawning...
    cout << name << " respawned with hp: " << hp << endl;
}




