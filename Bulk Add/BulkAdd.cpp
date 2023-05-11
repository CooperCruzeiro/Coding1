#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0)); // seeding random number generator
  int count = 0;
  int randMat[10][10];

  string favGames[100];

  int index = 0;

  while (true) {
    cout << endl;
    cout << "What would you like to do?\n\n";
    cout << "Type 'quit' to quit. \n";
    cout << "Type 'add' to add. \n";
    cout << "Type 'bulkadd' to add multiple games.\n";
    cout << "Type 'show' to show the array of games.\n";
    cout << "Type 'edit' to edit the last entry.\n";
    cout << "Type 'find' to find and replace and entry.\n\n";
    string input;
    cin >> input;

    if (input == "quit") {
      cout << "Thanks for playing.\n";
      break;
    }

    if (input == "add") {
      cout << "What game would you like to add?\n";
      cin >> input;
      favGames[index] = input;
      index++;
    }

    
    if(input == "bulkadd") {
      cout << "type 'quit' to finish adding games.\n";

      while(true){
        
        cin >> input;
        if(input == "quit"){
          break;
        }

        else{
          favGames[index] = input;
          index++;
        }
        
      }
    }

    
    if (input == "show") {
      cout << "Here are your favorite games:\n";
      for (int i = 0; i < index; i++) {
        cout << favGames[i] << endl;
      }
    }
    
    if( input == "edit"){
      cout << "Re-enter the last Game\n";
      cin >> input;
      favGames[index - 1] = input;
    }
    
    if( input == "find"){
      cout << "What game would you like to edit?\n";
      cin >> input;
      
      for(int i = 0; i < index; i++){
        if(input == favGames[i]){
          cout << "Found it.\n";
          cout << "What would you like to change this too?\n";
          cin >> input;
          favGames[i] = input;
        }
      }
    }
  }
}
