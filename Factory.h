

#ifndef ASSIGN2_H
#define ASSIGN2_H

#include <iostream>
#include "LinkedList.h"
#include "Bag.h"



class Factory{ 
public:

Factory(int numberOfPlayers,int numberOfCentral);
void setTotalFactories(int numberOfPlayers, int numberofCentral);
int getTotalFactories();
void fillFactory(Bag* tileBag);

LinkedList* getList();
void addFactory(Factory *factory);
int getSize();
// void Shuffle();
void print();
std::string returnAsString();

// void getElementAtIndex(Factory *factory,int index,Tiles* tile);
void removeElement(int i,char colour);
int getNumberTiles(int index,char tile);
void loadFactory(std::vector<std::string> factoryStrings);
// void changeTiles(char tiles,int i);
void placeTileInZero(char tile,int central);
// void fillStatic();
void deleteAll(int i);
void addRemainingTiles(int index, char selectedColour,int central);
int getTotalSize();
bool firstPlayerTileExsists(int central);
void preetyPrint();
int getNumberoFactories();
// void staticFactory();
// void printStatic();

private:
// LinkedList* l1;
// LinkedList* l2;
// LinkedList* l3;
// LinkedList* l4;
// LinkedList* l5;
// LinkedList* l6;
// LinkedList* l7;
// LinkedList* factories;
// int num;
LinkedList** factory;
// LinkedList* Loadfactory[5];
// LinkedList* test[8];
int random(int min, int max);

// int numberPlayers;
int numberCentral;
int totalFactories;



};
#endif