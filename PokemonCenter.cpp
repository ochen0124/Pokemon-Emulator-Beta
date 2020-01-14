#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include <iostream>

using namespace std;

PokemonCenter::PokemonCenter(): Building('C', 1, Point2D())
{
  stamina_capacity = 100; // base default pokemon center
  num_stamina_points_remaining = stamina_capacity;
  dollar_cost_per_stamina_point = 5;
  state = STAMINA_POINTS_AVAILABLE;
  cout << "PokemonCenter default constructed\n";
}

PokemonCenter::PokemonCenter(int in_Id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc): Building('C', in_Id, in_loc)
{
  dollar_cost_per_stamina_point = stamina_cost;
  stamina_capacity = stamina_cap;
  num_stamina_points_remaining = stamina_capacity;
  state = STAMINA_POINTS_AVAILABLE;
  cout << "PokemonCenter constructed\n";
}

bool PokemonCenter::HasStaminaPoints() // simple check to see if there is stamina points available
{
  if (num_stamina_points_remaining > 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining() // checks to see number of stamina points left
{
  return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
  if ((stamina_points * dollar_cost_per_stamina_point) <= budget) //checks if stamina points * the cost of each point is less than or equal to your money
  {
    return true;
  }
  else
  {
    return false;
  }
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
  return stamina_points * dollar_cost_per_stamina_point; //returns the cost of the stamina points
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
  if (num_stamina_points_remaining >= points_needed) // if there is enough stamina than you want
  {
    num_stamina_points_remaining = num_stamina_points_remaining - points_needed; //subtracts the points you want from stamina pool
    return points_needed;
  }
  if (num_stamina_points_remaining < points_needed)
  {
    unsigned int current = num_stamina_points_remaining; //takes all the stamina out of the pool
    num_stamina_points_remaining = 0; //stamina points depleted
    return current;
  }
}

bool PokemonCenter::Update()
{
  if (num_stamina_points_remaining == 0)
  {
    state = NO_STAMINA_POINTS_AVAILABLE; // if stamina points depleted then state is that and C becomes c
    display_code = 'c';
    cout << "PokemonCenter " << id_num << " has ran out of stamina points.\n";
    return true;
  }
  else
  {
    return false;
  }
}

void PokemonCenter::ShowStatus() // gives the current status of the PokemonCenter
{
    cout << "Pokemon Center Status: ";
    Building::ShowStatus();
    cout << "Pokemon dollars per stamina point: " << dollar_cost_per_stamina_point << "\n";

    if (num_stamina_points_remaining > 1) // checks for multiple or singularity of stamina points left
    {
        cout << "has" << num_stamina_points_remaining << " stamina points remaining\n";
    }
    else
    {
        cout << "has" << num_stamina_points_remaining << " stamina point remaining\n";
    }
}
