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

/* Consistencies */
void rl_init_window_v2(const v2 area_maybe, const char * name);
rl_screen rl_load_render_texture_v2(const v2 area);
v2 rl_get_render_area(void);

/* Different Interfaces */
bool rl_init_window2(const v2 area_maybe, const char * name);
bool rl_init_audio_device2(void);
bool rl_window_open(void);

#endif  /* RLEXTRA_H_ */
