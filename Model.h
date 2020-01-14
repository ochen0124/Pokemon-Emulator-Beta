#ifndef MODEL_H
#define MODEL_H

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "View.h"
#include "string.h"


class Model
{
private:
  int time;

  GameObject* object_ptrs[10];

  int num_objects;

  Pokemon* pokemon_ptrs[10];

  int num_pokemon;

  PokemonCenter* center_ptrs[10];

  int num_centers;

  PokemonGym* gym_ptrs[10];

  int num_gyms;
public:
  Model();

  Pokemon* GetPokemonPtr(int);

  PokemonCenter* GetPokemonCenterPtr(int);

  PokemonGym* GetPokemonGymPtr(int);

  bool Update();

  void Display(View& view);

  void ShowStatus();

  ~Model(); // model destructor
};

#endif
