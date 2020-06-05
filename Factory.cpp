#include <random>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include "Factory.h"
#include <chrono>
#include <iostream>
#include <sstream>

#define numFactory 4

using namespace std;

Factory::Factory(int numberOfPlayers, int numberofCentral)
{
    // this->numberPlayers = numberOfPlayers;
    this->numberCentral = numberofCentral;
    setTotalFactories(numberOfPlayers, numberofCentral);
    
    factory = new LinkedList*[totalFactories];

    for(int i = 0; i < totalFactories ; i++) {
        factory[i] = new LinkedList();
    }

}

void Factory::setTotalFactories(int numberOfPlayers, int numberofCentral) {

    if(numberOfPlayers == 2){
        totalFactories = 5;
    }
    else if(numberOfPlayers == 3){
        totalFactories = 7;
    }
    else{
        totalFactories = 9;
    }

    if(numberofCentral == 1){
        totalFactories += 1;
    }
    else{
        totalFactories += 2;
    }
}

int Factory::getTotalFactories() {
    return totalFactories;
}

// fills factory from Tile Bag
void Factory::fillFactory(Bag* tileBag){
    
    factory[0]->addNode(new Tiles(firstplayer));
    
    Tiles* t = nullptr;
   
    for(int i = this->numberCentral; i < totalFactories; i++){
        for(int j = 0; j < 4; j++){
            
            if(tileBag->getList()->findNode(0) != nullptr){
                char tile = tileBag->getList()->findNode(0)->getTile()->getColour();
                tileBag->getList()->deleteNode(0);
                
                if(tile == 'R'){
                    t = new Tiles(Red);
                }
                else if(tile == 'B'){
                    t = new Tiles(DarkBlue);
                }
                else if(tile == 'Y'){
                    t = new Tiles(Yellow);
                }
                else if(tile == 'U'){
                    t = new Tiles(Black);
                }
                else if(tile == 'L'){
                    t = new Tiles(LightBlue);
                }
                else if(tile == 'O'){
                    t = new Tiles(Orange);
                }
                else if(tile == 'F'){
                    t = new Tiles(firstplayer);
                }
                factory[i]->addNode(t);
            }
            
            
        }
    }

}


LinkedList *Factory::getList()
{
    for (int i = 0; i < totalFactories; i++)
    {
        return factory[i];
    }
    return nullptr;
}

void Factory::placeTileInZero(char tile, int central){
  
    if(tile == 'U'){
        factory[central]->addNode(new Tiles(Black));
    }
    else if(tile == 'R'){
        factory[central]->addNode(new Tiles(Red));
    }
    else if(tile == 'B'){
        factory[central]->addNode(new Tiles(DarkBlue));
    }
    else if(tile == 'L'){
        factory[central]->addNode(new Tiles(LightBlue));
    }
    else if(tile == 'Y'){
        factory[central]->addNode(new Tiles(Yellow));
    }
   
}
void Factory::addRemainingTiles(int index, char selectedColour,int central){
   
    for(int i = 0; i < factory[index]->returnSize(); i++){
        char tileColour = factory[index]->findNode(i)->getTile()->getColour(); 
        if(tileColour != selectedColour) {
            placeTileInZero(tileColour,central);
        }
    }

    factory[index]->deleteAll();

}

int Factory::getNumberTiles(int index, char tile){
   
    int count = 0;

    
    for(int i = 0; i < factory[index]->returnSize(); i++){
        if(factory[index]->findNode(i)->getTile()->getColour() == tile) {
            count++;
        }

    }
    return count;

}

// void Factory::changeTiles(char tiles,int i){
//     int count = getNumberTiles(i,tiles);
//     int newCount = 0;
  
//     if(factory[i]!=nullptr){
//         for(int p=0; p<factory[i]->returnSize();p++){
//             if(factory[i]->findNode(p)->getTile()->getColour() == tiles && newCount < count ){
//                     factory[i]->findNode(p)->getTile()->setColour(notile);
//                     newCount++;
//             }
//         }
//     }
// }

bool Factory::firstPlayerTileExsists(int central){
    Node* node = factory[central]->findNode(0);
    if(node != nullptr && node->getTile()->getColour() == 'F'){
        return true;
    }
    
    return false;

}


// int Factory::getSize()
// {
   
//     for (int i = 0; i < totalFactories; i++)
//     {
//         return factory[i]->returnSize();
//     }
//     return 0;
// }

void Factory::print()
{
    for (int p = 0; p < totalFactories; p++)
    {
    
        std::cout << p << ": ";
        factory[p]->printLine();
    }
    
}


std::string Factory::returnAsString() {

    // LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    std::string factoryString = "";      
    for (int p = 0; p < totalFactories; p++)
    {

        // factoryString += to_string(p) + ": ";
        factoryString += factory[p]->returnAsString();
    }
    return factoryString;
}


void Factory::removeElement(int i, char colour){
   
   factory[i]->removeElement(colour);
}

void Factory::deleteAll(int i){
    
    factory[i]->deleteAll();
    
}

void Factory::loadFactory(std::vector<std::string> factoryStrings){
   
    Tiles* t;

    for (auto i = factoryStrings.begin(); i != factoryStrings.end(); ++i) {
    // for (std::vector<string>::const_iterator i = factoryStrings.begin(); i != factoryStrings.end(); ++i){
        std::string line = *i;
        int index = std::distance(factoryStrings.begin(), i);

        for(int j = 0; j < line.length(); j++) {
            char tile = line.at(j);
            if(tile == 'F') {
                t = new Tiles(firstplayer);
                factory[index]->addNode(t);
            }

            else if(tile == 'R'){
                t = new Tiles(Red);
                factory[index]->addNode(t);
            }
            else if(tile == 'B'){
                t = new Tiles(DarkBlue);
                factory[index]->addNode(t);
            }
            else if(tile == 'Y'){
                t = new Tiles(Yellow);
                factory[index]->addNode(t);
            }
            else if(tile == 'U'){
                t = new Tiles(Black);
                factory[index]->addNode(t);
            }
            else if(tile == 'L'){
                t = new Tiles(LightBlue);
                factory[index]->addNode(t);
            }
            else if(tile == 'O'){
                t = new Tiles(Orange);
                factory[index]->addNode(t);
            }
            
        }
    }

    // for(int i = 0; i < 6; i++) {
    //     std::string line = factoryStrings[i];
    //     for(int j = 0; j < line.length(); j++) {
    //         char tile = line.at(j);
    //         if(tile == 'F') {
    //             t = new Tiles(firstplayer);
    //             factory[i]->addNode(t);
    //         }

    //         else if(tile == 'R'){
    //             t = new Tiles(Red);
    //             factory[i]->addNode(t);
    //         }
    //         else if(tile == 'B'){
    //             t = new Tiles(DarkBlue);
    //             factory[i]->addNode(t);
    //         }
    //         else if(tile == 'Y'){
    //             t = new Tiles(Yellow);
    //             factory[i]->addNode(t);
    //         }
    //         else if(tile == 'U'){
    //             t = new Tiles(Black);
    //             factory[i]->addNode(t);
    //         }
    //         else if(tile == 'L'){
    //             t = new Tiles(LightBlue);
    //             factory[i]->addNode(t);
    //         }
            
    //     }
    // }

}


int Factory::getTotalSize(){
    
    int totalSize = 0;
    for(int i = 0 ; i < totalFactories; i++){
        if(factory[i] != NULL){
            totalSize += factory[i]->returnSize();
        }
       
    }
   
    return totalSize;
}

// void Factory::staticFactory(){
//     test[0]->addNode(new Tiles(LightBlue));
//     test[0]->addNode(new Tiles(LightBlue));

//     test[1]->addNode(new Tiles(DarkBlue));


    
// }

// void Factory::printStatic(){
//     for(int i = 0 ; i < 8 ; i++){
//         std::cout << i << ": ";
//         test[i]->printLine();
//     }

// }

int Factory::getNumberoFactories(){
    return totalFactories;
}