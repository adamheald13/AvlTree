#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"
#include "City.h"

class AvlTree
{
public:
  AvlTree();
  void printTree(Node* root, int numberOfCities);
  void findNearCitites(Node* root, int numberOfCities, int x, int y, int distance);
  void insert(City city, Node*& current);
  void deleteByName(string cityName, Node*& current);
  void deleteByCoords(int x, int y, Node*& current);
  int getDeleteComparisons();
  int getInsertComparisons();
  Node* getRoot();
  Node* rootNode;

private:
  void insertPrivate(City city, Node* current);
  void balance(Node*& root);
  int height(Node* node);
  City findMin(Node*& right);

  void rotateLeft(Node*& k2);
  void doubleRotateLeft(Node*& k3);
  void rotateRight(Node*& k2);
  void doubleRotateRight(Node*& k3);
  bool withinDistance(int x1, int x2, int y1, int y2, int distance);
  string searchCity;
  City nearCities[100];
  int deleteComparisons;
  int insertComparisons;
};

#endif
