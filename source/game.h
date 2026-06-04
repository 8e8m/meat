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

#include "terry.h"             /* https://github.com/BasedProject/terry */
#include <chad.h>              /* https://github.com/BasedProject/libchad */

enum { TILE_HORIZONTAL, TILE_VERTICAL, TILE_CORNER, TILE_EMPTY, TILE_BLOCK,
       /* ^-- */                                    /* tile fundamentals */
       SELECT_CORNER,                               /* select corner */
       SDM,                                         /* SDM, if the "player" touches this the game is lost. */
       UP_DOOR, DOWN_DOOR,                          /* doorways */
       PLAYER,                                      /* the "player" */
       NEWT, FISH, RAT, LAMBDA, SKEL, POLY,         /* enemies */
       END_BEING,
       LANDMINE, SPIKE,                             /* traps */
       TEXTURE_END };

typedef struct
{ int display;                       /* BEGIN_BEING < x < END_BEING */
  u8 health;
  u8 damage, resist;            /* health -= MIN(damage - resist, 0); */
  u8 speed;                     /* number of tiles traversable / attacks doable in a turn */
  float crit;                   /* 0..1, 2x, ignore resist. */
  u8 xp;                        /* xp reward to player */
  u16 cost;                     /* reward / investment cost */
} being_t;

#define MAX_BEINGS 64
#define MAX_BLOCKS 4
#define MAX_PIPES 8
#define MAX_LAYERS 3

struct game
{ bool debug;                   /* DEBUGGING! :( */
  rl_screen virtual[1];         /* Drawarea everything we want to scale to the screen should be drawn to  */
  v2 virtual_area[1];           /* (Effectively Constant) virtual area : upscaled (stretched) to the physical area */
  v2 physical_area[1];          /* resizable actual window */
  rl_font font;
  /* All Zerod On Restart:       */
  u64 gold, xp;                 /* gold of the dungeon, xp of "player" */
  being_t beings[MAX_LAYERS][MAX_BEINGS];
  v4 blocks[MAX_LAYERS][MAX_BLOCKS];
  v3 pipes[MAX_LAYERS][MAX_PIPES];
};

void loop(struct game * game);
void init(struct game * game, const char * program_name);
void restart(struct game * game);

extern struct game * global_game; /* don't use this */

#define dbg (game->debug)

#define warn(...) fprintf(stderr, __VA_ARGS__)

#define die(...)                  \
  do {                            \
    warn(__VA_ARGS__);            \
    exit(1);                      \
  } while (0)

#endif  /* GAME_H_ */
