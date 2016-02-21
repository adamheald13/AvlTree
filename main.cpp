#include <iostream>
#include <fstream>
#include <sstream>
#include "City.h"
#include "UnorderedArray.h"
#include "AvlTree.h"
using namespace std;

void readFile();
UnorderedArray array;
AvlTree* avlTree = new AvlTree();
int numberOfCities;

int main()
{
  std::cout << "Populate Unordered Array...." << std::endl << endl;
  readFile();
  std::cout << "----- Resulting Array -----" << std::endl;
  array.printArray();

  std::cout << endl << "----- Delete by name (Salina) -----" << std::endl;
  array.deleteByName("Salina");
  array.printArray();

  std::cout << endl << "----- Delete by coords (9, 10) -----" << std::endl;
  array.deleteByCoords(9, 10);
  array.printArray();

  std::cout << endl << "Populate AVL Tree....." << std::endl << endl;
  std::cout << "----- Resulting Tree -----" << std::endl;
  avlTree->printTree(avlTree->getRoot(), numberOfCities);

  std::cout << endl << "----- Delete by name (Topeka) -----" << std::endl;
  avlTree->deleteByName("Topeka", avlTree->rootNode);
  avlTree->printTree(avlTree->getRoot(), numberOfCities);

  std::cout << endl << "----- Delete by coords (25, 26) -----" << std::endl;
  avlTree->deleteByCoords(25, 26, avlTree->rootNode);
  avlTree->printTree(avlTree->getRoot(), numberOfCities);
}

void readFile()
{
  ifstream cityFile("realDB.txt");
  string line;
  string name;
  int x;
  int y;
  numberOfCities = 0;

  if(cityFile.is_open()) {
    while(getline(cityFile, line)) {
      istringstream iss(line);
      iss >> name >> x >> y;

      array.insert(City(name, x, y));
      avlTree->insert(City(name, x, y), avlTree->rootNode);
      numberOfCities++;
    }
    cityFile.close();
  }
}
