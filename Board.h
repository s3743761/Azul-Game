#include<iostream>
#include<vector>
#include "Factory.h"
#include "Tiles.h"

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

private:
int boardHeight = 5;
//Tiles* board[5][5];
//char* board_one[5][5];
//char* board_two[5][5];
const char* board[5][11];

//Tiles* board2[5][5];



};