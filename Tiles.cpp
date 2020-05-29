#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Tiles.h"
#include <vector>

using namespace std;


Tiles::Tiles(Colour colour){
    this->colour = colour;
}

Colour Tiles::getColour(){
    return this->colour;
}

void Tiles::printTile(){
    cout<< colour;
}

string Tiles::getTileDetails(){
    return "colour";
}

void Tiles::setColour(Colour colour){
    this->colour = colour;
}



    







