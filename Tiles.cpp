#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Tiles.h"
#include <vector>

using namespace std;


// #define firstplayer "F"
// #define DarkBlue "B"
// #define LightBlue "L"
// #define Black "U"
// #define Yellow "Y" 
// #define Red "R"
// #define notile "."
// std::map<Colour,string> colour;

// string col[] = {firstplayer,Red,Yellow,DarkBlue,LightBlue};
// std::vector<string> colour(col,col + sizeof(col)/sizeof(string));

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


    







