#include "Vector2D.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

Vector2D::Vector2D() //The default constructor initializes x and y to 0.0
{
  x = 0.0;
  y = 0.0;
}
Vector2D::Vector2D(double in_x, double in_y) //sets x and y to in_x and in_y
{
  x = in_x;
  y = in_y;
}
// following are non-member overloaded operators
Vector2D operator*(Vector2D v1, double d)
{
  Vector2D v2;
  v2.x = v1.x * d;
  v2.y = v1.y * d;
  return v2;
}

Vector2D operator/(Vector2D v1, double d)
{
  Vector2D v2;
  v2.x = v1.x / d;
  v2.y = v1.y / d;
  return v2;
}

ostream& operator<<(ostream& out, Vector2D v)
{
  return out << v.x << " " << v.y << "\n";
}
