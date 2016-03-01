#include <iostream>
#include <math.h>
#include "UnorderedArray.h"
using namespace std;

UnorderedArray::UnorderedArray() {
  this->insertComparisons = 0;
  this->deleteComparisons = 0;
  this->size = 0;
}

void UnorderedArray::insert(City city) {
  this->arrayOfCities[size] = city;
  this->size++;
}

int UnorderedArray::getSize() {
  return this->size;
}

void UnorderedArray::printArray() {
  for(int i = 0; i < this->size; i++) {
    cout << this->arrayOfCities[i].getName() << " "
               << this->arrayOfCities[i].getX() << " "
               << this->arrayOfCities[i].getY() << endl;
  }
}

void UnorderedArray::findNearCitites(int x, int y, int distance) {
  int numFoundCities = 0;

  for(int i = 0; i < this->size; i++) {
    if(this->arrayOfCities[i].getX() == x && this->arrayOfCities[i].getY() == y) {
      cout << "City with matching coordinates found: "
           << this->arrayOfCities[i].getName() << " ("
           << this->arrayOfCities[i].getX() << ", "
           << this->arrayOfCities[i].getY() << ")" << endl;
    } else if(withinDistance(x, this->arrayOfCities[i].getX(), y, this->arrayOfCities[i].getY(), distance)) {
      this->nearCities[numFoundCities] = this->arrayOfCities[i];
      numFoundCities++;
    }
  }

  cout << "Cities within specified distance: " << endl;

  for(int i = 0; i < numFoundCities; i++) {
    cout << this->nearCities[i].getName() << " "
               << this->nearCities[i].getX() << " "
               << this->nearCities[i].getY() << endl;
  }
}

void UnorderedArray::deleteByName(string name) {
  int foundIndex = -1;

  for(int i = 0; i < this->getSize(); i++) { deleteComparisons++;
    if(foundIndex < 0) { /*search*/ deleteComparisons++;
      if(name == this->arrayOfCities[i].getName()) deleteComparisons++;
        foundIndex = i;
    } else {             //move array elements to fill the gap
      this->arrayOfCities[i - 1] = this->arrayOfCities[i];
    }
  }

  this->size--;
}

void UnorderedArray::deleteByCoords(int x, int y) {
  int foundIndex = -1;

  for(int i = 0; i < this->getSize(); i++) {
    if(foundIndex < 0) { //search
      if(x == this->arrayOfCities[i].getX() && y == this->arrayOfCities[i].getY())
        foundIndex = i;
    } else {             //move array elements to fill the gap
      this->arrayOfCities[i - 1] = this->arrayOfCities[i];
    }
  }

  this->size--;
}

bool UnorderedArray::withinDistance(int x1, int x2, int y1, int y2, int distance) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) <= distance;
}

int UnorderedArray::getInsertComparisons() {
  return this->insertComparisons;
}

int UnorderedArray::getDeleteComparisons() {
  return this->deleteComparisons;
}
