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

int main() {
    Character bob("bob", 2000, 400, 100);
    Character alice("alice", 1000, 300, 200);
    bob.respawn();
    alice.respawn();
    
    return 0;
}


Character::Character(string name, int hp, int ad, int ar){
    // some code for initialisation..
    this->name = name;
    this->hp = hp;
    this->ad = ad;
    this->ar = ar;
}
void Character::respawn() {
    // some code for respawning...
    cout << name << " respawned with hp: " << hp << endl;
}




