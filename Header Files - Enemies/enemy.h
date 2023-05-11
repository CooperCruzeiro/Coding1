#include <string>
using std::string;


class enemy{
private:
  string name;
  int health;
  int damage;

public:
  enemy(string givenName = "Mr. Baddie");

  void status();

  int getHealth();
  void setHealth(int by);

  void setName(string newName);
  string getName();
};