#ifndef    GAME_H_
#define    GAME_H_

#ifndef PLATFORM_WEB
# define PLATFORM_WEB 0
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <strings.h>
#include <stddef.h>
#include <time.h>

/* automatically renamed raylib functions, by function redirection */
#include <rl.h>
#include <rlm.h>
#include "rlextra.h"

#include "terry.h"              /* https://github.com/BasedProject/terry-h */
#include "photon.h"             /* https://github.com/BasedProject/librandom */

struct game
{ bool debug;                   /* DEBUGGING! :( */
  rl_screen screen;             /* Area everything we want to scale to the screen should be drawn to  */
  v2 screen_area[1];            /* (Effectively Constant) screen area : drawn upscaled & centered in the physical area */
  v2 physical_area[1];          /* resizable actual window */
  photon_t random[1];           /* MT19937 moving random seed via https://github.com/BasedProject/librandom */
  rl_font font;
  /* All Zerod On Restart:       */
  u64 number;                   /* "Incremental" Game Number. */
};

void loop(struct game * game);
void init(struct game * game, const char * program_name);
void restart(struct game * game);

extern struct game * global_game; /* don't use this */

/* libc rand() considered no fun. */
#define rand() random(game->random)

#define dbg (game->debug)

#define warn(...) fprintf(stderr, __VA_ARGS__)

#define die(...)                  \
  do {                            \
    warn(__VA_ARGS__);            \
    exit(1);                      \
  } while (0)

#endif  /* GAME_H_ */
