#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H

#include "Building.h"
#include "GameObject.h"
#include "Point2D.h"

enum PokemonCenterStates // if stamina available = 0, else = 1
{
  STAMINA_POINTS_AVAILABLE = 0,
  NO_STAMINA_POINTS_AVAILABLE = 1
};

class PokemonCenter: public Building
{
private:
  unsigned int stamina_capacity;

  unsigned int num_stamina_points_remaining;

  double dollar_cost_per_stamina_point;
public:
  PokemonCenter();

  PokemonCenter(int, double, unsigned int, Point2D);

  bool HasStaminaPoints();

  unsigned int GetNumStaminaPointsRemaining();

  bool CanAffordStaminaPoints(unsigned int, double);

  unsigned int DistributeStamina(unsigned int);

  bool Update();

  void ShowStatus();
};

#endif
