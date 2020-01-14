#include "GameObject.h"
#include "Vector2D.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

GameObject::GameObject(char in_code) //default game object
{
  display_code = in_code;
  id_num = 1;
  state = 0;
  cout << "GameObject constructed";
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
  char display_code;
  int id_num;
  state = 0;
  cout << "GameObject constructed";
}

Point2D GetLocation() //Returns location for this object
{
  return location;
}

int Getld() //Returns id
{
  return in_id;
}

char GetState() //Returns state
{
  return state;
}

void ShowStatus() //Outputs information contained in this class
{
  cout << display_code << " " << id_num << " at " << location;
}

GameObject::~GameObject()
{
  cout << "GameObject destructed\n";
}
