#ifndef UNORDEREDARRAY_H
#define UNORDEREDARRAY_H
#include "City.h"

class UnorderedArray
{
public:
  UnorderedArray();

  void insert(City city);
  void printArray();
  void findNearCitites(int x, int y, int distance);
  int getSize();
  void deleteByName(string name);
  void deleteByCoords(int x, int y);
  int getDeleteComparisons();
  int getInsertComparisons();

private:
  int size;
  int deleteComparisons;
  int insertComparisons;
  City arrayOfCities[100];
  City nearCities[100];
  bool withinDistance(int x1, int x2, int y1, int y2, int distance);
};

#endif
