#include <ctime> //seeding random numbers
#include <iostream>
#include <stdlib.h> //for random numbers
using namespace std;

int health = 20;
int totalTreasure = 0;

void Story() {
  string playerName;
  cout << "Welcome to my dungeon." << endl;

}

bool AskYesNo(string question) {
  char input;
  cout << question;
  cin >> input;
  if (input == 'y') {
    return true;
  }

  else {
    return false;
  }
}

int RollDie(int sides = 6) {
  
  int roll;
  roll = rand() % sides + 1;
  return roll;
}

void Adventure() {
  int attack;
  int block;
  int treasure;
  
  cout << endl << "Health: " << health << endl << endl;
  srand(time(0));
  attack = RollDie(6);
  block = RollDie(6);
  treasure = RollDie(10);
  cout << "Enemy attack score: " << attack << endl;
  cout << "Your Block score: " << block << endl << endl;

  if (attack <= block) {
    cout << "Amazing block! " << endl << endl;
    cout << "Health: " << health << endl;
    totalTreasure = totalTreasure + treasure;
    cout << "You now have " << totalTreasure << " treasure!" << endl;
    return;
  }

  else {
    health -= attack;

    if (health <= 0){
      health = 0;
      return;
    }

    cout << "You've been hit! ";
    cout << "Health: " << health << endl << endl;
    cout << "You have " << totalTreasure << " treasure." << endl;
  }
}

void Ending() {
  if (health > 0) {
    cout << "\nHealth: " << health << endl;
    cout << "You leave victorious with " << totalTreasure << " treasure!";
  }
  else{
    cout << "You have perished. Your greed has cost you your life.";
  }
}

int main() {
  bool YesNo;
  Story();
  if (AskYesNo("Do you wish to enter my dungeon and risk your life? (y/n): ")) {
    do {
      cout << "\n----------------------------\n";
      Adventure();

      if (health <= 0){
        Ending();
        break;
      }
      
    } while (AskYesNo("Keep Going? (y/n): ") && health > 0);
    Ending();
  }

  else{
    cout << "Oh. Well . . . bye.";
  }
}