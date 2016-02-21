#ifndef NODE_H
#define NODE_H
#include "City.h"

class Node
{
public:
  Node(City city);
  Node *left;
  Node *right;
  int height;
  int getHeight();
  City getCity();
  void setCity(City city);

private:
  City city;
};

#endif
