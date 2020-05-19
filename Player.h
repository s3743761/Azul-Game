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
void winner(Player* player1,Player* player2);
void updatePoints(int val);
void savePlayer(string filename);
std::fstream& GotoLine(std::fstream& file, unsigned int num);
void loPoints1(string filename);
void loPoints2(string filename);
void setloadPoints1(int loadPoints1);
void setloadPoints2(int loadPoints2);
int getLoadPoints1();
int getLoadPoints2();


private:

string name;
int points;
int loadPoints1;
int loadPoints2;

 LinkedList * list = new LinkedList();
};