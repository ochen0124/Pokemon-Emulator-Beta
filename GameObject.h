#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vector2D.h"
#include "Point2D.h"

using namespace std;

class GameObject
{
protected:
  Point2D location; //Location of the object

  int id_num;

  char display_code; //How the object is represented in the View

  char state; //State of the object

  char in_code;

public:
  GameObject(char);

  GameObject(Point2D, int,char);

  virtual ~GameObject(); // object destructor

  Point2D GetLocation(); //Returns location for this object

  int Getld(); //Returns id

  char GetState(); //Returns state

  virtual void ShowStatus(); //Outputs information contained in this class

  virtual bool ShouldBeVisible();

  virtual bool Update();

  void DrawSelf(char*);
};

#endif
