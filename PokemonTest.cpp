#include <iostream>

using namespace std;

class Point2D
{
public:
  double x; //The x value of the point
  double y; //The y value of the point
    Point2D() //The default constructor initializes x and y to 0.0
    {
      x = 0.0;
      y = 0.0;
    }
    Point2D(double in_x, double in_y) //sets x and y to in_x and in_y
    {
      x = in_x;
      y = in_y;
    }
};

double GetDistanceBetween(Point2D p1, Point2D p2) //Gets the distance between the 2 points.
{
  return sqr(pow(p1,2) + pow(p2,2));
}

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

class Vector2D
{
public:
  double x;
  double y;
    Point2D() //The default constructor initializes x and y to 0.0
    {
      x = 0.0;
      y = 0.0;
    }
    Vector2D(double in_x, double in_y) //sets x and y to in_x and in_y
    {
      x = in_x;
      y = in_y;
    }
};

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

class GameObject
{
protected:
  Point2D location; //Location of the object
  int id_num;
  char display_code; //How the object is represented in the View
  char state; //State of the object
  char in_code;
public:
  GameObject(char in_code)
  {
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout << "GameObject constructed";
  }
  GameObject(Point2D in_loc, int in_id, char in_code)
  {
    char display_code;
    int id_num;
    cout << "GameObject constructed";
  }
  Point2D GetLocation(); //Returns location for this object
  {
    return
  }
  int Getld(); //Returns id
  {
    return in_id;
  }
  bool GetState(); //Returns state
  {
    return state;
  }
  void ShowStatus(); //Outputs information contained in this class
  {
    cout << display_code << "status" << id_num << "at" <<
  }
};

int main()
{
  return 0;
}
