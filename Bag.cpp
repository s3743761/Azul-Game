#include "Bag.h"
#include <random>

Bag::Bag()
{
    tiles = new LinkedList();
}

void Bag::fillBag()
{
    tiles = new LinkedList();

    Tiles *t;

    for (int i = 0; i < 3; i++)
    {
        for (int i = 1; i <= 6; i++)
        {

            t = new Tiles(firstplayer);
            tiles->addNode(t);

            t = new Tiles(Red);
            tiles->addNode(t);

            t = new Tiles(Yellow);
            tiles->addNode(t);

            t = new Tiles(DarkBlue);
            tiles->addNode(t);

            t = new Tiles(LightBlue);
            tiles->addNode(t);

            t = new Tiles(Black);
            tiles->addNode(t);
        }
    }
}

void Bag::Shuffle()
{
    for (int i = 0; i < 108; ++i)
    {
        int rand = random(0, 107);
        if (rand == 0)
        {
            tiles->addBack(tiles->findNode(rand)->getTile());
            tiles->deleteFront();
        }
        else
        {
            tiles->addBack(tiles->findNode(rand)->getTile());
            tiles->deleteFront();
        }
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