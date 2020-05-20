#include "Player.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits>


using namespace std;

Player::Player(string name, int points)
{
  this->name = name;
  this->points = points;
}

string Player::getName()
{
  return this->name;
}

void Player::setName(string name)
{
  this->name = name;
}

int Player::getPoints()
{
  return this->points;
}

void Player::setPoints(int points)
{
  this->points = points;
}

LinkedList Player::returnlist()
{
  return *list;
}

int Player::tilesinhand()
{
  return list->returnSize();
}

void Player::fillHand(Factory* factory) {
    
    for (int i = 0; i < 6; i++) {
     
      factory->fillFactory();
   
    }
}

void Player::winner(Player* player1, Player* player2){
  if(player1->getPoints() > player2->getPoints() ){
    cout << "Player 1:  " << player1->getName() << " is the winner.";
  }
  else if(player1->getPoints() < player2->getPoints()){
    cout << "Player 2: " << player2->getName() << " is the winner.";
  }
}

void Player::updatePoints(int val){
  int currpoints =this->points -val;
  std::cout<< "These " << currpoints<< endl;
  setPoints(currpoints);
} 

void Player::savePlayer(string filename){
  ofstream of;
  of.open(filename,ios::app|ios::out);
  of << points;

}

std::fstream& Player::GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

// int Player::getLoadPoints1(){
//   return this->loadPoints1;
// }

// int Player::getLoadPoints2(){
//   return this->loadPoints2;
// }

// void Player::setloadPoints1(int loadPoints1){
//   this->loadPoints1 = loadPoints1;
// }


// void Player::setloadPoints2(int loadPoints2){
//   this->loadPoints2 = loadPoints2;
// }

void Player::loPoints1(string filename){
  fstream file(filename);
  GotoLine(file,12);
  int line;
  file>>line;
  setPoints(line);

}

void Player::loPoints2(string filename){
  fstream file(filename);
  GotoLine(file,24);
  int line;
  file>>line;
  setPoints(line);

}
