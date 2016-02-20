#include "City.h"
using namespace std;

City::City() {

}

City::City(string name, int x, int y) {
  this->name = name;
  this->x = x;
  this->y = y;
}

string City::getName() {
  return this->name;
}

int City::getX() {
  return this->x;
}

int City::getY() {
  return this->y;
}
