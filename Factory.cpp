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
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include "Factory.h"
#include <chrono>
#include <iostream>

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

int Factory::getNumberTiles(int index,string tile )
{
    int count =0;
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    if(factory[index]!=nullptr){
        for(int i=0; i<factory[index]->returnSize();i++){
             if(factory[index]->findNode(i)->getTile()->getColour()==tile){
                count+=1;
            }

        }
    }
    return count;
}

void Factory::changeTiles(std::string tiles,int i){
    int count = getNumberTiles(i,tiles);
    int newCount = 0;
    // Tiles *t7 = new Tiles(notile);
     LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    if(factory[i]!=nullptr){
        for(int p=0; p<factory[i]->returnSize();p++){
            if(factory[i]->findNode(p)->getTile()->getColour() == tiles && newCount < count ){
                    factory[i]->findNode(p)->getTile()->setColour(notile);
                    newCount++;
            }
           
                

            
            

        }
    }
    

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
    // for (int p = 0 ; p < 6;p++){
    //     if(i == p){
    //         if(factory[i] != nullptr && factory[i]->returnSize() >=4){
    //             factory[i]->removeElement(i,colour);
    //         }
    //     }
    // }
    if(factory[i] != nullptr){
        factory[i]->removeElement(colour);
    
    }
   
}

void Factory::saveFactory(std::string filename){
    LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    ofstream of;
    int count =0;
    of.open(filename,ios::app|ios::out);
    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            Node* temp = factory[i]->findNode(j);

        if(!of){
            // cout<<"Error"<<endl;; 
        }
        
        else{
            while(temp!=NULL && count<getNumberTiles(0,factory[0]->findNode(0)->getTile()->getColour())){
                for(int l=0; l<6; l++){
                    of<<l<<": ";  
                    for(int k=0; k<4; k++){    
                        of<<factory[l]->findNode(k)->getTile()->getColour()<<" ";
                    }
                
                    of<<endl;
                }
                count+=1;
            }

        }
    
        of.close();
        }
    }
}

void Factory::loadFactory(std::string filename){

    string line;
    ifstream myFile(filename);
    // LinkedList *factory[6] = {l1, l2, l3, l4, l5, l6};
    if (myFile.is_open())
    {
   
        for (int lineno = 0; getline(myFile,line) && lineno < 7; lineno++){

            if (lineno < 6){
               cout<<line<<endl;
            }
        }
    

    }

}


