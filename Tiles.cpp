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
    if(colour == 'R'){
        cout<< ("\x1b[31mR\x1b[0m" );
    }
    cout<< colour;
}

void Tiles::printTileColour(){
    if(colour == 'R'){
        cout<< ("\x1b[31mR\x1b[0m" );
    }
    if(colour == 'B'){
        cout<< ("\x1b[34mB\x1b[0m" );
    }
    if(colour == 'L'){
        cout<< ("\x1b[96mL\x1b[0m" );
    }
    if(colour == 'U'){
        cout<< ("\x1b[35mU\x1b[0m" );
    }
    if(colour == 'Y'){
        cout<< ("\x1b[33mY\x1b[0m" );
    }
    if(colour == 'O'){
       cout << ("\x1b[31;1mO\x1b[0m");
    }
}

string Tiles::getTileDetails(){
    return "colour";
}

void Tiles::setColour(Colour colour){
    this->colour = colour;
}



    







