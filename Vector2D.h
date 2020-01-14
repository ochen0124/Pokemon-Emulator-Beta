#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
using namespace std;

class Vector2D
{
public:
  double x;

  double y;

  Vector2D(); //The default constructor initializes x and y to 0.0

  Vector2D(double, double); //sets x and y to in_x and in_y
};

Vector2D operator*(Vector2D, double); // non member overloaded operators

Vector2D operator/(Vector2D, double);

ostream& operator<<(ostream&, Vector2D);

#endif
