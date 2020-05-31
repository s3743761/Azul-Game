
#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H

#include <cstdlib>
#include "LinkedList.h"
#include "Tiles.h"

class Bag{
public:
Bag();

void fillBag();
void Shuffle();
LinkedList* getList();
int getSize();
int random(int min, int max);
void removeFromBag(Tiles* tile);
void load(std::string tilesString);
std::string returnAsString();
void setSixTileMode(bool mode);


private:
LinkedList* tiles;
bool sixTileMode;

};

#endif