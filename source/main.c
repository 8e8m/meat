#include "game.h"

struct game * global_game;

void game_unload_screen(void)
{ rl_unload_render_texture(global_game->screen); }

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

}

void loop(struct game * game)
{ while (rl_window_open()) /* requires -s ASYNCIFY=1 for Emscripten */
  { update(game);
    { rl_begin_drawing();
      render(game);
    } rl_end_drawing();
  }
}

void restart(struct game * game)
{ game->number = 0;
}

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
  { fputs("No Window :(\n", stderr);
    exit(1);
  }

  if (rl_init_audio_device2())
  { atexit(rl_close_audio_device);
    rl_set_master_volume(0.1f);
  }
  else
  { fputs("No Audio :(\n", stderr);
  }

  game->screen = rl_load_render_texture_v2(game->screen_area[0]);
  if (rl_is_texture_valid(game->screen.texture))
  { atexit(game_unload_screen);
  }
  else
  { fputs("No Render Texture :(\n", stderr);
    exit(1);
  }

  restart(game);
}

int main(int ac , char ** av)
{ char * program_name = av[0];
  struct game game[1] = {0};
  global_game = game;

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
