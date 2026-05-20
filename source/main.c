#include "game.h"

#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
int change_directory(const char * filename)
{ struct stat statistics;
  char path[PATH_MAX];
  if (!filename) { return -1; }
  strncpy(path, filename, PATH_MAX-1);
  if (stat(path, &statistics)) { return -1; }
  if (!S_ISDIR(statistics.st_mode)) {
    char * terminator = strrchr(path, '/');
    if (!terminator) { return -1; }
    *terminator = '\0';
  }
  return chdir(path);
}

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
