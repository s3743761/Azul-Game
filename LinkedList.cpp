
#include "LinkedList.h"
#include "Factory.h"
LinkedList::LinkedList() : head(nullptr),
                           current(nullptr),
                           tail(nullptr)

{
  numOfNodes = 0;
}

LinkedList::~LinkedList()
{
}

void LinkedList::addNode(Tiles *tile)
{
  NodePtr node = new Node(tile, nullptr);
  /* checks if the list is already empty
     * then go through the list, using next to
     * point to the next node
     * else, if empty, make the head the node
     */
  if (head != nullptr)
  {
    tail->setNext(node);
    tail = node;
    numOfNodes++;
  }
  else if (head == nullptr)
  {
    head = node;
    tail = node;
    numOfNodes++;
  }
  else if (head == tail)
  {
    tail->setNext(node);
    tail = node;
    head->setNext(tail);
    numOfNodes++;
  }
} //end of addNode

// Node LinkedList::getNode(LinkedList* f,int i){
//   Node* newNode = new Node(f->,nullptr);

// }

/* find node for the random int to pull out */
Node *LinkedList::findNode(int index)
{
  Node *temp = head;

  for (int count = 1; count <= index; count++)
  {

    temp = temp->getNext();
  }
  return temp;
}

void LinkedList::addAt(int i, Node *node)
{
  if (i > 0 && i < numOfNodes)
  { /* find the node  
    and then set the pointers according 
    */
    Node *ka = findNode(i);
    findNode(i - 1)->setNext(node);
    findNode(i - 1)->getNext()->setNext(ka);
    numOfNodes++;
  }
  else if (i == 0 && head != nullptr)
  { /*additional cases where we might 
    be at the head
    */
    node->setNext(head);
    head = node;
    numOfNodes++;
  }
  else if (i == (numOfNodes))
  {
    tail->setNext(node);
    tail->getNext()->setNext(nullptr);
    tail = tail->getNext();
    numOfNodes++;
  }
}

void LinkedList::addBack(Tiles *data)
{
  Node *newNode = new Node(data, nullptr);
  tail->setNext(newNode);
  tail = tail->getNext();
  numOfNodes++;
}

void LinkedList::addFront(Tiles *data)
{
  Node *newNode = new Node(data, nullptr);
  newNode->setNext(head);
  head = newNode;
  numOfNodes++;
}
/* delete selected tile pointer */
void LinkedList::deleteNode(int i)
{
  if (i == 0)
  {
    head = head->getNext();
    numOfNodes--;
  }
  else if (i == numOfNodes - 1)
  {
    deleteBack();
  }
  else
  {
    findNode(i - 1)->setNext(findNode(i + 1));
    numOfNodes--;
  }
}

void LinkedList::deleteBack()
{

  tail = findNode(numOfNodes - 2);
  tail->setNext(nullptr);
  numOfNodes--;
}

void LinkedList::deleteFront()
{

  head = head->getNext();
  numOfNodes--;
}

int LinkedList::returnSize()
{
  return numOfNodes;
}

/* prints everything in the linked list */
void LinkedList::printLine()
{
  current = head;

  while (current->getNext() != nullptr)
  {
    current->getTile()->printTile();

    if (current->getNext()->getNext() != nullptr)
    {
      std::cout << ", ";
    }
    if (current->getNext()->getNext() == nullptr)
    {
      std::cout << ", ";
      current->getNext()->getTile()->printTile();
    }
    current = current->getNext();
  }

  if (head->getNext() == nullptr)
  {
    std::cout << head->getTile()->getTileDetails();
  }

  std::cout << std::endl;
}

Tiles *LinkedList::getElement(LinkedList *list, int index,Tiles* tile)
{

  // Tiles *tile = new Tiles("R");
  Node *newElement = new Node(tile, nullptr);
  for (int i = 0; i < 6; i++)
  {
    // newElement = f->findNode(index);
    //TODO
    //
  }

  std::cout << "We found" << newElement->getTile();
  //return f->findNode(i);
  return nullptr;
}

void LinkedList::removeElement(std::string tile){
 
    // head = dummy->getNext();

  // Node *temp = head;
  // Node *prev = nullptr;

  // while(temp != nullptr){
  //   while(temp!= nullptr && temp->getTile()->getColour() == tile){
  //     prev = temp;
  //     temp = temp->getNext();
  //   }

  //   if(temp == nullptr){
  //     prev->setNext(temp->getNext());
  //     temp = prev->getNext();
  //   }
  // }
    Node *temp;
    Node *prev = NULL;
    Node *next;

    for (temp = head;  temp != NULL;  temp = next) {
        next = temp->getNext();

        if (temp->getTile()->getColour() != tile) {
            prev = temp;
            continue;
        }

        if (prev != NULL)
            prev->setNext(next);
        else
            head = next;

        delete temp;
    }






    // int pos = 0;
   
    // Node *current,*store;
    // current = head;
  //  current = head;
  //   // Node *q;


  //   if(current== nullptr) {
  //     printf("Linked List not initialized");
  //     return;
  //   } 

  //   // current = head;
  //   while(current!= nullptr && current->getNext() != nullptr) {
  //       if(current->getTile()->getColour() == tile) {
  //         std::cout<<current->getTile()->getColour()<<std::endl;
  //           current->setTile(notile);
       
  //       return;
  //       } 
        
  //       else{
  //         current = current->getNext();
        
  //       }
  //   }

}

