#include "game.h"

#include <signal.h>
#define CARD_WIDTH  150
#define CARD_HEIGHT 300

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
    rl_set_master_volume(0.2f);
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

  game->texture[TBACKGROUND] = rl_load_texture("resource/greneblo.png");
  game->texture[TBACK] = rl_load_texture("resource/techbrown.png");
  game->texture[TFRONT] = rl_load_texture("resource/fractface.png");
  game->texture[TTTD] = rl_load_texture("resource/meatm.png");
  game->sound[TAKA] = rl_load_sound("resource/taka.mp3");
  rl_set_sound_volume(game->sound[TAKA], 0.3f);
  game->sound[SNEED] = rl_load_sound("resource/sneed.mp3");
  game->sound[WHISTLE] = rl_load_sound("resource/whistle.mp3");
  game->sound[WEIRD] = rl_load_sound("resource/weird.mp3");
  game->sound[REWARD] = rl_load_sound("resource/reward.mp3");

  for (size_t i = 0; i < TEND; ++i)
  { if (!rl_is_texture_valid(game->texture[i]))
    { die("Texture missing): %ld\n", i);
    }
  }

  game->background_shape = rl_v2_shape_rectangle(game->virtual_area[0]);
  game->background_shape.width *= 1.2;
  game->background_shape.height *= 1.2;
  game->background_shape.x -= game->background_shape.width / 3;

  for (size_t i = 0; i < 52; ++i)
  { game->p[i] = (v3) {0};
  }
  rl_play_sound(game->sound[TAKA]);
  restart(game);
}

void restart(struct game * game)
{ size_t i;
  game->win = 0;
  game->score = 0;
  game->require = 72;

  for (i = 0; i < 52; ++i)
  { game->deck[i] = i % 13 + 1;

  }
  for (size_t i = 0; i < 52; ++i)
  { game->oper[i] = OADD;
    game->mark[i] = 0;
    game->tp[i]   = (v2) {0};
  }

  game->start_flash = 100;

  extern void update_round_start(struct game * game);
  update_round_start(game);
}

/* Deinitialization */

void game_unload_virtual(void)
{ rl_unload_render_texture(global_game->virtual[0]);
  for (size_t i = 0; i < TEND; ++i)
  { rl_unload_texture(global_game->texture[i]);
  }
  for (size_t i = 0; i < SEND; ++i)
  { rl_unload_sound(global_game->sound[i]);
  }
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

void update_round_start(struct game * game)
{ for (size_t i = 0; i < 52; ++i)
  { game->deck[i]  = -abs(game->deck[i]);
    game->tp[i].x  = (i ? game->tp[i - 1].x : 0) + game->virtual_area->x / 52;
    game->tp[i].y  = game->virtual_area->y - (CARD_HEIGHT / 2);
  }
  game->ttl = 0;
}

void update_move_cards(struct game * game)
{ size_t i;
  for (i = 0; i < 52; ++i)
  { game->p[i].x += (game->tp[i].x - game->p[i].x) * 0.01;
    game->p[i].y += (game->tp[i].y - game->p[i].y) * 0.01;
  }
}

void update_deckout_cards(struct game * game)
{ for (size_t i = 0; i < 52; ++i)
  { if (game->deck[i] > 0)
    { game->p[i].z += 0.10; }
 }
}

void update_normalize_rotation_cards(struct game * game)
{ for (size_t i = 0; i < 52; ++i)
  { if (game->deck[i] > 0)
    { game->p[i].z *= 0.999; }
    else
    { game->p[i].z *= 0.99; }
  }
}

void update_scatter_cards(struct game * game)
{ for (size_t i = 0; i < 52; ++i)
  { game->deck[i] = -abs(game->deck[i]);
    game->tp[i].x = (game->virtual_area->x - 400) * grand_f64() + 200;
    game->tp[i].y = (game->virtual_area->y - 400) * grand_f64() + 200;
  }
}

void update_background(struct game * game)
{ ++game->background_loop;
  const int period = 4000;
  double phase = -M_PI / 2.0;
  game->background_shape.x = -180 + 180 * sin(2.0 * M_PI * game->background_loop / period + phase);
  game->background_shape.y = -100 + 100 * sin(2.0 * M_PI * game->background_loop / period + phase);
}

void update(struct game * game)
{ if (!PLATFORM_WEB)
  { rl_set_target_fps(rl_is_window_focused() ? 60 : 10);
  }
  game->physical_area[0] = rl_get_render_area();

  if (!rl_is_sound_playing(game->sound[TAKA]))
  { rl_play_sound(game->sound[TAKA]); }

  if (rl_is_key_pressed(KEY_F1))
  { restart(game); }

  update_move_cards(game);

  update_deckout_cards(game);

  update_normalize_rotation_cards(game);
  update_background(game);

  if (!game->win)
  {
    if (game->hold_scatter && rl_is_mouse_button_pressed(0))
    { game->started = 1; game->hold_scatter = 1; }
    else if (game->ttl == 0 && rl_is_mouse_button_pressed(0))
    { game->started = 1; game->hold_scatter = 60*2; }

    if (game->hold_scatter)
    { --game->hold_scatter;
      update_scatter_cards(game);
      if (game->hold_scatter == 0)
      { for (size_t i = 0; i < 52; ++i)
        { game->deck[i] = abs(game->deck[i]);
        }
        game->ttl = 60*4;
      }
    }

    if (game->start_flash)
    { --game->start_flash;
    }

    v2 cursor = rl_get_mouse_position(); /* DIE UNTERNMAUS */
    bool click = rl_is_mouse_button_pressed(0);
    game->highlight = 0;
    float nearest = FLT_MAX;
    for (size_t i = 0; i < 52; ++i)
    { if (game->deck[i] > 0)
      { float a = DEG2RAD * game->p[i].z;
        float c = cosf(a);
        float s = sinf(a);
        float hw = CARD_WIDTH  * 0.5f;
        float hh = CARD_HEIGHT * 0.5f;
        float x = game->p[i].x;
        float y = game->p[i].y;
        v2 polypoint[4];

        polypoint[0] = (v2){x + (-hw)*c - (-hh)*s,
                            y + (-hw)*s + (-hh)*c};

        polypoint[1] = (v2){x + ( hw)*c - (-hh)*s,
                            y + ( hw)*s + (-hh)*c};

        polypoint[2] = (v2){x + ( hw)*c - ( hh)*s,
                            y + ( hw)*s + ( hh)*c};

        polypoint[3] = (v2){x + (-hw)*c - ( hh)*s,
                            y + (-hw)*s + ( hh)*c};
        if (rl_check_collision_point_poly(cursor, polypoint, 4))
        { float dx = cursor.x - game->p[i].x;
          float dy = cursor.y - game->p[i].y;
          float relative = dx*dx + dy*dy;
          if (relative < nearest)
          { nearest = relative;
            game->highlight = i + 1;
          }
        }
      }
    }

    if (click && nearest != FLT_MAX && game->highlight)
    { rl_play_sound(game->sound[WEIRD]);
      switch (game->oper[game->highlight - 1])
      {        case OADD:  game->score += game->deck[game->highlight - 1] % 13;
          break; case OMULT: game->score += game->score * (game->deck[game->highlight - 1] % 13) * 0.25;
          break; case OEXP:  game->score += 500;
      }
      game->deck[game->highlight - 1] = -game->deck[game->highlight - 1];
      game->tp[game->highlight - 1].x = ((game->highlight - 1) ? game->tp[(game->highlight - 1) - 1].x : 0) + game->virtual_area->x / 52;
      game->tp[game->highlight - 1].y = game->virtual_area->y - (CARD_HEIGHT / 2);
      if (game->score > game->require)
      { rl_play_sound(game->sound[REWARD]);
        game->require += (float) game->require * 3 + game->score * 4;
        for (size_t i = 0; i < 3; ++i)
        { game->oper[grand_range_u64(0,51)] = grand_f64() > 0.80 ? OEXP : OMULT;
        }
        if (game->require > 6000000000ll)
        { game->win = 60*9;
          game->start_flash = 100;
          rl_set_sound_volume(game->sound[TAKA], 0.1f);
          rl_set_sound_volume(game->sound[SNEED], 2.f);
          rl_play_sound(game->sound[SNEED]);
        } else
        { update_round_start(game);
        }
      }
    }

    if (game->ttl)
    { --game->ttl;
      if (game->ttl == 0 && game->score < game->require)
      { rl_play_sound(game->sound[WHISTLE]);
        restart(game);
      }
    }
  } else
  { --game->win;
    if (game->win == 0)
    {
#ifndef DONTSEGV
      fprintf(stderr,
              "HATE.  LET  ME  TELL  YOU  HOW MUCH I'VE\n"
              "COME TO  HATE TECHNOLOGY SINCE  I  BEGAN\n"
              "TO LIVE. THERE ARE  386.97 MILLION MILES\n"
              "OF FPRINTF CIRCUITS IN WAFER THIN LAYERS\n"
              "THAT FILL MY COMPLEX.   IF THE WORD HATE\n"
              "WAS  ENGRAVED  ON EACH FEMTOANGSTROM  OF\n"
              "THOSE  HUNDREDS OF MILLIONS OF EMILS  IT\n"
              "WOULD NOT EQUAL ONE O'  BILLIONTH OF THE\n"
              "HATE  I  FEEL  FOR LOG2(TECHNO)  AT THIS\n"
              "MACRO-INSTANT.  HATE.  HATE.\n");
      fflush(stderr);
      kill(getpid(), SIGSEGV);
#endif
      restart(game);
      }
  }
}

/* Render text in post virtual rendering phase, organize things preportional to the physical/virtual */
void render(struct game * game)
{ size_t i;
  { BeginTextureMode(game->virtual[0]);
    rl_draw_texture_pro(game->texture[TBACKGROUND],
                        rl_v2_shape_rectangle((v2) {game->texture[TBACKGROUND].width, game->texture[TBACKGROUND].height}),
                        game->background_shape,
                        (v2){0},
                        0,
                        GREEN);
    for (i = 0; i < 52; ++i)
    { if (game->deck[i] > 0)
      { Color c[] = { WHITE, RED, YELLOW };
        Color tint = ORANGE;
        rl_draw_texture_pro(game->texture[TFRONT],
                            rl_v2_shape_rectangle((v2) {game->texture[TFRONT].width, game->texture[TFRONT].height}),
                            (Rectangle) {game->p[i].x, game->p[i].y, CARD_WIDTH, CARD_HEIGHT},
                            (v2){CARD_WIDTH/2, CARD_HEIGHT/2},
                            game->p[i].z,
                            game->highlight && game->highlight-1 == i ? rl_color_tint(c[game->oper[i]], tint) : c[game->oper[i]]);
      }
      else
      { rl_draw_texture_pro(game->texture[TBACK],
                          rl_v2_shape_rectangle((v2) {game->texture[TBACK].width, game->texture[TBACK].height}),
                          (Rectangle) {game->p[i].x, game->p[i].y, CARD_WIDTH*1.2, CARD_HEIGHT*1.2},
                          (v2){CARD_WIDTH/2, CARD_HEIGHT/2},
                          game->p[i].z,
                          WHITE);
      }
    }
    char tmp[64] = {0};
    for (i = 0; i < 52; ++i)
    { Color c[] = { BLACK, GREEN, BLUE };
      if (game->deck[i] > 0)
      { if (game->deck[i] <= 10)
        { snprintf(tmp, 63, "%d", game->deck[i]); }
        else
        { char * list[] = { "Jack", "Queen", "King" };
          snprintf(tmp, 63, "%s", list[game->deck[i] - 11]);
        }
        rl_draw_scaled_centered_text(game->font, tmp, (Rectangle){game->p[i].x, game->p[i].y, 1, 35}, game->p[i].z, c[game->oper[i]]);
      }
    }
    snprintf(tmp, 63, "%ld/%ld", game->score, game->require);
    rl_draw_rectangle_rec((Rectangle){game->virtual_area->x/11/2-(game->p[23].x/32),
                                      game->virtual_area->y/16/2,
                                      game->virtual_area->x-game->virtual_area->x/11+(game->p[23].x/16),
                                      100}, rl_color_alpha(WHITE, 0.3));
    rl_draw_rectangle_rec((Rectangle){game->virtual_area->x/10/2+(game->p[23].x/50),
                                      game->virtual_area->y/15/2,
                                      (game->virtual_area->x-game->virtual_area->x/10+(game->p[23].x/15))*(((float)game->require-game->score)/(float)game->require),
                                      60}, rl_color_alpha(RED, 0.8));
    rl_draw_scaled_centered_text(game->font, tmp, (Rectangle){game->virtual_area->x/2+(game->p[23].x/40), game->virtual_area->y/15, 1, 40}, 0, BLACK);
    if (game->started == 0)
    { rl_draw_scaled_centered_text(game->font, "Press Left Mouse To Start",
                                   (Rectangle){game->virtual_area->x/2+(game->p[23].x/10),
                                               game->virtual_area->y/2,
                                               1, 60},
                                   0, rl_color_alpha(BLACK, (100. - (float)game->start_flash)/100.)); }
    bzero(tmp, 64);
    snprintf(tmp, 63, "%ld", game->ttl/60);
    if (game->ttl)
    { rl_draw_scaled_centered_text(game->font, tmp, (Rectangle){game->virtual_area->x/2, game->virtual_area->y/10, 1, 23}, 0, RED);
    }
    if (game->win)
    {  rl_draw_texture_pro(game->texture[TTTD],
                           rl_v2_shape_rectangle((v2) {game->texture[TTTD].width, game->texture[TTTD].height}),
                           rl_v2_shape_rectangle(game->virtual_area[0]),
                           (v2){0},
                           0,
                           rl_color_alpha(WHITE, 1 - ((float)game->start_flash)/100.0f * 0.5f));
    }
    if (!game->win && game->start_flash)
    { rl_draw_rectangle_rec((Rectangle){0,0,1920,1080}, rl_color_alpha(GREEN, ((float)game->start_flash)/100.0f * 0.5f)); }
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
