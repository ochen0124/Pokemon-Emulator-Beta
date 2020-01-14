#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "string.h"
#include "math.h"
#include <iostream>

using namespace std;

Pokemon::Pokemon(): GameObject('P') //defalt pokemon object
{
  speed = 5;
  is_in_gym = false;
  is_in_center = false;
  stamina = 20;
  experience_points = 0;
  pokemon_dollars = 0;
  training_units_to_buy = 0;
  stamina_points_to_buy = 0;
  name = "Mew"; // default name
  current_center = NULL;
  current_gym = NULL;
  destination = Point2D();
  delta = Vector2D();
  state = STOPPED;
  cout << "Pokemon default constructed.\n";
}

Pokemon::Pokemon(char in_code): GameObject(in_code)
{
  speed = 5;
  is_in_gym = false;
  is_in_center = false;
  stamina = 20;
  experience_points = 0;
  pokemon_dollars = 0;
  training_units_to_buy = 0;
  stamina_points_to_buy = 0;
  name = "MewTwo"; // default name
  current_center = NULL;
  current_gym = NULL;
  destination = Point2D();
  delta = Vector2D();

  cout << "Pokemon constructed.\n";
  state = STOPPED;
  display_code = in_code;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc): GameObject(in_loc, in_id, in_code)
{
  speed = in_speed;
  name = in_name;
  is_in_gym = false;
  is_in_center = false;
  stamina = 20;
  experience_points = 0;
  pokemon_dollars = 0;
  training_units_to_buy = 0;
  stamina_points_to_buy = 0;
  current_center = NULL;
  current_gym = NULL;
  destination = Point2D();
  delta = Vector2D();
  state = STOPPED;
  cout << "Pokemon constructed.\n";
}

string Pokemon::PokemonName() // useful when calling the pokemon names in a cout statement
{
  return this -> name;
}

void Pokemon::StartMoving(Point2D dest)
{
  SetupDestination(dest); //sets the destination

  if ((fabs(this -> location.x - dest.x)) == fabs(delta.x) && (fabs(this -> location.y - dest.y) == fabs(delta.y))) // checks to see if you are already at the destination
  {
    cout << this -> display_code << this -> id_num << ": I'm already here. See?\n";
  }
  else
  {
    cout << this -> display_code << this -> id_num << ": On my way.\n"; // if not state is moving
    state = MOVING;
  }

  if (state == IN_CENTER)
  {
    current_center -> AddOnePokemon(); //if already in center then adds one pokemon
    current_center = NULL;
  }

  if (state == IN_GYM)
  {
    current_gym -> AddOnePokemon(); // if in gym, add one pokemon
    current_gym = NULL;
  }

  if (this -> state == EXHAUSTED) // checks if state is exhausted
  {
    cout << this -> display_code << this -> id_num << ": I am exhausted. I may move but you cannot see me.\n";
  }
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
  SetupDestination(center -> GetLocation()); // sets location to pokemon center

  if ((fabs(this -> location.x - destination.x)) == fabs(delta.x) && (fabs(this -> location.y - destination.y) == fabs(delta.y)))
  {
    cout << this -> display_code << this -> id_num << ": I am already at the Pokemon Center!\n"; // checks if you are already at the destination
    state = IN_CENTER;
  }
  else
  {
    cout << this -> display_code << this -> id_num << ": on my way to the center " << center -> GetId() << "\n";
    state = MOVING_TO_CENTER; // if not state is moving
  }

  if (this -> state == EXHAUSTED) // checks if pokemon is exhausted
  {
    cout << this -> display_code << this -> id_num << ": I am exhausted so I can't move to recover stamina...\n";
  }

  if (state == IN_CENTER)
  {
    current_center -> AddOnePokemon(); // add one pokemon if in gym or center
    current_center = NULL;
  }

  if (state == IN_GYM)
  {
    current_gym -> AddOnePokemon();
    current_gym = NULL;
  }
  current_center = center
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
  SetupDestination(gym -> GetLocation());

  if ((fabs(this -> location.x - destination.x)) == fabs(delta.x) && (fabs(this -> location.y - destination.y) == fabs(delta.y)))
  {
    cout << this -> display_code << this -> id_num << ": I am already at the Pokemon Gym!\n"; // checks if pokemon is already at the gym
    state = IN_GYM;
  }
  else
  {
    cout << this -> display_code << this -> id_num << ": On my way to gym " << gym -> GetId() << "\n";
    state = MOVING_TO_GYM; // if not then state is moving
  }

  if (this -> state == EXHAUSTED) // checks for exhaustion
  {
    cout << this -> display_code << this -> id_num << ": I am exhausted so I shouldn't be going to the gym...\n";
  }

  if (state == IN_CENTER)
  {
    current_center -> AddOnePokemon(); // adds a pokemon if in center or gym
    current_center = NULL;
  }

  if (state == IN_GYM)
  {
    current_gym -> AddOnePokemon();
    current_gym = NULL;
  }
  current_gym = gym;
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
  if (this -> state == EXHAUSTED) // if exhausted then can not train
  {
    cout << this -> display_code << this -> id_num << ": I am exhausted so no more training for me...\n";
  }
  else if (state != IN_GYM) // cannot train if not in gym
  {
    cout << this -> display_code << this -> id_num << ": I can only train in a Pokemon Gym!\n";
  }
  else if ((current_gym -> GetDollarCost(num_training_units) > this -> pokemon_dollars) || (current_gym -> GetStaminaCost(num_training_units) > this -> stamina))
  { //cannot train if not enough money
    cout << this -> display_code << this -> id_num << ": Not enough stamina and/or money for training\n";
  }
  else if (current_gym -> GetState() == BEATEN) // cannot train if already beaten
  {
    cout << this -> display_code << this -> id_num << ": Cannot train! This Pokemon Gym is already beaten!\n";
  }
  else
  {
    if (num_training_units > current_gym -> GetNumTrainingUnitsRemaining()) // else trains and  displays how many units you are training with
    {
      training_units_to_buy = current_gym -> GetNumTrainingUnitsRemaining();
    }
    else
    {
      training_units_to_buy = num_training_units;
    }

    cout << this -> display_code << this -> id_num << ": Started to train at Pokemon Gym " << current_gym -> GetId() <<  " with " << training_units_to_buy << " training units\n";
    state = TRAINING_IN_GYM;
  }
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points) //starts recovery based on conditions presented
{
  if (this -> pokemon_dollars < current_center -> GetDollarCost(num_stamina_points))
  {
    cout << this -> display_code << this -> id_num << ": Not enough money to recover any stamina.\n";
    stamina_points_to_buy = 0;
  }
  else if (current_center -> GetNumStaminaPointsRemaining() < 1)
  {
    cout << this -> display_code << this -> id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center\n";
    stamina_points_to_buy = 0;
  }
  else if (state != IN_CENTER)
  {
    cout << this -> display_code << this -> id_num << ": I can only recover stamina points at a Pokemon Center!\n";
    stamina_points_to_buy = 0;
  }
  else
  {
    if (num_stamina_points > current_center -> GetNumStaminaPointsRemaining()) //recovery based on the number of stamina points remaining
    {
      stamina_points_to_buy = current_center -> GetNumStaminaPointsRemaining();
    }
    else
    {
      stamina_points_to_buy = num_stamina_points;
    }

    if (stamina_points_to_buy > 1) //cout depends on multiple or singular stamina point left
    {
      cout << this ->  display_code << this -> id_num << ": Started recovering " << stamina_points_to_buy << " stamina points at Pokemon Center " << current_center -> GetId() << "\n";
    }
    else
    {
      cout << this ->  display_code << this -> id_num << ": Started recovering " << stamina_points_to_buy << " stamina point at Pokemon Center " << current_center -> GetId() << "\n";
    }
    state = RECOVERING_STAMINA;
  }
}

void Pokemon::Stop() // stops the pokemon
{
  state = STOPPED;
  cout << this -> display_code << this -> id_num << ": Stopping..\n";
}

bool Pokemon::IsExhausted()
{
  if (this -> stamina == 0) // if stamina is 0 then pokemon is indeed exhausted
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Pokemon::ShouldBeVisible()
{
  if (this -> state != EXHAUSTED)
  {
    return true; // if pokemon is not exhausted it should show up on the map!
  }
  else
  {
    return false;
  }
}

void Pokemon::ShowStatus()
{
  cout << name << " status: \n";
  GameObject::ShowStatus(); // pokemmon status with cout the ID, speed and delta/ steps to get there

  if (state == STOPPED)
  {
    cout << "stopped\n";
  }
  else if (state == MOVING)
  {
    cout << "moving at a speed of " << speed << " to destination " << destination << "at each step of " << delta << "\n";
  }
  else if (state == MOVING_TO_CENTER)
  {
    cout << "heading to Pokemon Center " << current_center -> GetId() << " at a speed of " << speed << " at each step of " << delta << "\n";
  }
  else if (state == MOVING_TO_GYM)
  {
    cout << "heading to Pokemon Gym " << current_gym -> GetId() << " at a speed of " << speed << " at each step of " << delta << "\n";
  }
  else if (state == IN_CENTER)
  {
    cout << "inside Pokemon Center " << current_center -> GetId() << "\n";
  }
  else if (state == IN_GYM)
  {
    cout << "inside Pokemon Gym " << current_gym -> GetId() << "\n";
  }
  else if (state == TRAINING_IN_GYM)
  {
    cout << "training in Pokemon Gym " << current_gym -> GetId() << "\n";
  }
  else if (state == RECOVERING_STAMINA)
  {
    cout << "recovering stamina in Pokemon Center " << current_center -> GetId() << "\n";
  }
  else
  {
    cout << "the current pokemon exhausted " << "\n";
  }
// basic stats displayed
  cout << "Stamina: " << stamina << "\n";
  cout << "Pokemon Dollars: " << pokemon_dollars << "\n";
  cout << "Experience Points: " << experience_points << "\n";
}

bool Pokemon::Update()
{
  if (state == STOPPED)
  {
    return false;
  }
  else if (state == MOVING)
  {
    UpdateLocation() // updates the location
    if (GetDistanceBetween(location, destination) == 0) // if already there then state is stop and returns true
    {
      state = STOPPED;
      return true;
    }
    else
    {
      if (IsExhausted() == false) // checks for exhaustion
      {
        state = MOVING;
        return false;
      }
      else
      {
        state = EXHAUSTED; // if exhausted returns true because the pokemon stops
        return true;
      }
    }
  }
  else if (state == MOVING_TO_CENTER)
  {
    UpdateLocation()
    if (GetDistanceBetween(location, destination) == 0)
    {
      state = IN_CENTER;
      current_center -> AddOnePokemon();
      return true;
    }
    else
    {
      if (IsExhausted() == false)
      {
        state = MOVING_TO_CENTER;
        return false;
      }
      else
      {
        state = EXHAUSTED;
        return true;
      }
    }
  }
  else if (state == MOVING_TO_GYM)
  {
    UpdateLocation()
    if (GetDistanceBetween(location, destination) == 0)
    {
      state = IN_GYM;
      current_gym -> AddOnePokemon();
      return true;
    }
    else
    {
      if (IsExhausted() == false)
      {
        state = MOVING_TO_GYM;
        return false;
      }
      else
      {
        state = EXHAUSTED;
        return true;
      }
    }
  }
  else if (state == IN_CENTER)
  {
    if (IsExhausted() == true)
    {
      state = EXHAUSTED;
      current_center -> RemoveOnePokemon();
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (state == IN_GYM)
  {
    if (IsExhausted() == true)
    {
      state = EXHAUSTED;
      current_gym -> RemoveOnePokemon();
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (state == TRAINING_IN_GYM)
  {
    stamina = stamina - current_gym -> GetStaminaCost(training_units_to_buy); // if in gym, subtracts the stamina
    pokemon_dollars = pokemon_dollars - current_gym -> GetDollarCost(training_units_to_buy); // subtracts pokemon dollars
    experience_points = experience_points + current_gym -> TrainPokemon(training_units_to_buy); // gains experiance

    if (training_units_to_buy > 1)
    {
      cout << "** " << this -> name << " completed " << training_units_to_buy << " training units! **\n";
    }
    else
    {
      cout << "** " << this -> name << " completed " << training_units_to_buy << " training unit! **\n";
    }

    if (experience_points_gained > 1)
    {
      cout << "** " << this -> name << " gained " << experience_points_gained << " experience points! **\n";
    }
    else
    {
      cout << "** " << this -> name << " gained " << experience_points_gained << " experience point! **\n";
    }

    if (IsExhausted() == true)
    {
      state = EXHAUSTED;
      return true;
    }
    else
    {
      state = IN_GYM;
      return true;
    }
  }
  else if (state == RECOVERING_STAMINA)
  {
    stamina = stamina + current_center -> DistributeStamina(stamina_points_to_buy); // gains stamina
    pokemon_dollars = pokemon_dollars - current_center -> GetDollarCost(stamina_points_to_buy); // decreases pokemon dollars

    if (stamina_points_gained > 1)
    {
      cout << "** " << this -> name << " recovered " << stamina_points_gained << " stamina points! **\n";
    }
    else
    {
      cout << "** " << this -> name << " recovered " << stamina_points_gained << " stamina point! **\n";
    }

    state = IN_CENTER;
    return true;
  }
  else
  {
    return false;
  }
}

bool Pokemon::UpdateLocation() // updates the location of the pokemon
{
  if (IsExhausted() == false) // checks that pokemon is not exhausted
  {
    if (fabs(this -> location.x - this -> destination.x) == fabs(this -> delta.x) && fabs(this -> location.y - this -> destination.y) == fabs(this -> delta.y))
    {
      this -> location.x = this -> destination.x; // if at destination then location = destination
      this -> location.y = this -> destination.y;
      cout << this -> display_code << this -> id_num << ": I'm there!\n";
      return true;
    }
    else
    {
      this -> location.x = this -> location.x + delta.x; // if not at destination, goes to location by change in delta
      this -> location.y = this -> location.y + delta.y;
      stamina = stamina - 1;
      pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars(); // gets x amount of pokemon dollar when walking
      cout << this -> display_code << this -> id_num << ": step...\n";
      return false;
    }
  }
  else
  {
    cout << this -> display_code << this -> id_num << ": is exhausted.\n"; // exhaustion hits the pokemon
    return false;
  }
}

void Pokemon::SetupDestination(Point2D dest) // sets the destination for the pokemon
{
  destination = dest;
  if (GetDistanceBetween(this -> destination, this -> location) == 0)
  {
    delta.x = 0; // delta is 0 if already at destination
    delta.y = 0;
  }
  else
  {
    this -> delta.x = (destination.x - location.x) * (speed / GetDistanceBetween(this -> destination, this -> location)); // formular for delta according to the document
    this -> delta.y = (destination.y - location.y) * (speed / GetDistanceBetween(this -> destination, this -> location));
  }
}

double GetRandomAmountOfPokemonDollars()
{
  return ((double) round((((double)rand() / RAND_MAX) * (2 - 0) * 100)) / 100); // formulates an amount between 2.0 and 0
}

Pokemon::~Pokemon() // pokemon destructor
{
  cout << "Pokemon destructed.\n";
}
