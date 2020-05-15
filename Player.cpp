#include "Player.h"

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

void Player::fillHand(Factory* factory)
{
  for (int i = 0; i < 6; i++)
  {
    factory->fillFactory();
  }
}