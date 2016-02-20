#ifndef UNORDEREDARRAY_H
#define UNORDEREDARRAY_H
#include "City.h"

class UnorderedArray
{
public:
  UnorderedArray();

  void insert(City city);
  void printArray();
  int getSize();
  void deleteByName(string name);
  void deleteByCoords(int x, int y);

private:
  int size;
  City arrayOfCities[100];
};

#endif
