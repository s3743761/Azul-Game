

// #ifndef None
// #include "Tiles.h"
// #include <iostream>
// class Factory{
//     // Tiles* tiles =  new Tiles();
// public:
// int make_bag();
// void make_factory();
// void reset_factory();

// private:
// Tiles* tiles;
// // int num;

// //     int total = sizeof(tiles->getIndexTiles(0))*20 + sizeof(tiles->getIndexTiles(1))*20 + sizeof(tiles->getIndexTiles(2))*20 +  
// //     sizeof(tiles->getIndexTiles(3))*20 + sizeof(tiles->getIndexTiles(4))*20 + sizeof(tiles->getIndexTiles(5))*20 + sizeof(tiles->getIndexTiles(6))*20 ;
// //     random_shuffle(total,total);
// //     return total;
    
// // }




// };
// #endif

#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H

#include <iostream>
#include "LinkedList.h"
#include "Bag.h"
#include "Tiles.h"

//typedef char* a;
// #define a "B"
// #define b "L"
// #define c "U"
// #define d "Y"
// #define e "R"
// #define f "."
// #define player "F"

class Factory{ 
public:

Factory();
void fillFactory();

LinkedList* getList();
void addFactory(Factory *factory);
int getSize();
void Shuffle();
void print();

void getElementAtIndex(Factory *factory,int index,Tiles* tile);
void removeElement(int i,std::string colour);

int getNumberTiles(int index,char* colour);

private:
LinkedList* l1;
LinkedList* l2;
LinkedList* l3;
LinkedList* l4;
LinkedList* l5;
LinkedList* l6;
// LinkedList* factories;
int num;
 LinkedList* factory[5];
 int random(int min, int max);



};
#endif