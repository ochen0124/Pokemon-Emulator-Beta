#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "GameCommand.h"
#include "Model.h"
#include "View.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

using namespace std;

int main()
{
  cout << "EC327: Introduction to Software Engineering\n";
  cout << "Fall 2019\n";
  cout << "Programming Assignment 3\n";
  cout << "                                  ,'\\ \n";
  cout << "   _.----.        ____         ,'  _\\   ___    ___     ____ \n";
  cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. \n";
  cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | \n";
  cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | \n";
  cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | \n";
  cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | \n";
  cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | \n";
  cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | \n";
  cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | \n";
  cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | \n";
  cout << "                                `'                            '-._| \n";
  srand(time(NULL)); // used for time
  int Id1;
  int Id2;
  double x;
  double y;
  unsigned int stamina_amount;
  unsigned int unit_amount;
  char input; // user input variable
  Model model = Model();
  View view = View();
  model.Display(view);

  while (input != 'q') // while the user doesn't quit, ask for input
  {
    cout << "Enter Command: ";
    cin >> input;
    if (input == 'm') // user commands with actions based on document
    {
      cin >> Id1;
      cin >> x;
      cin >> y;
      DoMoveCommand(model, Id1, Point2D(x,y));
    }
    else if (input == 'g')
    {
      cin >> Id1;
      cin >> Id2;
      DoMoveToGymCommand(model, Id1, Id2);
    }
    else if (input == 'c')
    {
      cin >> Id1;
      cin >> Id2;
      DoMoveToCenterCommand(model, Id1, Id2);
    }
    else if (input == 's')
    {
      cin >> Id1;
      DoStopCommand(model, Id1);
    }
    else if (input == 'r')
    {
      cin >> Id1;
      cin >> stamina_amount;
      DoRecoverInCenterCommand(model, Id1, stamina_amount);
    }
    else if (input == 't')
    {
      cin >> Id1;
      cin >> unit_amount;
      DoTrainInGymCommand(model, Id1, unit_amount);
    }
    else if (input == 'v')
    {
      DoGoCommand(model, view);
    }
    else if (input == 'x')
    {
      DoRunCommand(model, view);
    }
    else if (input == 'q')
    {
      return 0; // if user quits then return 0
    }
    else
    {
      cout << "Please enter a valid command\n"; // else asks for a proper command!
    }
  }
    return 0;
}
