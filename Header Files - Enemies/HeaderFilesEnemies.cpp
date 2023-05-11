#include "enemy.h"
#include <cstdlib>
#include <ctime>
#include <fstream> //ifstream(into a file) and ofstream (out of a file)
#include <iostream>
#include <string>

using namespace std;

int main() {
  // ofstream file;
  // file.open("data.txt");
  // file << "Saving text in file.\n";
  
  // while (true) {
  //   cout << "What would you like to say?\n";
  //   string input;
  //   getline(cin, input);
  //   if (input == "quit")
  //     break;

  //   file << input << endl;
    
  // }

  // file.close();

  // cout << "done\n";

  // string line;
  // ifstream save("save.txt");

  // if(save.is_open()){
  //   while (getline(save, line)){
  //     cout << line << endl;
  //     //favGames[index++] = line;
  //   }
  // }
  
  // else{
  //   cout << "file could not be loaded\n";
  // }




  

  srand(time(0));

  enemy dale("Dale");

  cout << "\nWhat would you like to name Dale?\n";
  string input;
  cin >> input;
  dale.setName(input);
  cout << "\nDale is now known as " << dale.getName();

  cout << "\n\n\nEnemies hit by storm!?!?\n";
  cout << endl << dale.getName() << " loses 6 health.\n";
  dale.setHealth(-6);
  dale.status();

  cout << endl << endl << endl << dale.getName() << " gets a medkit for +5 health!\n";
  dale.setHealth(5);

  dale.status();
}