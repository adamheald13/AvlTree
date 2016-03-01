#include <iostream>
#include <fstream>
#include <sstream>
#include "City.h"
#include "UnorderedArray.h"
#include "AvlTree.h"
using namespace std;

void readFile();
void readTestData();
void deletionTest();
void findCitiesInProximity(int x, int y, int distance);
UnorderedArray array;
AvlTree* avlTree = new AvlTree();
int inputs[100][3];
int numberOfTests;
int numberOfCities;

int main() {
  readFile();
  readTestData();

  for(int i = 0; i < numberOfTests; i++) {
    findCitiesInProximity(inputs[i][0],
                          inputs[i][1],
                          inputs[i][2]);
  }

  cout << "----- Comparisons -----" << endl;
  //comparison numbers based on the insertion in the trees when they are created
  cout << "Number of comparisons for insertion on UnorderedArray: " << array.getInsertComparisons() << endl;
  cout << "Number of comparisons for insertion on AvlTree: " << avlTree->getInsertComparisons() << endl;

  //delete every other city from data structures and report # of comps
  deletionTest();
}

void findCitiesInProximity(int x, int y, int distance) {
  //TODO UnorderedArray
  cout << "----- Near Cities in UnorderedArray -----" << endl;
  array.findNearCitites(x, y, distance);
  cout << endl;

  //TODO AvlTree
  cout << "----- Near Cities in AvlTree -----" << endl;
  avlTree->findNearCitites(avlTree->getRoot(), numberOfCities, x, y, distance);
  cout << endl;
}

void readFile() {
  ifstream cityFile("data5R.txt");
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

void readTestData() {
  ifstream testFile("lab5_testR.txt");
  string line;
  int x;
  int y;
  int distance;
  numberOfTests = 0;

  if(testFile.is_open()) {
    while(getline(testFile, line)) {
      istringstream iss(line);
      iss >> x >> y >> distance;
      inputs[numberOfTests][0] = x; inputs[numberOfTests][1] = y; inputs[numberOfTests][2] = distance;
      numberOfTests++;
    }
    testFile.close();
  }
}

void deletionTest() {
  ifstream cityFile("data5R.txt");
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

      if(numberOfCities % 2 == 0) {
        array.deleteByName(name);
        avlTree->deleteByName(name, avlTree->rootNode);
      }
    }
    cityFile.close();
  }
  cout << "Number of comparisons for deletion on UnorderedArray: " << array.getDeleteComparisons() << endl;
  cout << "Number of comparisons for deletion on AvlTree: " << avlTree->getDeleteComparisons() << endl;
}
