#include <iostream>
#include <fstream> //ifstream(into a file) and ofstream (out of a file)
#include <string>
using namespace std;

string favGames[100];
int index = 0;
string input;


void add(){
  cout << "type 'quit' to finish adding games.\n";

  while(true){
        
    getline(cin, input);
    if(input == "quit"){
      break;
    }

    else{
      favGames[index] = input;
      index++;
    }
        
  }
}

void show(){
  cout << "Here are your favorite games:\n";
  for (int i = 0; i < index; i++) {
    if(favGames[i] == ""){
      continue;
    }
    cout << favGames[i] << endl;
  }
}

void edit(){
  cout << "\nWhat game would you like to edit?\n";
  cin.ignore();
  getline(cin, input);
      
  for(int i = 0; i < index; i++){
    if(input == favGames[i]){
      cout << "Found it.\n";
      cout << "What would you like to change this too?\n";
      cin.ignore();
      getline(cin, input);
      favGames[i] = input;
    }
  }
}

void remove(){
  cout << "What game would you like to remove?\n";
  cin.ignore();
  getline(cin, input);
  for(int i = 0; i < index; i++){
    if(input == favGames[i]){
      favGames[i] = "";
      cout << "The game was removed.";
    }
  }  
}

void load(){
  ifstream file;
  string line;
  int num = 0;
  file.open("games.txt");
  //file << "Saving games in a file.\n";
  while(getline(file, line)){
    favGames[num] = line;
    cout << favGames[num];
    num++;
  }
  index = num;
  // file << input << endl;
    
}

void save(){
  //for loop to write array lines to file
  // file << favGames[i] << endl;
  //int index = 0;
  ofstream save("games.txt");
  if(save.is_open()){
    for(int i = 0; i < index; i++){
      save << favGames[i] << endl;
    }
  }  
}

int main() {
  cout << "Loading list of favorite games.\n";
  load();
  while (true) {
    cout << endl;
    cout << "What would you like to do?\n\n";
    cout << "Type 'quit' to quit. \n";
    cout << "Type 'add' to add games. \n";
    cout << "Type 'show' to show the array of games.\n";
    cout << "Type 'edit' to find and edit an entry.\n";
    cout << "Type 'remove' to remove an entry.\n";
    
    cin >> input;

    if (input == "quit") {
      cout << "Thanks for playing.\n";
      break;
    }

    if (input == "add") {
      add();
    }
 
    if (input == "show") {
      show();
    }
    
    if(input == "edit"){
      edit();
    }
    
    if(input == "remove"){
      remove();
    }
  }

  cout << "Saving favorite games.\n";
  save();
}
