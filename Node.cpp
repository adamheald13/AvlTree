#include "Node.h"

Node::Node(City city) {
  this->city = city;
  this->left = 0;
  this->right = 0;
  this->height = 0;
}

void Node::setCity(City city) {
  this->city = city;
}

int Node::getHeight() {
  return this->height;
}

City Node::getCity() {
  return this->city;
}
