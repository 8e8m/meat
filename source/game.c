#include "game.h"

const being_t init_table[END_BEING-PLAYER] =
  {
    /* The soon to be Ubermensch. */
    {PLAYER,  20,  3,  2, 1,  1/10, 0,   20},
    /* nearly harmless, dependant on swarms and crits */
    {NEWT,     1,  1,  1, 3,   1/2, 1,   -2},
    /* like newts but with with a smell and a backbone */
    {FISH,    10,  3,  2, 1,   1/4, 3,   -5},
    /* The masterclass in being troublesome */
    {RAT,      5,  2,  3, 3, 1/100, 5,   -3},
    /* The masterclass in beatdowns */
    {LAMBDA,  40, 10,  5, 2,  1/10, 20,  -80},
    /* (You.) */
    {SKEL,   100, 20, 20, 3,   1/5, 100,   -1},
    /* Polymorph. Transmutes into something random from the above each turn,
     * besides you of course (you're irreplaceable.) */
    {POLY,     1,  1,  1, 1,   1/1, 50,  -20},
  }
  ;

/* magic table of factors that modulates the value of the upgrade action. */
const float init_factor[8] = {1.5, 1.2, 1.1, 1, 1/100, 1, 1.2, 2};

const char glyph[TEXTURE_END+1] =
  "-|+ "
  "X"
  "&"
  "<>"
  "@:Frλx?"
  "."
  "^_";

being_t table[sizeof(init_table) / sizeof(init_table[0])];
float factor[sizeof(init_factor) / sizeof(init_factor[0])];

struct game * global_game;      /* Only for Deinit. */

/* Initialization */

void init(struct game * game, const char * program_name)
{ game->virtual_area[0] = (v2) {1920, 1080 };

  rl_set_trace_log_level(LOG_ERROR);
  rl_set_config_flags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);

  if (rl_init_window2(game->virtual_area[0], program_name))
  { atexit(rl_close_window);
    /* rl_toggle_fullscreen(); */
  }
  else
  { die("No Window :(\n");
  }

  if (rl_init_audio_device2())
  { atexit(rl_close_audio_device);
    rl_set_master_volume(0.1f);
  }
  else
  { warn("No Audio :(\n");
  }

  game->virtual[0] = rl_load_render_texture_v2(game->virtual_area[0]);
  if (rl_is_texture_valid(game->virtual->texture))
  { void game_unload_virtual(void);
    atexit(game_unload_virtual);
  }
  else
  { die("No Render Texture :(\n");
  }

  game->font = rl_load_font("resource/atkinson.ttf");
  if (!rl_is_font_valid(game->font))
  { warn("No Special Font Loaded :(\n");
    game->font = rl_get_font_default();
    if (!rl_is_font_valid(game->font))
    { die("No Normal Font Loaded? :(\n");
    }
  }

  restart(game);
}

void restart(struct game * game)
{ memcpy(table, init_table, sizeof(init_table) / sizeof(init_table[0]));
  memcpy(factor, init_factor, sizeof(init_factor) / sizeof(init_factor[0]));
  game->gold = 20;
  game->xp = 0;
  for (int i = 0; i < 3; ++i)
  { bzero(game->beings[i], sizeof(game->beings[i][0]) * MAX_BEINGS);
    bzero(game->blocks[i], sizeof(game->blocks[i][0]) * MAX_BLOCKS);
    bzero(game->pipes[i], sizeof(game->pipes[i][0]) * MAX_PIPES);
  }
}

/* Deinitialization */

void game_unload_virtual(void)
{ rl_unload_render_texture(global_game->virtual[0]);
}

/* Game Loop */

void loop(struct game * game)
{ while (rl_window_open()) /* requires -s ASYNCIFY=1 for Emscripten */
  { void update(struct game * game);
    update(game);
    void render(struct game * game);
    render(game);
  }
}

/* Update / Render Body */

void update(struct game * game)
{ if (!PLATFORM_WEB)
  { rl_set_target_fps(rl_is_window_focused() ? 60 : 10);
  }
  game->physical_area[0] = rl_get_render_area();
}

/* Render text in post virtual rendering phase, organize things preportional to the physical/virtual */
void render(struct game * game)
{ { BeginTextureMode(game->virtual[0]);
    rl_clear_background(WHITE);
  } EndTextureMode();
  { rl_begin_drawing();
    rl_clear_background(BLACK);
    rl_draw_texture_pro(game->virtual->texture,
                        (Rectangle){ 0, 0, game->virtual->texture.width, -game->virtual->texture.height },
                        rl_v4_rectangle(rl_fit_centered(game->virtual_area[0], game->physical_area[0])),
                        (v2){ 0, 0 },
                        0,
                        WHITE);
  } rl_end_drawing();
}
