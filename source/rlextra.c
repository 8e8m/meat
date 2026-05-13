#include "rlextra.h"

void rl_init_window_v2(const v2 area_maybe, const char * name)
{ rl_init_window(area_maybe.x, area_maybe.y, name); }

rl_screen rl_load_render_texture_v2(const v2 area)
{ return rl_load_render_texture(area.x, area.y); }

v2 rl_get_render_area(void)
{ return (v2) {GetRenderHeight(), GetRenderWidth() }; }

bool rl_init_window2(const v2 area_maybe, const char * name)
{ rl_init_window_v2(area_maybe, name);
  return rl_is_window_ready();
}

bool rl_init_audio_device2(void)
{ rl_init_audio_device();
  return rl_is_audio_device_ready();
}

bool rl_window_open(void)
{ return !rl_window_should_close();
}
