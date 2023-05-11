#include <cstdlib> //for random numbers
#include <ctime>   //for seeding random number generators
#include <iostream>
#include <string>
using namespace std;

class spaceship{
public:
  string name;
  int fuel;
  int shields;
  int health;

  spaceship();
  spaceship(string givenName);
  void status();
};

spaceship::spaceship(){
  name = "spaceship";
  fuel = 0;
  shields = 0;
  health = 0;
}
spaceship::spaceship(string givenName){
  name = givenName;
  fuel = 100;
  shields = 20;
  health = 100;
}

void spaceship::status(){
  cout << name << endl;
  cout << "Fuel: " << fuel << endl;
  cout << "Shields: " << shields << endl;
  cout << "Health: " << health << endl;
  cout << "-------------------------------" << endl;
}

void battle(spaceship ship1, spaceship ship2){
  srand(time(0));

  while (ship1.health > 0 && ship2.health > 0){
    
    ship1.shields -= rand() % 20;
    
    if(ship1.shields <= 0){
      ship1.shields = 0;
      ship1.health -= rand() % 10;
    }

  
    ship1.fuel -= rand() % 5;
    
    ship2.shields -= rand() % 20;
    
    if(ship2.shields <= 0){
      ship2.shields = 0;
      ship2.health -= rand() % 10;
    }
    
    ship2.fuel -= rand() % 5;

    cout << "The Battle Continues!\n\n";
    ship1.status();
    ship2.status();
    cout << "\n-------------------------------\n-------------------------------\n\n";
  }

  if(ship1.health <= 0){
    cout << ship2.name << " Wins!";
  }

  else if (ship2.health <= 0){
    cout << ship1.name << " Wins!";
  }
}

int main() {
  srand(time(0));
  string shipNames[6] = {"Milano", "Enterprise", "Millenium Falcon", "Destroyer", "Razorcrest", "Nostromo"};
  spaceship spaceships[6];
  
  for(int i = 0; i < 6; i++){
    spaceships[i] = spaceship(shipNames[i]);   
  }
  
  battle(spaceships[rand() % 6], spaceships[rand() % 6]);
}