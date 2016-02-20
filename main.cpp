#include <iostream>
#include <fstream>
#include <sstream>
#include "City.h"
#include "UnorderedArray.h"
#include "AvlTree.h"
using namespace std;

void readFile();
UnorderedArray array;
AvlTree avlTree;

int main()
{
  readFile();
  array.deleteByCoords(9, 10);
  array.printArray();
}

void readFile()
{
  ifstream cityFile("cityDatabase.txt");
  string line;
  string name;
  int x;
  int y;
  if(cityFile.is_open()) {
    while(getline(cityFile, line)) {
      istringstream iss(line);
      iss >> name >> x >> y;
      array.insert(City(name, x, y));
    }
    cityFile.close();
  }
}
