#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "string.h"
#include <iostream>

using namespace std;

View::View()
{
  size = 11;
  scale = 2;
  origin = Point2D(0,0); // values set according to document
}

void View::Clear() // "clears" the chart which creates spaces and periods
{
  for (int i = 0; i <= view_maxsize; i++) // starts at top left
  {
    for (int j = view_maxsize; j >= 0; j--) // goes down from maxsize
    {
      grid[i][j][0] = ' ';
      grid[i][j][1] = '.';
    }
  }
}

void View::Plot(GameObject* ptr) // plots the game objects
{
  if (GetSubscripts(out_x, out_y, ptr -> GetLocation()) == true)
  {
    // couldnt figure out draw function
  }
}

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location) //determines if x and y are out of screen
{
  out_x = (location.x - origin.x) / scale);
  out_y = ((location.y - origin.y) / scale);

  if (out_x <= view_maxsize && out_y <= view_maxsize)
  {
    return true;
  }
  else
  {
    cout << "An object is outside the display\n";
    return false;
  }
}

// couldn't figure out the draw function
