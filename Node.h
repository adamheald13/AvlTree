#ifndef NODE_H
#define NODE_H
#include "City.h"

class Node
{
public:
  Node* getLeft();
  Node* getRight();
  int getHeight();
  City getCity();

private:
  Node *left;
  Node *right;
  int height;
  City city;
};

#endif
