
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
Node* pickFromBag();
LinkedList* getList();
int getSize();

private:
LinkedList* tiles;
int random(int min, int max);
};

#endif