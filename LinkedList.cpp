
  #include "LinkedList.h"
  #include <fstream> 
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
  //  std::cout<< node->getTile()->getColour()<<std::endl;
  //  std::cout<<node->getNext();
    if (head == nullptr)
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
    else if (head != nullptr)
    {
      tail->setNext(node);
      tail = node;
      numOfNodes++;
    }
  

  } //end of addNode

  
  Node *LinkedList::findNode(int index)
  {
    Node *temp = head;

    for (int count = 1; count <= index; count++)
    {
      temp = temp->getNext();
    }
    return temp;
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
    if(head == nullptr) {
        return 0;
    }
    return numOfNodes;
  }

  /* prints everything in the linked list */
  void LinkedList::printLine()
  {
  
    current = head;
    

    if(current != nullptr){
        std::cout<<"";
        if(current->getTile()->getColour() == 'F'){
            std::cout<<"\u2460 ";
        }
        else{
            // current->getTile()->printTile();
             current->getTile()->printTileColour();

        }

        while (current != nullptr && current->getNext() != nullptr)
        {
          current = current->getNext();
          std::cout << " ";
          if(current->getTile()->getColour() == 'F'){
            std::cout<<"\u2460 ";
          }
          else{
            // current->getTile()->printTile();
             current->getTile()->printTileColour();
          }
        }
    }

    std::cout << std::endl;
    
  }

  std::string LinkedList::returnAsString()
  {
    std::string linkedListAsString = "";
    current = head;

    if(current != nullptr){
        linkedListAsString += current->getTile()->getColour();

        while (current != nullptr && current->getNext() != nullptr)
        {
          current = current->getNext();
          linkedListAsString += " ";
          linkedListAsString += current->getTile()->getColour();
        }
    }
    
    linkedListAsString += "\n";
    return linkedListAsString;    
  }

  
  void LinkedList::removeElement(char tile)
  {

    /*

    Node *current{head};
    Node *prev{nullptr};
    while (current != NULL and current->getNext() != NULL) {

      while (current->getTile()->getColour() == tile) {

        Node *oldCurrent = current;
        current = current->getNext();

        if (oldCurrent == head){
          head = current;
        }
        // Update the previous element in the list, if any
        if (prev){
          prev->setNext(current);
        }

        delete oldCurrent;
        std::cout << numOfNodes << std::endl;
      }

      if (current->getNext() != nullptr) {
        prev = current;
        current = current->getNext();
      }

      // std::cout<<current->getTile()->getColour()<<std::endl;
      
    }*/

    Node *current{head};
    Node *prev{nullptr};


    while(current != nullptr) {
      if(current->getTile()->getColour() == tile) {

        if (current == head){
            if(current->getNext() != nullptr) {
              current = current->getNext();
              head = current;
            }
            else {
              head = nullptr;
              tail = nullptr;
              current = nullptr;
             
            }
            numOfNodes--;
            
        }
        else if (current == tail) {
            prev->setNext(nullptr);
            tail = prev;
            current = nullptr;
            numOfNodes--;
        }
        else {
            prev->setNext(current->getNext());
            current = current->getNext();
            numOfNodes--;
        }
      }
      else {
        prev = current;
        current = current->getNext();
      }
    }
    
  }

  void LinkedList::deleteAll(){

    Node* current = head;  
    Node* next;  
    
  while (current != NULL)  
  {  
      next = current->getNext();  
      free(current);  
      current = next;  
      
  }  

  numOfNodes = 0;  
  /* deref head_ref to affect the real head back  
      in the caller. */
  head = NULL;

  }

