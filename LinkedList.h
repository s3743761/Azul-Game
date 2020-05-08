#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"


class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   //only adds node at the end
   void addNode(Tiles* a);
   //find the Node
   Node* findNode(int f);
   //only deletes node of where it is
   void deleteNode(int i);
   void deleteBack();
   void deleteFront();
   void addBack(Tiles* data);
   void addFront(Tiles* data);
   void addAt(int i, Node* data);
   int returnSize();
   void swapNodes(int from, int to);

   void printLine();



private:
   NodePtr head;
   NodePtr current;
   NodePtr tail;
   int numOfNodes;
};

#endif // ASSIGN2_LINKEDLIST_H
