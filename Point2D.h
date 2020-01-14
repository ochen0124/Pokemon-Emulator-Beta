#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "Vector2D.h"
using namespace std;

class Point2D
{
public:
  double x; //The x value of the point

  double y; //The y value of the point

  Point2D(); //The default constructor initializes x and y to 0.0

  Point2D(double, double); //sets x and y to in_x and in_y
};

double GetDistanceBetween(Point2D, Point2D); //Gets the distance between the 2 points.

ostream& operator<<(ostream&, Point2D);

Point2D operator+(Point2D, Vector2D);

Point2D operator-(Point2D, Vector2D);

#endif
