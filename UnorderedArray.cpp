#include <iostream>
#include "UnorderedArray.h"
using namespace std;

UnorderedArray::UnorderedArray() {
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

void UnorderedArray::deleteByName(string name) {
  int foundIndex = -1;

  for(int i = 0; i < this->getSize(); i++) {
    if(foundIndex < 0) { //search
      if(name == this->arrayOfCities[i].getName())
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
