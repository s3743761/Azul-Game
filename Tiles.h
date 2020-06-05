#include <iostream>


#include <string>
#include <string.h>
#include "TileColour.h"
#include <vector>
#ifndef BLAH_H
#define BLAH_H

typedef char Colour;
//typedef string Colour;

class Tiles{
public:

Tiles(Colour colour);
Colour getColour();
std::string getTileDetails();
void setColour(Colour colour);
void printTileColour();

void printTile();
// std::string getIndexTiles(int i);
// int tileToIndex(std::string t);
// int tile_comp(std::string firstplayer,std::string DarkBlue);
// // Tiles* drawTiles(int num);
// bool isAllOneColour();
// // std::string getColour();
//  std::string getColorIgnoreWhite();


// void removeTilesOfColor(std::string c);
// std::vector<std::string> drawTiles(int num);
// void printAll();

 private:
 Colour colour;
//  Tiles* tiles;
};

#endif

