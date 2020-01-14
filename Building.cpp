#include "Building.h"
#include "Point2D.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

Building::Building(): GameObject('B') //default constructor
{
  display_code == 'B'; //sets display code to B
  cout << "Building default constructed\n";
  pokemon_count = 0;
}

Building::Building(char in_code, int in_Id, Point2D in_loc): GameObject(in_loc, in_Id, in_code)
{
  id_num = in_id;
  location = in_loc;
  display_code = in_code;
  cout << "Building constructed\n";
  pokemon_count = 0;
}

void Building::AddOnePokemon() // if in building adds 1 count
{
  pokemon_count = pokemon_count + 1;
}

void Building::RemoveOnePokemon() // if not in building removes 1 count
{
  pokemon_count = pokemon_count - 1;
}

void Building::ShowStatus() // displays how many pokemons are in the building
{
  if (pokemon_count == 1) // checks for multiple or singular
  {
    cout << pokemon_count << " pokemon is in this building";
  }
  else
  {
    cout << pokemon_count << " pokemons are in this building";
  }
}

bool Building::ShouldBeVisible()
{
  return true;
}
