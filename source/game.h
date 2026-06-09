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

enum
{ TBACKGROUND,
  TBACK,
  TFRONT,
  TTTD,
  TEND,
};

enum
{ TAKA,
  SNEED,
  WHISTLE,
  REWARD,
  WEIRD,
  SEND,
};

enum
{ OADD,
  OMULT,
  OEXP,
};

struct game
{ bool debug;                   /* DEBUGGING! :( */
  rl_screen virtual[1];         /* Drawarea everything we want to scale to the screen should be drawn to  */
  v2 virtual_area[1];           /* (Effectively Constant) virtual area : upscaled (stretched) to the physical area */
  v2 physical_area[1];          /* resizable actual window */
  rl_font font;
  rl_texture texture[TEND];
  rl_sound sound[SEND];
  /* All Zerod On Restart:       */
  i64 score, require, ttl, started, start_flash;
  i32 deck[52];                 /* sign determines side (positive: show, negative: hide */
  i32 oper[52];                 /* obviously bit encodable */
  i32 mark[52];
  v3 p[52];
  v2 tp[52];
  u32 highlight;
  Rectangle background_shape;
  size_t background_loop;
  u32 win, hold_scatter;
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
