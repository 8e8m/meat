#ifndef    RLEXTRA_H_
#define    RLEXTRA_H_

/* Stapling ontop raylib. Consistency functions, biases, and extras. */

#include <rl.h>
#include <rlm.h>

/* Raylib types aren't altered by redirection, so we'll define custom types here: */
typedef Vector2 v2;
typedef Vector3 v3;
typedef Vector4 v4;

typedef RenderTexture2D rl_screen;
typedef Texture2D rl_texture;
typedef Font rl_font;

/* Consistencies */
void rl_init_window_v2(const v2 area_maybe, const char * name);
rl_screen rl_load_render_texture_v2(const v2 area);
v2 rl_get_render_area(void);

/* Different Interfaces */
bool rl_init_window2(const v2 area_maybe, const char * name);
bool rl_init_audio_device2(void);
bool rl_window_open(void);

/* Proper Extra Functionality */
/* Textures */
/* project width/height is scale from identity (1,1) */
void rl_draw_centered_wrapped_texture(const Texture *texture, Rectangle source, Rectangle project, Rectangle box, float degree, Color color);
/* project width/height is font spacing (width) & size (height)  */
void rl_draw_centered_texture(const Texture * texture, Rectangle source, Rectangle project, float degree, Color color);
/* Font */
/* DPI adjusted font rendering */
void rl_draw_scaled_text(Font font, const char * text, v2 position, v2 origin, float degree, int font_size, int spacing, Color color);
void rl_draw_scaled_centered_text(Font font, const char * text, Rectangle project, float degree, Color color);
/* type conversions */
Rectangle rl_v4_rectangle(v4 v);
v4 rl_rectangle_v4(Rectangle rect);

/* Uncatagorized */
v4 rl_fit_centered(v2 fit, v2 inside);

#endif  /* RLEXTRA_H_ */
