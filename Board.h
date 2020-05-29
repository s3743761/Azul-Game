#include<iostream>
#include<vector>
#include "Factory.h"
#include "Player.h"

using namespace std;

#define EMPTY ' '
#define BLOCK '.'
#define AREA '|'
class Board{


public:
Board();
~Board();
void makeBoard();

void printBoard();
const char** getBoard();
// std::vector<std::vector<const char*>> getNewBoard();
// std::vector<const char*> copyBoard();
void addTileOnBoard(string val,string tile, string count);
int getEmptyRowSize(int val);
void addBrokenTile(int count, int value, char tile);
void printVectorBoard();
bool gameEnd();
bool isEmpty();
int roundEnd();
void addTileOnSquareBoard(int val, char c);
bool does_exist(const vector< vector<const char *> >&  v);
void addTile(int row,char value,int count);
bool checkIfBoardFilled();
int adjacent();
std::string returnTriangleAsString();
std::string returnWallAsString();
void saveBroken(string filename);
bool checkTile(int val, char tile);
void loadBoard(std::string* triangle, std::string* wall);
// void loadBoard2(string filename);
void removeTileFromBoard(vector<char> &bagLid);
std::fstream& GotoLine(std::fstream& file, unsigned int num);
void printLoadBoard();
void printLoadBoard2();
void setSize(int size);
int getSize();
int checkTilesHorizontally(int x);
int checkTilesVertically(int y);
int checkTotaltiles();
void sampleMosiac();
bool checkTileInMosiac(int row,char tile);
bool checkForSimilarTiles(int val);
void addPoints(Player* player,Board* board);
void saveLid(string fileName);
void placeTileAtLast();
void testfunc(char outStr);
std::vector<char> getLid();


private:

// Tiles* BLOCK;
// Tiles* AREA;
// Tiles* EMPTY;
int size;
char sample[5][5] = {{'B','Y','R','U','L'},
                    {'L','B','Y','R','U'},
                     {'U','L','B','Y','R'},
                     {'R','U','L','B','Y'},
                     {'Y','R','U','L','B'}};
char board[5][12];
string loadboard[5][11];
// string loadboard2[];
const Tiles* tileBoard[5][11];

std::vector<char> broken;
// std::vector<std::vector<const char*>> newBoard = std::vector<std::vector<const char*>> (5,std::vector<const char*> (11,0));


};