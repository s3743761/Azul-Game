
#include<iostream>
#include<vector>
#include "Board.h"
using namespace std;

int main(){

Board* board = new Board();

std::cout<<std::endl;
board->makeBoardOne();
board->printBoard();
board->addTile(4-1,"R",2);
board->addTile(3-1,"L",2);
board->addTile(2-1,"U",3);
// board->addTile(2,"B",2);



// board->addTileOnBoard(2,"R",2);
// board->printBoard();






}
