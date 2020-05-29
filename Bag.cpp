#include "Bag.h"
#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <fstream>
using std::ofstream;


Bag::Bag()
{
    tiles = new LinkedList();
}

void Bag::fillBag()
{
    tiles = new LinkedList();

    Tiles *t;
    for(int i = 0; i < 20; i++) {
        t = new Tiles(Red);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(Yellow);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(DarkBlue);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(LightBlue);
        tiles->addNode(t);
    }

    for(int i = 0; i < 20; i++) {
        t = new Tiles(Black);
        tiles->addNode(t);
    }

    if(this->sixTileMode) {
        for(int i = 0; i < 20; i++) {
            t = new Tiles(Orange);
            tiles->addNode(t);
        }
    }
}

void Bag::Shuffle()
{
    int totalTiles = this->sixTileMode ? 120 : 100;
    for (int i = 0; i < totalTiles; ++i)
    {
        int rand = random(0, totalTiles - i);

        Node *n = tiles->findNode(rand);
        tiles->deleteNode(rand);
        tiles->addBack(n->getTile());
           
    }
}

LinkedList *Bag::getList()
{
    return tiles;
}
void Bag::setSixTileMode(bool mode){
    
    this->sixTileMode = mode;

}

int Bag::getSize()
{
    return tiles->returnSize();
}

int Bag::random(int min, int max)
{

    std::random_device engine;
    std::uniform_int_distribution<int> uniform_dist(min, max);

    int randomNo = 0;
    for (int i = 0; i != max; ++i)
    {

        randomNo = uniform_dist(engine);
    }
    return randomNo;
}


std::string Bag::returnAsString() {

    std::string bagString = ""; 

    for(int i = 0; i < getSize(); i++) {
        bagString += getList()->findNode(i)->getTile()->getColour();
    }
    
    if(bagString.length() == 0){
        return "_";
    }
    return bagString;
}