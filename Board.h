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
void addTile(int row, char value, int count,vector<char> &bagLid);
void addTileOnSquareBoard(int val, char c);
void removeTileFromBoard(vector<char> &bagLid);
std::string returnTriangleAsString();
std::string returnWallAsString();
void loadBoard(std::vector<string> triangle, std::vector<std::string> wall);
int checkTilesHorizontally(int x);
int checkTilesVertically(int y);
int checkTotaltiles();

bool checkAdjacent(int i , int j);
void addBrokenTile(int count, int value, char tile,vector<char> &bagLid);
int getSize();
bool gameOver();
void placeTileGreyBoard(int i ,int j );
int getRows();
char getTile(int i);
int getColumns();
void loadBroken(string bagLidString);
vector<char> getBroken();
void printBroken();
string returnBrokenAsString();
void addFirstPlayerTile(vector<char> &bagLid);
void clearBroken(vector<char> &bagLid);


char** board;
private:
int rows;    
int columns;
// char** board;
char** mosaic;
int maxBrokenSize;
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