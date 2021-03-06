#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include <iostream>
#include "Board.h"

class mainGame {
public:
mainGame();
void playGame();

void countpoints(Player* player1, Board* board1);


void saveGame(std::string filename);
void LoadGame(std::string filename);
void help();
void addPlayer(Player *player, Board* board);
void reFill(vector<char> tileLid, Bag* tileBag);
string returnLidAsString();
void askForPlayers();
void askForCentralFactories();
void askForGameMode();
int setPlayerOrderForRound();
void playTurn(int factoryIndex, char colour, int row, int centralFactoryIndex, Player* currentPlayer, Board* currentBoard);
void askForGreyBoardInput();
void printBoardAllign();
void printPlayers(Player *currentPlayer);
void printBroken(bool sixTileMode);
void printScores();

private:
Bag* tileBag;
vector<char> bagLid;

Factory* factory;
Player** players;
Player** orderPlayers;
Board** boards;
Board** orderBoards;
int turnPlayerID;
bool playerOrderSet;
string playerOrder;
int numberOfPlayers;
int length;
int numCentralFactories;
bool sixTileMode;
bool greyBoardMode;
bool gameLoadedFromFile;

};

#endif 
