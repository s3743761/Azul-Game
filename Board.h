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
Board(bool sixTileMode);
~Board();

void makeBoard();
void printBoard();
int getEmptyRowSize(int row);
bool checkTileInMosiac(int row, char tile);
///// 
void placeTileAtLast();
void addTile(int row, char value, int count);
void addTileOnSquareBoard(int val, char c);
void removeTileFromBoard(vector<char> &bagLid);
std::string returnTriangleAsString();
std::string returnWallAsString();
void loadBoard(std::string* triangle, std::string* wall);
int checkTilesHorizontally(int x);
int checkTilesVertically(int y);
int checkTotaltiles();
bool gameOver();

void addBrokenTile(int count, int value, char tile);
int getSize();



private:
int rows;    
int columns;
char** board;
char** mosaic;
char fiveTileMosaic[5][5] = {
    {'B','Y','R','U','L'},
    {'L','B','Y','R','U'},
    {'U','L','B','Y','R'},
    {'R','U','L','B','Y'},
    {'Y','R','U','L','B'}
};

char sixTileMosaic[6][6] = {
    {'B','Y','R','U','L','O'},
    {'O','B','Y','R','U','L'},
    {'L','O','B','Y','R','U'},
    {'U','L','O','B','Y','R'},
    {'R','U','L','O','B','Y'},
    {'Y','R','U','L','O','B'}
};

std::vector<char> broken;

};