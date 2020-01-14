#ifndef BUILDING_H
#define BUILDING_H

#include "Point2D.h"
#include "GameObject.h"

class Building: public GameObject
{
private:
  unsigned int pokemon_count; // number of pokemon currently in this Building
public:
  Building(); // default constructor

  Building(char, int, Point2D); //initializes id, location, display code and other values

  void AddOnePokemon(); //add 1 pokemon

  void RemoveOnePokemon(); //minus 1 pokemon

  void ShowStatus(); // prints the status

  bool ShouldBeVisible(); //returns true
};

#endif
