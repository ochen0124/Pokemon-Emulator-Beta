#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"
#include <iostream>

using namespace std;

PokemonGym::PokemonGym(): Building('G', 1, Point2D()) // default gym settings
{
  state = NOT_BEATEN; // set to not beaten
  max_number_of_training_units = 10;
  num_training_units_remaining = max_number_of_training_units;
  stamina_cost_per_training_unit = 1;
  dollar_cost_per_training_unit = 1.0;
  experience_points_per_training_unit = 2;
  cout << "PokemonGym default constructed\n";
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc): Building('G', in_id, in_loc)
{
  id_num = in_id;
  max_number_of_training_units = max_training_units;
  stamina_cost_per_training_unit = stamina_cost;
  experience_points_per_training_unit = exp_points_per_unit;
  dollar_cost_per_training_unit = dollar_cost;
  location = in_loc
  cout << "PokemonGym constructed\n";
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
  return dollar_cost_per_training_unit * unit_qty; //returns cost of training the amount of units
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
  return stamina_cost_per_training_unit * unit_qty; //returns stamina of training the amount of units
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
  return num_training_units_remaining; //returns amount of units left
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
  if ((unit_qty * dollar_cost_per_training_unit <= budget) && (unit_qty * stamina_cost_per_training_unit <= stamina))
  {
    return true; //if cost of training and cost of stamina is less than bugdget and current stamina
  }
  else
  {
    return false;
  }
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
  if (training_units <= num_training_units_remaining)
  {
    num_training_units_remaining = num_training_units_remaining - training_units;
    return training_units * experience_points_per_training_unit; // if the amount of training units wanted is less than remaining
  }
  else
  {
    training_units = num_training_units_remaining; // or else you can only get the training units remaining
    num_training_units_remaining = 0; // remaining set to 0
    return training_units * experience_points_per_training_unit;
  }
}

bool PokemonGym::Update()
{
  if (num_training_units_remaining == 0 && state == NOT_BEATEN) // training units are depleted so state is beaten
  {
    state = BEATEN;
    display_code = 'g'; // display codes becomes lowercase g
    cout << display_code << id_num << " has been beaten.\n";
    return true;
  }
  else
  {
    return false;
  }
}

bool PokemonGym::IsBeaten()
{
  if (num_training_units_remaining == 0) // if units = 0, it is beaten
  {
    return true;
  }
  else
  {
    return false;
  }
}

void PokemonGym::ShowStatus() // shows status of the gym
{
  cout << "Pokemon Gym Status: "\n;
  Building::ShowStatus();
  cout << "Max number of training units: " << max_number_of_training_units;
  cout << "\nStamina cost per training unit: " << stamina_cost_per_training_unit;
  cout << "\nPokemon dollar per training unit: " << dollar_cost_per_training_unit;
  cout << "\nExperience points per training unit: " << experience_points_per_training_unit << "\n";
  if (num_training_units_remaining > 1) // tests for multiple or singularity
  {
    cout << num_training_units_remaining << " training units are remaining for this gym\n";
  }
  else
  {
    cout << num_training_units_remaining << " training unit is remaining for this gym\n";
  }
}
