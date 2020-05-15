// #include <random>
// #include <string>
// #include <string.h>
// #include <algorithm>
// #include "Tiles.h"
// #include "Factory.h"
// using namespace std;

// #define Size 4

// // Tiles* tiles =  new Tiles();

// int Factory::make_bag(){
//     int total = sizeof(tiles->getIndexTiles(0))*20 + sizeof(tiles->getIndexTiles(1))*20 + sizeof(tiles->getIndexTiles(2))*20 +
//     sizeof(tiles->getIndexTiles(3))*20 + sizeof(tiles->getIndexTiles(4))*20 + sizeof(tiles->getIndexTiles(5))*20 + sizeof(tiles->getIndexTiles(6))*20 ;

//     int r =total %  rand();

//     // random_shuffle(total,total);
//     // shuffle(tiles->getIndexTiles(0),tiles->getIndexTiles(6),std::default_random_engine(total));
//     return r;
// }

#include <random>
#include <string>
//#include <string>
#include <algorithm>
// #include "Tiles.h"
#include "Factory.h"
#include <chrono>

#define numFactory 4

using namespace std;

Factory::Factory()
{
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    
}

void Factory::fillFactory()
{
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
   

    Tiles *t2 = new Tiles(DarkBlue);
    Tiles *t3 = new Tiles(LightBlue);
    Tiles *t4 = new Tiles(Black);
    Tiles *t5 = new Tiles(Yellow);
    Tiles *t6 = new Tiles(Red);
    Tiles *t7 = new Tiles(notile);
    
    std::vector<Tiles *> tileVector = {t2, t3, t4, t5, t6, t7};

    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
   
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
  

            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

            std::shuffle(tileVector.begin(), tileVector.end(), std::default_random_engine(seed));
            factory[i]->addNode(tileVector[j]);

           
        }
    }
    
    factory[0]->deleteFront();
    factory[0]->addFront(new Tiles(firstplayer));

  
}

LinkedList *Factory::getList()
{
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    for (int i = 0; i < 6; i++)
    {
        return factory[i];
    }
    return nullptr;
}

int Factory::getNumberTiles(int index,char* p )
{
    int count =0;
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    if(factory[index]!=nullptr){
        for(int i=0; i<factory[index]->returnSize();i++){
            if(strcmp(factory[index]->findNode(i)->getTile()->getColour(),p)==0){
                
                count+=1;

            }

        }
    }
    return count;
}

int Factory::getSize()
{
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    for (int i = 0; i < 6; i++)
    {
        return factory[i]->returnSize();
    }
    return 0;
}

void Factory::print()
{
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    for (int i = 0; i < 6; i++)
    {
        std::cout << i << ": ";
        factory[i]->printLine();
    }
}

int Factory::random(int min, int max)
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


void Factory::Shuffle()
{
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    for (int i = 0; i < 4; ++i)
    {
        int rand = random(0, 3);
        if (rand == 0)
        {
            factory[i]->addBack(factory[i]->findNode(rand)->getTile());
            factory[i]->deleteFront();
        }
        else
        {
            factory[i]->addBack(factory[i]->findNode(rand)->getTile());
            factory[i]->deleteFront();
        }
    }
}




void Factory::getElementAtIndex(Factory *fact, int index,Tiles* tile)
{
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};

    factory[index]->getElement(fact->getList(), index,tile);
}



void Factory::removeElement(int i,std::string colour){
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    
    if(factory[i] != nullptr){
        factory[i]->removeElement(colour);
    }

}
