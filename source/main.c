#include "game.h"

#include <chad.h>

int main(int ac , char ** av)
{ char * program_name = av[0];
  struct game game[1] = {0};
  global_game = game;

  change_directory(program_name);

  while (++av, --ac)
  { if (av[0][0] == '-')
    { while (av[0][0]
         &&  (++av[0])[0])
      { switch (av[0][0])
        { case 'd': game->debug = 1;
          case '-': goto noopt;
        }
      }
    }
  }
 noopt:

  init(game, program_name);

  loop(game);
  exit(0);
}
