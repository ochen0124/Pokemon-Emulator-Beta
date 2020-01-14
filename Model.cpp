#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"

#include "string.h"
#include "math.h"
#include "View.h"
#include "stdlib.h"

#include <iostream>

using namespace std;

Model::Model()
{
  time = 0;
  Pokemon* pokemon_1 = new Pokemon("Gengar", 1, 'P', 2, Point2D(5,1)); // not sure if I can change the pokemon name and speed
  Pokemon* pokemon_2 = new Pokemon("Dragonite", 2, 'P', 2, Point2D(10,1)); // but I created custom pokemons, my two favorites
  PokemonCenter* center_1 = new PokemonCenter(1, 1, 100, Point2D(1,20));
  PokemonCenter* center_2 = new PokemonCenter(2, 2, 150, Point2D(10,20)); // also customized the pokecenter and gyms
  PokemonGym* gym_1 = new PokemonGym(15, 2, 3.0, 2, 1, Point2D());
  PokemonGym* gym_2 = new PokemonGym(25, 4, 6.0, 4, 2, Point2D(5,5) );

  num_objects = 6; // total objects
  num_pokemon = 2;
  num_centers = 2;
  num_gyms = 2;
// sets the objects to both the respective pointer as well as an object pointers with 6 spaces
  object_ptrs[0] = pokemon_1;
  pokemon_ptrs[0] = pokemon_1;
  object_ptrs[1] = pokemon_2;
  pokemon_ptrs[1] = pokemon_2;
  object_ptrs[2] = center_1;
  center_ptrs[0] = center_1;
  object_ptrs[3] = center_2;
  center_ptrs[1] = center_2;
  object_ptrs[4] = gym_1;
  gym_ptrs[0] = gym_1;
  object_ptrs[5] = gym_2;
  gym_ptrs[1] = gym_2;

  cout << "Model default constructed\n";
}

Model::~Model() // model destructor deletes all the game objects by looping through
{
  for (int i = 0; i < 6; i++)
  {
    delete object_ptrs[i];
  }
  cout << "Model destructed.\n";
}
// pointers to the game objects
Pokemon* Model::GetPokemonPtr(int id)
{
  return pokemon_ptrs[id-1];
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
  return center_ptrs[id-1];
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
  return gym_ptrs[id-1];
}

bool Model::Update() // updates
{
  int pokemon_counter = 0; // counter to see how many pokemons are left, each counter represents an exhausted pokemon
  int gym_counter = 0; // each counter represents a defeated gym
  bool returntf = false; // holds the bool

  for (int i = 0; i < num_pokemon; i++)
  {
    if (pokemon_ptrs[i] -> GetState() == EXHAUSTED) // if exhausted counter goes up
    {
      pokemon_counter = pokemon_counter + 1;
    }
    else
    {
      pokemon_counter = pokemon_counter + 0;
    }

    if (pokemon_ptrs[i] -> Update() == true)
    {
      returntf = true;
    }
    else
    {
      returntf = false;
    }
  }

  for (int i = 0; i < num_gyms; i++)
  {
    if (gym_ptrs[i] -> GetState() == BEATEN) // if gym beaten counter goes up
    {
      gym_counter = gym_counter + 1;
    }
    else
    {
      gym_counter = gym_counter + 0;
    }

    if (gym_ptrs[i] -> Update() == true)
    {
      returntf = true;
    }
    else
    {
      returntf = false;
    }
  }

  for (int i=0; i < num_centers; i++)
  {
    if (center_ptrs[i] -> Update() == true)
    {
      returntf = true;
    }
    else
    {
      returntf = false;
    }
  }

  time = time + 1; // increases time

  if (pokemon_counter == num_pokemon)
  {
    cout << "GAME OVER: You lose! All of your Pokemon are tired!\n"; // if counter of 2 equals pokemon of 2 you lose!
    exit(EXIT_FAILURE);
  }

  if (gym_counter == num_gyms) // if beaten gyms = 2 you win!
  {
    cout << "GAME OVER: You win! All Pokemon Gyms beaten!\n";
    exit(EXIT_SUCCESS);
  }

  return returntf;
}


void Model::Display(View& view)
{
  cout << "time: " << time << "\n"; // displays time 

  this -> ShowStatus();
  view.Clear();
  for (int i = 0; i < num_objects; i++)
  {
    view.Plot(object_ptrs[i]);
  }
}


void Model::ShowStatus() // shows status of each game object
{
  for (int i = 0; i < num_objects; i++)
  {
    object_ptrs[i] -> ShowStatus();
  }
}
