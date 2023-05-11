#include <ctime> //seeding random numbers
#include <iostream>
#include <stdlib.h> //for random numbers
using namespace std;

int main() {
  string playerName;
  int health = 10;
  int attack = 0;
  int block = 0;
  int turns = 0;
  
  string input;
  
  srand(time(0));

  cout << "Welcome to my dungeon.\nWhat is thou name fine warrior?\n";
  getline(cin, playerName);

  cout << "Good luck " << playerName << ". You'll need it.\n";
  cout << ".\n.\n.\n\n";

  cout << "An enemy approaches! Prepare to fight!\n\n";

  do {
    health = 10;
    turns = 0;
    while (health > 0 && turns < 4) {
      attack = rand() % 5;
      block = rand() % 5;

      cout << "Enemy attack score: " << attack << endl;
      cout << "Your Block score: " << block << endl;

      if (attack <= block) {
        cout << "Amazing block! ";
        cout << "Health: " << health << " \n\n";
      }

      else {
        health -= attack;

        if (health < 0)
          health = 0;

        cout << "You've been hit! ";
        cout << "Health: " << health << endl << endl;
      }

      turns++;
    }

    if (health > 0) {
      cout << "You have vanquished your foe. Collect your prize brave "
              "warrior.\n\n";
    }

    else {
      cout << "You have perished. A warrior, you are not.\n\n";
    }

    cout << "Press Y to play again. Press any other button to exit.\n";
    cin >> input;
    cout << endl << endl << endl;

  } while (input == "Y" || input == "y");
}