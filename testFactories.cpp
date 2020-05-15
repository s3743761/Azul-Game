// #include <string>
// #include <string.h>
// #include <algorithm>
// #include <random>
// #include "LinkedList.h"
// #include "Tiles.h"
// // #include "Factory.h"

// #define numFactory 4

// using namespace std;

// int main(){
//     LinkedList* l1 = new LinkedList();
//     LinkedList* l2 = new LinkedList();
//     LinkedList* l3 = new LinkedList();
//     LinkedList* l4 = new LinkedList();
//     LinkedList* l5 = new LinkedList();
//     LinkedList* l6 = new LinkedList();

//     Tiles* t;
//     t = new Tiles(firstplayer);

//     LinkedList* factories[6] = {l1,l2,l3,l4,l5,l6};
//     for(int i=0; i<6; i++){
// //factories[i]->addBack(t);
// factories[i]->addNode(t);
//     }

// for(int i =0; i<6; i++){
//     //factories[i]->printLine();
// }
   
// }

// // LinkedList getList(LinkedList* factory[]){
// //    // LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
// //     for(int i = 0 ; i < 6; i++){
// //           return factory[i]->;
// //     }
// //     //return nullptr;
// //     return ;
     
// // }
// int getSize(LinkedList* factory[]){
//     //LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
//     for(int i = 0 ; i < 6;i++){
//       return factory[i]->returnSize();
//     }
//     return 0;
// }

// void print(LinkedList* factory[]){
//      // LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
//      for(int i = 0 ; i < 6;i++){
//          std::cout<<i<<": ";
//         factory[i]->printLine();
//      }
// }

// int random(int min, int max)
// {


//   std::random_device engine;
//   std::uniform_int_distribution<int> uniform_dist(min, max);

//   int randomNo = 0;
//   for (int i = 0; i != max; ++i)
//   {

//     randomNo = uniform_dist(engine);
//   }
//   return randomNo;
// }

// void Shuffle(LinkedList* factory[]){
//     //LinkedList* factory[6] = {l1,l2,l3,l4,l5,l6};
//     for(int i  = 0 ;  i < 4;++i){
//         int rand = random(0,3);
//         if(rand == 0){
//             factory[i]->addBack(factory[i]->findNode(rand)->getTile());
//              factory[i]->deleteFront();
//         }
//         else{
//             factory[i]->addBack( factory[i]->findNode(rand)->getTile());
//             factory[i]->deleteFront();
//         }
//     }
// }



#include<iostream>
#include "LinkedList.h"
#include "Factory.h"
#include "Tiles.h"
#include "Player.h"
using namespace std;

int main(){
Factory* f = new Factory();
f->fillFactory();
Player* player = new Player("Prabhav",0);
// player->fillHand(f);



}
    





