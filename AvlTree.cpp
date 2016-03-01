#include <iostream>
#include <queue>
#include <math.h>
#include "AvlTree.h"
using namespace std;

AvlTree::AvlTree() {
  this->insertComparisons = 0;
  this->deleteComparisons = 0;
  this->rootNode = 0;
}

void AvlTree::insert(City city, Node*& current) {
  if(current == 0) { insertComparisons++;
    Node* newNode = new Node(city);
    current = newNode;
  } else if(city.getName().compare(current->getCity().getName()) < 0) { insertComparisons++;
    insert(city, current->left);
  } else if(city.getName().compare(current->getCity().getName()) > 0) { insertComparisons++;
    insert(city, current->right);
  }
  balance(current);
}

void AvlTree::findNearCitites(Node* root, int numberOfCities, int x, int y, int distance) {
  int numFoundCities = 0;

  queue<Node*> queue;
  int i = 0;
  int level = 0;

  if(root != 0) {
    queue.push(root);
  }
  while (queue.size() < numberOfCities)
  {
    i = queue.size();
    while(i > 0) {

      Node* temp = 0;
      if(queue.front() != 0) {
        temp = queue.front();
        City tempCity = temp->getCity();

        if(tempCity.getX() == x && tempCity.getY() == y) {
          cout << "City with matching coordinates found: "
               << tempCity.getName() << " ("
               << tempCity.getX() << ", "
               << tempCity.getY() << ")" << endl;
        } else if(withinDistance(x, tempCity.getX(), y, tempCity.getY(), distance)) {
          this->nearCities[numFoundCities] = tempCity;
          numFoundCities++;
        }
      }

      queue.pop();

      if(temp == 0) {
        queue.push(0);
        queue.push(0);
      } else {
        if(temp->left != 0) {
          queue.push(temp->left);
        } else {
          queue.push(0);
        }
        if(temp->right != 0) {
          queue.push(temp->right);
        } else {
          queue.push(0);
        }
      }
      i--;
    }
    level++;
  }
  cout << "Cities within specified distance: " << endl;

  for(int i = 0; i < numFoundCities; i++) {
    cout << this->nearCities[i].getName() << " "
               << this->nearCities[i].getX() << " "
               << this->nearCities[i].getY() << endl;
  }
}

void AvlTree::deleteByName(string cityName, Node*& current) {
  if(current == 0) { deleteComparisons++;
    return;
  }
  if(cityName.compare(current->getCity().getName()) < 0) { deleteComparisons++;
    deleteByName(cityName, current->left);
  } else if(cityName.compare(current->getCity().getName()) > 0) { deleteComparisons++;
    deleteByName(cityName, current->right);
  } else if(current->left != 0 && current->right != 0) { deleteComparisons++;
    current->setCity(findMin(current->right));
    deleteByName(current->getCity().getName(), current->right);
  } else {
    Node* temp = current;
    current = (current->left != 0) ? current->left : current->right;
    delete temp;
  }

  balance(current);
}

void AvlTree::deleteByCoords(int x, int y, Node*& current) {
  if(current == 0) {
    return;
  }

  if(current->getCity().getX() == x && current->getCity().getY() == y) {
    this->searchCity = current->getCity().getName();
  }  else {
    deleteByCoords(x, y, current->left);
    deleteByCoords(x, y, current->right);
  }

  deleteByName(this->searchCity, this->rootNode);
}

City AvlTree::findMin(Node*& current) {
  if(current->left == 0) {
    return current->getCity();
  } else {
    return findMin(current->left);
  }
}

void AvlTree::balance(Node*& root) {
  if(root == 0) {
    return;
  }

  if(height(root->left) - height(root->right) > 1) {
    if(height(root->left->left) >= height(root->left->right)) {
      rotateLeft(root);
    } else {
      doubleRotateLeft(root);
    }
  } else if(height(root->right) - height(root->left) > 1) {
    if(height(root->right->right) >= height(root->right->left)) {
      rotateRight(root);
    } else {
      doubleRotateRight(root);
    }
  }

  root->height = max(height(root->left), height(root->right)) + 1;
}

void AvlTree::rotateLeft(Node*& k2) {
  Node* k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->left), k2->height) + 1;
  k2 = k1;
}

void AvlTree::rotateRight(Node*& k2) {
  Node* k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->right), k2->height) + 1;
  k2 = k1;
}

void AvlTree::doubleRotateLeft(Node*& k3) {
  rotateRight(k3->left);
  rotateLeft(k3);
}

void AvlTree::doubleRotateRight(Node*& k3) {
  rotateLeft(k3->right);
  rotateRight(k3);
}

void AvlTree::printTree(Node* root, int numberOfCities) {
  queue<Node*> queue;
  int i = 0;
  int level = 0;

    if(root != 0) {
      queue.push(root);
    }
    while (queue.size() < numberOfCities)
    {
      i = queue.size();
      std::cout << "Level " << level << ": ";
      while(i > 0) {

        Node* temp = 0;
        if(queue.front() != 0) {
          temp = queue.front();
        }

        queue.pop();
        if(temp != 0) {
          cout << temp->getCity().getName() << " ";
        } else {
          cout << "* ";
        }

        if(temp == 0) {
          queue.push(0);
          queue.push(0);
        } else {
          if(temp->left != 0) {
            queue.push(temp->left);
          } else {
            queue.push(0);
          }
          if(temp->right != 0) {
            queue.push(temp->right);
          } else {
            queue.push(0);
          }
        }
        i--;
      }
      level++;
      cout << endl;
    }
}

Node* AvlTree::getRoot() {
  return this->rootNode;
}

int AvlTree::height(Node* node) {
  if(node == 0) {
    return -1;
  } else {
    return node->height;
  }
}

bool AvlTree::withinDistance(int x1, int x2, int y1, int y2, int distance) {
  // cout << sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) << " " << endl;
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) <= distance;
}

int AvlTree::getInsertComparisons() {
  return this->insertComparisons;
}

int AvlTree::getDeleteComparisons() {
  return this->deleteComparisons;
}
