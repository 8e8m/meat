#include <chad.h>
#include "rlextra.h"

void rl_init_window_v2(const v2 area_maybe, const char * name)
{ rl_init_window(area_maybe.x, area_maybe.y, name); }

rl_screen rl_load_render_texture_v2(const v2 area)
{ return rl_load_render_texture(area.x, area.y); }

v2 rl_get_render_area(void)
{ return (v2) {rl_get_render_width(), rl_get_render_height() }; }

bool rl_init_window2(const v2 area_maybe, const char * name)
{ rl_init_window_v2(area_maybe, name);
  return rl_is_window_ready();
}

bool rl_init_audio_device2(void)
{ rl_init_audio_device();
  return rl_is_audio_device_ready();
}

bool rl_window_open(void)
{ return !rl_window_should_close(); }

v4 rl_rectangle_v4(Rectangle rect)
{ return (v4) { rect.x, rect.y, rect.width, rect.height }; }

Rectangle rl_v4_rectangle(v4 v)
{ return (Rectangle) { v.x, v.y, v.z, v.w }; }

Rectangle rl_source_texture(const Texture * texture)
{ return (Rectangle) { 0, 0, texture->width, texture->height }; }

/* (x, y) is origin, (width, height) is scale, negative scale inverts image. */
void rl_draw_centered_texture(const Texture * texture, Rectangle source, Rectangle project, float degree, Color color)
{ v4 target = rl_rectangle_v4(source);
  v4 scale = (v4) {
    1,
    1,
    project.width / fabsf(project.width),
    project.height / fabsf(project.height),
  };
  DrawTexturePro(*texture,
                 rl_v4_rectangle(rl_vector4_multiply(target, scale)),
                 (Rectangle) {
                   project.x,
                   project.y,
                   texture->width * fabsf(project.width),
                   texture->height * fabsf(project.height)
                 },
                 (Vector2) {
                   texture->width * 0.5f,
                   texture->height * 0.5f
                 },
                 degree, color);
}

void rl_draw_centered_wrapped_texture(const Texture *texture, Rectangle source, Rectangle project, Rectangle box, float degree, Color color)
{ const float w = texture->width  * fabsf(project.width);
  const float h = texture->height * fabsf(project.height);
  const float hw = w * 0.5f;
  const float hh = h * 0.5f;

  float xoff = 0.0f;
  float yoff = 0.0f;

  if (project.x - hw < 0.0f)
    xoff = box.x;
  else if (project.x + hw > box.x)
    xoff = -box.x;

  if (project.y - hh < 0.0f)
    yoff = box.y;
  else if (project.y + hh > box.y)
    yoff = -box.y;

  rl_draw_centered_texture(texture, source, project, degree, color);

  if (xoff != 0.0f)
    rl_draw_centered_texture(texture, source, (Rectangle){ project.x + xoff, project.y, project.width, project.height }, degree, color);

  if (yoff != 0.0f)
    rl_draw_centered_texture(texture, source, (Rectangle){ project.x, project.y + yoff, project.width, project.height }, degree, color);

  if (xoff != 0.0f && yoff != 0.0f)
    rl_draw_centered_texture(texture, source, (Rectangle){ project.x + xoff, project.y + yoff, project.width, project.height }, degree, color);
}

void rl_draw_scaled_text(Font font, const char * text, v2 position, v2 origin, float degree, int font_size, int spacing, Color color)
{ v2 dpi = GetWindowScaleDPI();
  font_size *= dpi.y;
  spacing *= dpi.x;
  DrawTextPro(font,
              text,
              position,
              origin,
              degree,
              font_size,
              spacing,
              color);
}

void rl_draw_scaled_centered_text(Font font, const char * text, Rectangle project, float degree, Color color)
{ float font_size = fabsf(project.height);
  float spacing   = project.width;

  Vector2 size = MeasureTextEx(font, text, font_size, spacing);

  rl_draw_scaled_text(font,
              text,
              (Vector2) { project.x, project.y },
              (Vector2) { size.x * 0.5f, size.y * 0.5f },
              degree,
              font_size,
              spacing,
              color);
}

/* This has made me astronomically angry. */
v4 rl_fit_centered(v2 fit, v2 inside)
{ float scale =
    inside.x / fit.x < inside.y / fit.y
    ? inside.x / fit.x
    : inside.y / fit.y;
  float width = fit.x * scale;
  float height = fit.y * scale;
  return
    (v4){ (inside.x - width) * 0.5f,
          (inside.y - height) * 0.5f,
          width, height };
}
