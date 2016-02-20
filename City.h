#ifndef CITY_H
#define CITY_H
#include <string>
using namespace std;

class City
{
public:
  City();
  City(string name, int x, int y);

  string getName();
  int getX();
  int getY();

private:
  string name;
  int x, y;
};

#endif
