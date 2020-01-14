#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include "string.h"
#include <iostream>

using namespace std;

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
  if (pokemon_id > 0 && pokemon_id <= 2) // if pokemon id is valid
  {
    Pokemon* PokemonPointer = model.GetPokemonPtr(pokemon_id); // uses a pointer for simplicity
    PokemonPointer -> StartMoving(p1); // moves the pokemon to the point
    cout << "Moving " << PokemonPointer -> PokemonName() << " to " << p1 << "\n"; // pokename functions comes in handy
  }
  else
  {
    cout << "Error: Please enter a valid command!\n"; // error checks if pokemon id is valid
  }
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id)
{
  if ((pokemon_id > 0 && pokemon_id <= 2) && (center_id > 0 && center_id <= 2)) // error checks for valid pokemon id and pokecenter id
  {
    Pokemon* PokemonPointer = model.GetPokemonPtr(pokemon_id);
    PokemonCenter* PokemonCenterPointer = Model.GetPokemonCenterPtr(center_id);
    PokemonPointer -> StartMovingToCenter(PokemonCenterPointer); // moves to pokecenter
    cout << "Moving " << PokemonPointer -> PokemonName() << " to center " << center_id << "\n";
  }
  else
  {
    cout << "Error: Please enter a valid command!\n";
  }
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)
{
  if ((pokemon_id > 0 && pokemon_id <= 2) && (gym_id > 0 && gym_id <= 2)) // checks for valid gym and pokemon id
  {
    Pokemon* PokemonPointer = model.GetPokemonPtr(pokemon_id);
    PokemonGym* PokemonGymPointer = Model.GetPokemonGymPtr(gym_id);
    PokemonPointer -> StartMovingToGym(PokemonGymPointer); // moves pokemon to the gym
    cout << "Moving " << PokemonPointer -> PokemonName() << " to gym " << gym_id << "\n";
  }
  else
  {
    cout << "Error: Please enter a valid command!\n";
  }
}


void DoStopCommand(Model& model, int pokemon_id)
{
    if (pokemon_id > 0 && pokemon_id <= 2)
    {
        Pokemon* PokemonPointer = model.GetPokemonPtr(pokemon_id);
        PokemonPointer -> Stop(); // tells pokemon to stop
        cout << "Stopping " << PokemonPointer -> PokemonName() << this -> display_code << this -> id_num << "\n";
    }
    else
    {
        cout << "Error: Please enter a valid command!\n";
    }
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)
{
  if (pokemon_id > 0 && pokemon_id <= 2)
  {
    Pokemon* PokemonPointer = model.GetPokemonPtr(pokemon_id);
    PokemonPointer -> StartTraining(training_units); // tells pokemon to train
    cout << "Training " << PokemonPointer -> PokemonName() << "\n";
  }
  else
  {
    cout << "Error: Please enter a valid command!\n";
  }
}


void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points)
{
  if (pokemon_id > 0 && pokemon_id <= 2)
  {
    Pokemon* PokemonPointer = model.GetPokemonPtr(pokemon_id);
    PokemonPointer -> StartRecoveringStamina(stamina_points); // tells pokemon to recover stamina in the center
    cout << "Recovering " << PokemonPointer -> PokemonName() << "'s stamina\n";
  }
  else
  {
    cout << "Error: Please enter a valid command!\n";
  }
}


void DoGoCommand(Model& model, View& view)
{
  cout << "Advancing one tick.\n";
  model.Update();
  model.Display(view);
}


void DoRunCommand(Model& model, View& view)
{
  cout << "Advancing one tick.\n";
  model.Update();
  model.Display(view);
}
