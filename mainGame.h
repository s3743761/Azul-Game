#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include <iostream>
#include "Board.h"




class mainGame {
public:
mainGame();
void playGame();
void setRow(int row);
void setColour(std::string colour);
void setCount(int count);
int getRow();
std::string getColour();
int getCount();
int getPlayerNum();
void setPlayerNum(int playerNumber);
void LoadGame(std::string filename);
void print(int r, std::string s,int p);





private:
int row;
std::string colour;
int count;
int playerNumber;



};

#endif 
