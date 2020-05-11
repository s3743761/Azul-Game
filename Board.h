#include<iostream>
#include<vector>
#include "Factory.h"
#include "Tiles.h"
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
void makeBoardOne();
void makeBoardTwo();
void printBoard();
const char** getBoard();
std::vector<std::vector<const char*>> getNewBoard();
//void addTileOnBoard(int val, Tiles *tile);
void addTileOnBoard(int val);
void printVectorBoard();
private:
int boardHeight = 5;
//Tiles* board[5][5];
//char* board_one[5][5];
//char* board_two[5][5];
const char* board[5][11];

//vector<vector<const char*>> board(vector<const char*>);
//std::vector<std::vector<const char*>> newBoard(5,std::vector<const char*> (11,0));
std::vector<std::vector<const char*>> newBoard = std::vector<std::vector<const char*>> (5,std::vector<const char*> (11,0));
//(5,std::vector<const char*> (11,0))
//Tiles* board2[5][5];




};