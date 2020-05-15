#include<iostream>
#include<vector>
#include "Factory.h"

using namespace std;

#define BOARD_HEIGHT 5;
#define BOARD_WIDTH 5;
#define EMPTY " "
#define BLOCK "."
#define AREA "||"
class Board{


public:
Board();
~Board();
void makeBoard();

void printBoard();
const char** getBoard();
std::vector<std::vector<const char*>> getNewBoard();
std::vector<const char*> copyBoard();
//void addTileOnBoard(int val, Tiles *tile);
void addTileOnBoard(int val,string tile, int count);
//void addTileOnBoard(int val,Colour tile);
int getEmptyRowSize(int val);
void addBrokenTile(int count, int value, std::string tile);
void printVectorBoard();
bool gameEnd();
bool isEmpty();
bool does_exist(const vector< vector<const char *> >&  v);
void addTile(int row,string value,int count);
private:

// Tiles* BLOCK;
// Tiles* AREA;
// Tiles* EMPTY;


const char *board[5][11] ;

const Tiles* tileBoard[5][11];
//vector<vector<const char*>> board(vector<const char*>);
//std::vector<std::vector<const char*>> newBoard(5,std::vector<const char*> (11,0));
std::vector<std::vector<const char*>> newBoard = std::vector<std::vector<const char*>> (5,std::vector<const char*> (11,0));
//(5,std::vector<const char*> (11,0))
//Tiles* board2[5][5];




};