#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Factory.h"


using namespace std;

class Player
{
public:

Player(string name, int points);
string getName();
void setName(string name);
int getPoints();
void setPoints(int points);
int tilesinhand();
LinkedList returnlist();
void fillHand(Factory* factory);


 private:
 string name;
 int points;
 LinkedList * list = new LinkedList();
};