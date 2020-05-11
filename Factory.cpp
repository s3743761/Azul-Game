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
#include <string.h>
#include <algorithm>
// #include "Tiles.h"
#include "Factory.h"

#define numFactory 4

using namespace std;


Factory::Factory(){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
    // LinkedList* factory[5] = {l1,l2,l3,l4,l5};

  
   


}


void Factory::fillFactory(){
    l1 = new LinkedList();
    l2 = new LinkedList();
    l3 = new LinkedList();
    l4 = new LinkedList();
    l5 = new LinkedList();
    l6 = new LinkedList();
   // Tiles* t1 = new Tiles('F');
    Tiles* t2 = new Tiles('B');
    Tiles* t3 = new Tiles('L');
    Tiles* t4 = new Tiles('U');
    Tiles* t5 = new Tiles('Y');
    Tiles* t6 = new Tiles('R');
    Tiles* t7 = new Tiles('.');
    //Tiles* tileArray[7] = {t1,t2,t3,t4,t5,t6,t7};
    std::vector<Tiles*> tileVector = {t2,t3,t4,t5,t6,t7};
  
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
     //factory[0]->deleteFront();
   // factory[0]->addFront(new Tiles('F')) ;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
    // for(int i = 0 ; i < 5;i++){
    //     if(factory[i] != nullptr){
           // t = new Tiles(firstplayer);
           
           std::random_shuffle(tileVector.begin(),tileVector.end());
         // std::shuffle(tileVector.begin(), tileVector.end());
            factory[i]->addNode(tileVector[j]);
        
            // t = new Tiles(Red);
            // factory[j]->addNode(t);
            // t = new Tiles(Yellow);
            // factory[j]->addNode(t);
            // factory[j]->addNode(t);
            // t = new Tiles(DarkBlue);
            // factory[j]->addNode(t);
            // t = new Tiles(LightBlue);
            // factory[j]->addNode(t);
            // t = new Tiles(Black);
            // factory[j]->addNode(t);
        
            // std::cout<< factory[2]<<endl;
            
        }
    }
    factory[0]->deleteFront();
    factory[0]->addFront(new Tiles('F')) ;
    
   // return *factory;

}

LinkedList *Factory::getList(){
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    for(int i = 0 ; i < 6; i++){
          return factory[i];
    }
    return nullptr;
     
}
int Factory::getSize(){
    LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    for(int i = 0 ; i < 6;i++){
      return factory[i]->returnSize();
    }
    return 0;
}

void Factory::print(){
      LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
     for(int i = 0 ; i < 6;i++){
         std::cout<<i<<": ";
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

// Tile* Factory::getTile(){
//     factory[6] = {l1,l2,l3,l4,l5,l6};
// return 
// }

void Factory::Shuffle(){
     LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    for(int i  = 0 ;  i < 4;++i){
        int rand = random(0,3);
        if(rand == 0){
            factory[i]->addBack(factory[i]->findNode(rand)->getTile());
             factory[i]->deleteFront();
        }
        else{
            factory[i]->addBack( factory[i]->findNode(rand)->getTile());
            factory[i]->deleteFront();
        }
    }
}

//  Factory::getTile(int val){
//      factory[6] = factory[l1,l2,l3,l4,l5];
//     for(int i=0; i<6; i++){
//         for(int j=0; j<11; j++){
//             if(val==i){
//                 return factory[i];
//             }
//         }
//     }
// }


void Factory::getElementAtIndex(Factory *f,int index){
   LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
    // for(int i=0; i<6; i++){
    //    if(index==i){
    //     //TODO

    //    }
    // }
   // factory->(f->getList(),index);
//    for(int i=0; i<6; i++){
//        if(index==i){
//   // return factory[i]->getElement(f->getList(),index);
//   factory[i]->getElement(f->getList(),index);
//        }
//    }
//    return nullptr;
factory[index]->getElement(f->getList(),index);
}


// Tiles* Factory::getTiles(){
//     LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
//     for(int i=0; i<6; i++){
//         factory[i]->
//     }
// }


