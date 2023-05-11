#include "enemy.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;

enemy::enemy(string givenName) {
  //srand(time(0));

  cout << "\nNew enemy has appeared.\n";
  name = givenName;
  health = 10;
  damage = rand() % 4 + 3;
  status();
}

void enemy::status() {
  cout << "\nName: " << name;
  cout << "\nHealth: " << health;
  cout << "\nDamage: " << damage;
}

int enemy::getHealth(){
  return health;
}

void enemy::setHealth(int by){
  
  health += by;
  
  if(health < 0){
    health = 0;
  }

  if (health > 10){
    health = 10;
  }
}

void enemy::setName(string newName){
  if(newName != "bad"){
    name = newName;
    return;
  }

  else{
    cout << "That's a bad word.";
  }
}

string enemy::getName(){
  return name;
}

