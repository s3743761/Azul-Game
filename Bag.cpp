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
}

void Bag::Shuffle()
{
    for (int i = 0; i < 100; ++i)
    {
        int rand = random(0, 100 - i);

        Node *n = tiles->findNode(rand);
        tiles->deleteNode(rand);
        tiles->addBack(n->getTile());
           
    }
}

Node *Bag::pickFromBag()
{
    Node *add = tiles->findNode(0);
    tiles->deleteFront();
    return add;
}

LinkedList *Bag::getList()
{
    return tiles;
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

void Bag::saveBag(std::string filename){
    ofstream of;

    of.open(filename, std::ios::app);
    of << "#TileBag" << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int i = 0; i < 6; i++)
        {
                for(int j=0; j<6; j++){
                of<<tiles->findNode(j)->getTile()->getColour();
                }
        }
        
    }
    of<<"\n";
    of.close();

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