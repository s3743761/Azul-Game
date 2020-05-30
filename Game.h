#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include <iostream>
#include "Board.h"




class mainGame {
public:
mainGame();
void playGame();

void countpoints(Player* player1, Board* board1);

int getCount();
int getPlayerNum();
void setPlayerNum(int playerNumber);
void saveGame(std::string filename);
void LoadGame(std::string filename);
void help();
void addPlayer(Player *player);
void reFill(vector<char> tileLid, Bag* tileBag);






private:
int row;
std::string colour;
int count;
int playerNumber;
Factory* factory;
std::string player1Name;
int player1Scores;
std::string player2Name;
int player2Scores;
Bag* tileBag;
Board* board1;
Board* board2;
bool boardsLoaded;
Player** players;
Board** boards;
int length;
string playerName;
int playerScores;
vector<char> bagLid;


};

#endif 
