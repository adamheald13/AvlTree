#include "Node.h"

Node* Node::getLeft() {
  return this->left;
}

Node* Node::getRight() {
  return this->right;
}

int Node::getHeight() {
  return this->height;
}

City Node::getCity() {
  return this->city;
}
