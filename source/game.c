#include "game.h"

struct game * global_game;      /* Only for Deinit. */

/* Initialization */

void init(struct game * game, const char * program_name)
{ game->random[0] = random_init(dbg ? 0 : time(NULL));
  game->screen_area[0] = (v2) {1920, 1080 };

  rl_set_trace_log_level(LOG_ERROR);
  rl_set_config_flags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);

  if (rl_init_window2(game->screen_area[0], program_name))
  { atexit(rl_close_window);
    rl_toggle_fullscreen();
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

  game->screen = rl_load_render_texture_v2(game->screen_area[0]);
  if (rl_is_texture_valid(game->screen.texture))
  { void game_unload_screen(void);
    atexit(game_unload_screen);
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
{ game->number = 0;
}

/* Deinitialization */

void game_unload_screen(void)
{ rl_unload_render_texture(global_game->screen);
}

/* Game Loop */

void loop(struct game * game)
{ while (rl_window_open()) /* requires -s ASYNCIFY=1 for Emscripten */
  { void update(struct game * game);
    update(game);
    { rl_begin_drawing();
      void render(struct game * game);
      render(game);
    } rl_end_drawing();
  }
}

/* Update / Render Body */

void update(struct game * game)
{ if (!PLATFORM_WEB)
  { rl_set_target_fps(rl_is_window_focused() ? 60 : 10);
  }
  game->physical_area[0] = rl_get_render_area();
}

void render(struct game * game)
{ rl_draw_texture_pro(game->screen.texture,
                      (Rectangle) {0, 0, game->screen.texture.width, game->screen.texture.height },
                      (Rectangle) {0, 0, game->physical_area->x, game->physical_area->y},
                      (v2){0,0},
                      0,
                      WHITE);
  rl_draw_text_ex(game->font, "Cogito Ergo Sum", Vector2Divide(game->screen_area[0], (v2){2,2}), 13, 0, WHITE);
}
