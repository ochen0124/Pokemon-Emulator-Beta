#include "Point2D.h"
#include "Vector2D.h"

#include <iostream>
#include "math.h"

using namespace std;

Point2D::Point2D() //The default constructor initializes x and y to 0.0
{
  x = 0.0;
  y = 0.0;
}

Point2D::Point2D(double in_x, double in_y) //sets x and y to in_x and in_y
{
  x = in_x;
  y = in_y;
}

double Point2D::GetDistanceBetween(Point2D p1, Point2D p2) //Gets the distance between the 2 points.
{
  return sqr(pow(p1,2) + pow(p2,2));
}
// non-member overloaded operators
ostream& operator<<(ostream& out, Point2D p)
{
  return out << "(" << p.x << "," << p.y << ")" << "\n";
}

Point2D operator+(Point2D p1, Vector2D v1)
{
  Point2D p2;
  p2.x = p1.x + v1.x;
  p2.y = p1.y + v1.y;
  return p2;
}

Point2D operator-(Point2D p1, Vector2D v1)
{
  Point2D p2;
  p2.x = p1.x - v1.x;
  p2.y = p1.y - v1.y;
  return p2;
}
