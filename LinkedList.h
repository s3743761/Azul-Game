#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"



class LinkedList {
public:

   LinkedList();
   ~LinkedList();


   void addNode(Tiles* a);
   Node* findNode(int f);
   void deleteNode(int i);
   void deleteBack();
   void deleteFront();
   void addBack(Tiles* data);
   void addFront(Tiles* data);
   void addAt(int i, Node* data);
   int returnSize();
   void removeElement(char tile);
   void printLine();
   std::string returnAsString();
   Tiles* getElement(LinkedList* factory,int i,Tiles* tile);
   void deleteAll();

NodePtr head;
 NodePtr current;
   NodePtr tail;
   int numOfNodes;

private:
   // NodePtr head;
   // NodePtr current;
   // NodePtr tail;
   // int numOfNodes;
};

#endif // ASSIGN2_LINKEDLIST_H
