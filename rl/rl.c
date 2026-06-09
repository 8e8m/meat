#include "rl.h"

/* -- raylib.h -- */

void rl_init_window(int width, int height, const char *title)
{ InitWindow(width, height, title); }

void rl_close_window(void)
{ CloseWindow(); }

bool rl_window_should_close(void)
{ return WindowShouldClose(); }

bool rl_is_window_ready(void)
{ return IsWindowReady(); }

bool rl_is_window_fullscreen(void)
{ return IsWindowFullscreen(); }

bool rl_is_window_hidden(void)
{ return IsWindowHidden(); }

bool rl_is_window_minimized(void)
{ return IsWindowMinimized(); }

bool rl_is_window_maximized(void)
{ return IsWindowMaximized(); }

bool rl_is_window_focused(void)
{ return IsWindowFocused(); }

bool rl_is_window_resized(void)
{ return IsWindowResized(); }

bool rl_is_window_state(unsigned int flag)
{ return IsWindowState(flag); }

void rl_set_window_state(unsigned int flags)
{ SetWindowState(flags); }

void rl_clear_window_state(unsigned int flags)
{ ClearWindowState(flags); }

void rl_toggle_fullscreen(void)
{ ToggleFullscreen(); }

void rl_toggle_borderless_windowed(void)
{ ToggleBorderlessWindowed(); }

void rl_maximize_window(void)
{ MaximizeWindow(); }

void rl_minimize_window(void)
{ MinimizeWindow(); }

void rl_restore_window(void)
{ RestoreWindow(); }

void rl_set_window_icon(Image image)
{ SetWindowIcon(image); }

void rl_set_window_icons(Image *images, int count)
{ SetWindowIcons(images, count); }

void rl_set_window_title(const char *title)
{ SetWindowTitle(title); }

void rl_set_window_position(int x, int y)
{ SetWindowPosition(x, y); }

void rl_set_window_monitor(int monitor)
{ SetWindowMonitor(monitor); }

void rl_set_window_min_size(int width, int height)
{ SetWindowMinSize(width, height); }

void rl_set_window_max_size(int width, int height)
{ SetWindowMaxSize(width, height); }

void rl_set_window_size(int width, int height)
{ SetWindowSize(width, height); }

void rl_set_window_opacity(float opacity)
{ SetWindowOpacity(opacity); }

void rl_set_window_focused(void)
{ SetWindowFocused(); }

int rl_get_screen_width(void)
{ return GetScreenWidth(); }

int rl_get_screen_height(void)
{ return GetScreenHeight(); }

int rl_get_render_width(void)
{ return GetRenderWidth(); }

int rl_get_render_height(void)
{ return GetRenderHeight(); }

int rl_get_monitor_count(void)
{ return GetMonitorCount(); }

int rl_get_current_monitor(void)
{ return GetCurrentMonitor(); }

Vector2 rl_get_monitor_position(int monitor)
{ return GetMonitorPosition(monitor); }

int rl_get_monitor_width(int monitor)
{ return GetMonitorWidth(monitor); }

int rl_get_monitor_height(int monitor)
{ return GetMonitorHeight(monitor); }

int rl_get_monitor_physical_width(int monitor)
{ return GetMonitorPhysicalWidth(monitor); }

int rl_get_monitor_physical_height(int monitor)
{ return GetMonitorPhysicalHeight(monitor); }

int rl_get_monitor_refresh_rate(int monitor)
{ return GetMonitorRefreshRate(monitor); }

Vector2 rl_get_window_position(void)
{ return GetWindowPosition(); }

Vector2 rl_get_window_scale_dpi(void)
{ return GetWindowScaleDPI(); }

void rl_set_clipboard_text(const char *text)
{ SetClipboardText(text); }

Image rl_get_clipboard_image(void)
{ return GetClipboardImage(); }

void rl_enable_event_waiting(void)
{ EnableEventWaiting(); }

void rl_disable_event_waiting(void)
{ DisableEventWaiting(); }

void rl_show_cursor(void)
{ ShowCursor(); }

void rl_hide_cursor(void)
{ HideCursor(); }

bool rl_is_cursor_hidden(void)
{ return IsCursorHidden(); }

void rl_enable_cursor(void)
{ EnableCursor(); }

void rl_disable_cursor(void)
{ DisableCursor(); }

bool rl_is_cursor_on_screen(void)
{ return IsCursorOnScreen(); }

void rl_clear_background(Color color)
{ ClearBackground(color); }

void rl_begin_drawing(void)
{ BeginDrawing(); }

void rl_end_drawing(void)
{ EndDrawing(); }

void rl_begin_mode2_d(Camera2D camera)
{ BeginMode2D(camera); }

void rl_end_mode2_d(void)
{ EndMode2D(); }

void rl_begin_mode3_d(Camera3D camera)
{ BeginMode3D(camera); }

void rl_end_mode3_d(void)
{ EndMode3D(); }

void rl_begin_texture_mode(RenderTexture2D target)
{ BeginTextureMode(target); }

void rl_end_texture_mode(void)
{ EndTextureMode(); }

void rl_begin_shader_mode(Shader shader)
{ BeginShaderMode(shader); }

void rl_end_shader_mode(void)
{ EndShaderMode(); }

void rl_begin_blend_mode(int mode)
{ BeginBlendMode(mode); }

void rl_end_blend_mode(void)
{ EndBlendMode(); }

void rl_begin_scissor_mode(int x, int y, int width, int height)
{ BeginScissorMode(x, y, width, height); }

void rl_end_scissor_mode(void)
{ EndScissorMode(); }

void rl_begin_vr_stereo_mode(VrStereoConfig config)
{ BeginVrStereoMode(config); }

void rl_end_vr_stereo_mode(void)
{ EndVrStereoMode(); }

VrStereoConfig rl_load_vr_stereo_config(VrDeviceInfo device)
{ return LoadVrStereoConfig(device); }

void rl_unload_vr_stereo_config(VrStereoConfig config)
{ UnloadVrStereoConfig(config); }

Shader rl_load_shader(const char *vsFileName, const char *fsFileName)
{ return LoadShader(vsFileName, fsFileName); }

Shader rl_load_shader_from_memory(const char *vsCode, const char *fsCode)
{ return LoadShaderFromMemory(vsCode, fsCode); }

bool rl_is_shader_valid(Shader shader)
{ return IsShaderValid(shader); }

int rl_get_shader_location(Shader shader, const char *uniformName)
{ return GetShaderLocation(shader, uniformName); }

int rl_get_shader_location_attrib(Shader shader, const char *attribName)
{ return GetShaderLocationAttrib(shader, attribName); }

void rl_set_shader_value(Shader shader, int locIndex, const void *value, int uniformType)
{ SetShaderValue(shader, locIndex, value, uniformType); }

void rl_set_shader_value_v(Shader shader, int locIndex, const void *value, int uniformType, int count)
{ SetShaderValueV(shader, locIndex, value, uniformType, count); }

void rl_set_shader_value_matrix(Shader shader, int locIndex, Matrix mat)
{ SetShaderValueMatrix(shader, locIndex, mat); }

void rl_set_shader_value_texture(Shader shader, int locIndex, Texture2D texture)
{ SetShaderValueTexture(shader, locIndex, texture); }

void rl_unload_shader(Shader shader)
{ UnloadShader(shader); }

Ray rl_get_screen_to_world_ray(Vector2 position, Camera camera)
{ return GetScreenToWorldRay(position, camera); }

Ray rl_get_screen_to_world_ray_ex(Vector2 position, Camera camera, int width, int height)
{ return GetScreenToWorldRayEx(position, camera, width, height); }

Vector2 rl_get_world_to_screen(Vector3 position, Camera camera)
{ return GetWorldToScreen(position, camera); }

Vector2 rl_get_world_to_screen_ex(Vector3 position, Camera camera, int width, int height)
{ return GetWorldToScreenEx(position, camera, width, height); }

Vector2 rl_get_world_to_screen2_d(Vector2 position, Camera2D camera)
{ return GetWorldToScreen2D(position, camera); }

Vector2 rl_get_screen_to_world2_d(Vector2 position, Camera2D camera)
{ return GetScreenToWorld2D(position, camera); }

Matrix rl_get_camera_matrix(Camera camera)
{ return GetCameraMatrix(camera); }

Matrix rl_get_camera_matrix2_d(Camera2D camera)
{ return GetCameraMatrix2D(camera); }

void rl_set_target_fps(int fps)
{ SetTargetFPS(fps); }

float rl_get_frame_time(void)
{ return GetFrameTime(); }

double rl_get_time(void)
{ return GetTime(); }

int rl_get_fps(void)
{ return GetFPS(); }

void rl_swap_screen_buffer(void)
{ SwapScreenBuffer(); }

void rl_poll_input_events(void)
{ PollInputEvents(); }

void rl_wait_time(double seconds)
{ WaitTime(seconds); }

void rl_set_random_seed(unsigned int seed)
{ SetRandomSeed(seed); }

int rl_get_random_value(int min, int max)
{ return GetRandomValue(min, max); }

void rl_unload_random_sequence(int *sequence)
{ UnloadRandomSequence(sequence); }

void rl_take_screenshot(const char *fileName)
{ TakeScreenshot(fileName); }

void rl_set_config_flags(unsigned int flags)
{ SetConfigFlags(flags); }

void rl_open_url(const char *url)
{ OpenURL(url); }

void rl_set_trace_log_level(int logLevel)
{ SetTraceLogLevel(logLevel); }

void rl_set_trace_log_callback(TraceLogCallback callback)
{ SetTraceLogCallback(callback); }

void rl_mem_free(void *ptr)
{ MemFree(ptr); }

void rl_unload_file_data(unsigned char *data)
{ UnloadFileData(data); }

bool rl_save_file_data(const char *fileName, const void *data, int dataSize)
{ return SaveFileData(fileName, data, dataSize); }

bool rl_export_data_as_code(const unsigned char *data, int dataSize, const char *fileName)
{ return ExportDataAsCode(data, dataSize, fileName); }

void rl_unload_file_text(char *text)
{ UnloadFileText(text); }

bool rl_save_file_text(const char *fileName, const char *text)
{ return SaveFileText(fileName, text); }

void rl_set_load_file_data_callback(LoadFileDataCallback callback)
{ SetLoadFileDataCallback(callback); }

void rl_set_save_file_data_callback(SaveFileDataCallback callback)
{ SetSaveFileDataCallback(callback); }

void rl_set_load_file_text_callback(LoadFileTextCallback callback)
{ SetLoadFileTextCallback(callback); }

void rl_set_save_file_text_callback(SaveFileTextCallback callback)
{ SetSaveFileTextCallback(callback); }

int rl_file_rename(const char *fileName, const char *fileRename)
{ return FileRename(fileName, fileRename); }

int rl_file_remove(const char *fileName)
{ return FileRemove(fileName); }

int rl_file_copy(const char *srcPath, const char *dstPath)
{ return FileCopy(srcPath, dstPath); }

int rl_file_move(const char *srcPath, const char *dstPath)
{ return FileMove(srcPath, dstPath); }

int rl_file_text_replace(const char *fileName, const char *search, const char *replacement)
{ return FileTextReplace(fileName, search, replacement); }

int rl_file_text_find_index(const char *fileName, const char *search)
{ return FileTextFindIndex(fileName, search); }

bool rl_file_exists(const char *fileName)
{ return FileExists(fileName); }

bool rl_directory_exists(const char *dirPath)
{ return DirectoryExists(dirPath); }

bool rl_is_file_extension(const char *fileName, const char *ext)
{ return IsFileExtension(fileName, ext); }

int rl_get_file_length(const char *fileName)
{ return GetFileLength(fileName); }

long rl_get_file_mod_time(const char *fileName)
{ return GetFileModTime(fileName); }

int rl_make_directory(const char *dirPath)
{ return MakeDirectory(dirPath); }

bool rl_change_directory(const char *dirPath)
{ return ChangeDirectory(dirPath); }

bool rl_is_path_file(const char *path)
{ return IsPathFile(path); }

bool rl_is_file_name_valid(const char *fileName)
{ return IsFileNameValid(fileName); }

FilePathList rl_load_directory_files(const char *dirPath)
{ return LoadDirectoryFiles(dirPath); }

FilePathList rl_load_directory_files_ex(const char *basePath, const char *filter, bool scanSubdirs)
{ return LoadDirectoryFilesEx(basePath, filter, scanSubdirs); }

void rl_unload_directory_files(FilePathList files)
{ UnloadDirectoryFiles(files); }

bool rl_is_file_dropped(void)
{ return IsFileDropped(); }

FilePathList rl_load_dropped_files(void)
{ return LoadDroppedFiles(); }

void rl_unload_dropped_files(FilePathList files)
{ UnloadDroppedFiles(files); }

unsigned int rl_get_directory_file_count(const char *dirPath)
{ return GetDirectoryFileCount(dirPath); }

unsigned int rl_get_directory_file_count_ex(const char *basePath, const char *filter, bool scanSubdirs)
{ return GetDirectoryFileCountEx(basePath, filter, scanSubdirs); }

unsigned int rl_compute_crc32(const unsigned char *data, int dataSize)
{ return ComputeCRC32(data, dataSize); }

AutomationEventList rl_load_automation_event_list(const char *fileName)
{ return LoadAutomationEventList(fileName); }

void rl_unload_automation_event_list(AutomationEventList list)
{ UnloadAutomationEventList(list); }

bool rl_export_automation_event_list(AutomationEventList list, const char *fileName)
{ return ExportAutomationEventList(list, fileName); }

void rl_set_automation_event_list(AutomationEventList *list)
{ SetAutomationEventList(list); }

void rl_set_automation_event_base_frame(int frame)
{ SetAutomationEventBaseFrame(frame); }

void rl_start_automation_event_recording(void)
{ StartAutomationEventRecording(); }

void rl_stop_automation_event_recording(void)
{ StopAutomationEventRecording(); }

void rl_play_automation_event(AutomationEvent event)
{ PlayAutomationEvent(event); }

bool rl_is_key_pressed(int key)
{ return IsKeyPressed(key); }

bool rl_is_key_pressed_repeat(int key)
{ return IsKeyPressedRepeat(key); }

bool rl_is_key_down(int key)
{ return IsKeyDown(key); }

bool rl_is_key_released(int key)
{ return IsKeyReleased(key); }

bool rl_is_key_up(int key)
{ return IsKeyUp(key); }

int rl_get_key_pressed(void)
{ return GetKeyPressed(); }

int rl_get_char_pressed(void)
{ return GetCharPressed(); }

void rl_set_exit_key(int key)
{ SetExitKey(key); }

bool rl_is_gamepad_available(int gamepad)
{ return IsGamepadAvailable(gamepad); }

bool rl_is_gamepad_button_pressed(int gamepad, int button)
{ return IsGamepadButtonPressed(gamepad, button); }

bool rl_is_gamepad_button_down(int gamepad, int button)
{ return IsGamepadButtonDown(gamepad, button); }

bool rl_is_gamepad_button_released(int gamepad, int button)
{ return IsGamepadButtonReleased(gamepad, button); }

bool rl_is_gamepad_button_up(int gamepad, int button)
{ return IsGamepadButtonUp(gamepad, button); }

int rl_get_gamepad_button_pressed(void)
{ return GetGamepadButtonPressed(); }

int rl_get_gamepad_axis_count(int gamepad)
{ return GetGamepadAxisCount(gamepad); }

float rl_get_gamepad_axis_movement(int gamepad, int axis)
{ return GetGamepadAxisMovement(gamepad, axis); }

int rl_set_gamepad_mappings(const char *mappings)
{ return SetGamepadMappings(mappings); }

void rl_set_gamepad_vibration(int gamepad, float leftMotor, float rightMotor, float duration)
{ SetGamepadVibration(gamepad, leftMotor, rightMotor, duration); }

bool rl_is_mouse_button_pressed(int button)
{ return IsMouseButtonPressed(button); }

bool rl_is_mouse_button_down(int button)
{ return IsMouseButtonDown(button); }

bool rl_is_mouse_button_released(int button)
{ return IsMouseButtonReleased(button); }

bool rl_is_mouse_button_up(int button)
{ return IsMouseButtonUp(button); }

int rl_get_mouse_x(void)
{ return GetMouseX(); }

int rl_get_mouse_y(void)
{ return GetMouseY(); }

Vector2 rl_get_mouse_position(void)
{ return GetMousePosition(); }

Vector2 rl_get_mouse_delta(void)
{ return GetMouseDelta(); }

void rl_set_mouse_position(int x, int y)
{ SetMousePosition(x, y); }

void rl_set_mouse_offset(int offsetX, int offsetY)
{ SetMouseOffset(offsetX, offsetY); }

void rl_set_mouse_scale(float scaleX, float scaleY)
{ SetMouseScale(scaleX, scaleY); }

float rl_get_mouse_wheel_move(void)
{ return GetMouseWheelMove(); }

Vector2 rl_get_mouse_wheel_move_v(void)
{ return GetMouseWheelMoveV(); }

void rl_set_mouse_cursor(int cursor)
{ SetMouseCursor(cursor); }

int rl_get_touch_x(void)
{ return GetTouchX(); }

int rl_get_touch_y(void)
{ return GetTouchY(); }

Vector2 rl_get_touch_position(int index)
{ return GetTouchPosition(index); }

int rl_get_touch_point_id(int index)
{ return GetTouchPointId(index); }

int rl_get_touch_point_count(void)
{ return GetTouchPointCount(); }

void rl_set_gestures_enabled(unsigned int flags)
{ SetGesturesEnabled(flags); }

bool rl_is_gesture_detected(unsigned int gesture)
{ return IsGestureDetected(gesture); }

int rl_get_gesture_detected(void)
{ return GetGestureDetected(); }

float rl_get_gesture_hold_duration(void)
{ return GetGestureHoldDuration(); }

Vector2 rl_get_gesture_drag_vector(void)
{ return GetGestureDragVector(); }

float rl_get_gesture_drag_angle(void)
{ return GetGestureDragAngle(); }

Vector2 rl_get_gesture_pinch_vector(void)
{ return GetGesturePinchVector(); }

float rl_get_gesture_pinch_angle(void)
{ return GetGesturePinchAngle(); }

void rl_update_camera(Camera *camera, int mode)
{ UpdateCamera(camera, mode); }

void rl_update_camera_pro(Camera *camera, Vector3 movement, Vector3 rotation, float zoom)
{ UpdateCameraPro(camera, movement, rotation, zoom); }

void rl_set_shapes_texture(Texture2D texture, Rectangle source)
{ SetShapesTexture(texture, source); }

Texture2D rl_get_shapes_texture(void)
{ return GetShapesTexture(); }

Rectangle rl_get_shapes_texture_rectangle(void)
{ return GetShapesTextureRectangle(); }

void rl_draw_pixel(int posX, int posY, Color color)
{ DrawPixel(posX, posY, color); }

void rl_draw_pixel_v(Vector2 position, Color color)
{ DrawPixelV(position, color); }

void rl_draw_line(int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{ DrawLine(startPosX, startPosY, endPosX, endPosY, color); }

void rl_draw_line_v(Vector2 startPos, Vector2 endPos, Color color)
{ DrawLineV(startPos, endPos, color); }

void rl_draw_line_ex(Vector2 startPos, Vector2 endPos, float thick, Color color)
{ DrawLineEx(startPos, endPos, thick, color); }

void rl_draw_line_strip(const Vector2 *points, int pointCount, Color color)
{ DrawLineStrip(points, pointCount, color); }

void rl_draw_line_bezier(Vector2 startPos, Vector2 endPos, float thick, Color color)
{ DrawLineBezier(startPos, endPos, thick, color); }

void rl_draw_line_dashed(Vector2 startPos, Vector2 endPos, int dashSize, int spaceSize, Color color)
{ DrawLineDashed(startPos, endPos, dashSize, spaceSize, color); }

void rl_draw_circle(int centerX, int centerY, float radius, Color color)
{ DrawCircle(centerX, centerY, radius, color); }

void rl_draw_circle_v(Vector2 center, float radius, Color color)
{ DrawCircleV(center, radius, color); }

void rl_draw_circle_gradient(Vector2 center, float radius, Color inner, Color outer)
{ DrawCircleGradient(center, radius, inner, outer); }

void rl_draw_circle_sector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)
{ DrawCircleSector(center, radius, startAngle, endAngle, segments, color); }

void rl_draw_circle_sector_lines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)
{ DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color); }

void rl_draw_circle_lines(int centerX, int centerY, float radius, Color color)
{ DrawCircleLines(centerX, centerY, radius, color); }

void rl_draw_circle_lines_v(Vector2 center, float radius, Color color)
{ DrawCircleLinesV(center, radius, color); }

void rl_draw_ellipse(int centerX, int centerY, float radiusH, float radiusV, Color color)
{ DrawEllipse(centerX, centerY, radiusH, radiusV, color); }

void rl_draw_ellipse_v(Vector2 center, float radiusH, float radiusV, Color color)
{ DrawEllipseV(center, radiusH, radiusV, color); }

void rl_draw_ellipse_lines(int centerX, int centerY, float radiusH, float radiusV, Color color)
{ DrawEllipseLines(centerX, centerY, radiusH, radiusV, color); }

void rl_draw_ellipse_lines_v(Vector2 center, float radiusH, float radiusV, Color color)
{ DrawEllipseLinesV(center, radiusH, radiusV, color); }

void rl_draw_ring(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)
{ DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color); }

void rl_draw_ring_lines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)
{ DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color); }

void rl_draw_rectangle(int posX, int posY, int width, int height, Color color)
{ DrawRectangle(posX, posY, width, height, color); }

void rl_draw_rectangle_v(Vector2 position, Vector2 size, Color color)
{ DrawRectangleV(position, size, color); }

void rl_draw_rectangle_rec(Rectangle rec, Color color)
{ DrawRectangleRec(rec, color); }

void rl_draw_rectangle_pro(Rectangle rec, Vector2 origin, float rotation, Color color)
{ DrawRectanglePro(rec, origin, rotation, color); }

void rl_draw_rectangle_gradient_v(int posX, int posY, int width, int height, Color top, Color bottom)
{ DrawRectangleGradientV(posX, posY, width, height, top, bottom); }

void rl_draw_rectangle_gradient_h(int posX, int posY, int width, int height, Color left, Color right)
{ DrawRectangleGradientH(posX, posY, width, height, left, right); }

void rl_draw_rectangle_gradient_ex(Rectangle rec, Color topLeft, Color bottomLeft, Color bottomRight, Color topRight)
{ DrawRectangleGradientEx(rec, topLeft, bottomLeft, bottomRight, topRight); }

void rl_draw_rectangle_lines(int posX, int posY, int width, int height, Color color)
{ DrawRectangleLines(posX, posY, width, height, color); }

void rl_draw_rectangle_lines_ex(Rectangle rec, float lineThick, Color color)
{ DrawRectangleLinesEx(rec, lineThick, color); }

void rl_draw_rectangle_rounded(Rectangle rec, float roundness, int segments, Color color)
{ DrawRectangleRounded(rec, roundness, segments, color); }

void rl_draw_rectangle_rounded_lines(Rectangle rec, float roundness, int segments, Color color)
{ DrawRectangleRoundedLines(rec, roundness, segments, color); }

void rl_draw_rectangle_rounded_lines_ex(Rectangle rec, float roundness, int segments, float lineThick, Color color)
{ DrawRectangleRoundedLinesEx(rec, roundness, segments, lineThick, color); }

void rl_draw_triangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{ DrawTriangle(v1, v2, v3, color); }

void rl_draw_triangle_gradient(Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3)
{ DrawTriangleGradient(v1, v2, v3, c1, c2, c3); }

void rl_draw_triangle_lines(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{ DrawTriangleLines(v1, v2, v3, color); }

void rl_draw_triangle_fan(const Vector2 *points, int pointCount, Color color)
{ DrawTriangleFan(points, pointCount, color); }

void rl_draw_triangle_strip(const Vector2 *points, int pointCount, Color color)
{ DrawTriangleStrip(points, pointCount, color); }

void rl_draw_poly(Vector2 center, int sides, float radius, float rotation, Color color)
{ DrawPoly(center, sides, radius, rotation, color); }

void rl_draw_poly_lines(Vector2 center, int sides, float radius, float rotation, Color color)
{ DrawPolyLines(center, sides, radius, rotation, color); }

void rl_draw_poly_lines_ex(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color)
{ DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color); }

void rl_draw_spline_linear(const Vector2 *points, int pointCount, float thick, Color color)
{ DrawSplineLinear(points, pointCount, thick, color); }

void rl_draw_spline_basis(const Vector2 *points, int pointCount, float thick, Color color)
{ DrawSplineBasis(points, pointCount, thick, color); }

void rl_draw_spline_catmull_rom(const Vector2 *points, int pointCount, float thick, Color color)
{ DrawSplineCatmullRom(points, pointCount, thick, color); }

void rl_draw_spline_bezier_quadratic(const Vector2 *points, int pointCount, float thick, Color color)
{ DrawSplineBezierQuadratic(points, pointCount, thick, color); }

void rl_draw_spline_bezier_cubic(const Vector2 *points, int pointCount, float thick, Color color)
{ DrawSplineBezierCubic(points, pointCount, thick, color); }

void rl_draw_spline_segment_linear(Vector2 p1, Vector2 p2, float thick, Color color)
{ DrawSplineSegmentLinear(p1, p2, thick, color); }

void rl_draw_spline_segment_basis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color)
{ DrawSplineSegmentBasis(p1, p2, p3, p4, thick, color); }

void rl_draw_spline_segment_catmull_rom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color)
{ DrawSplineSegmentCatmullRom(p1, p2, p3, p4, thick, color); }

void rl_draw_spline_segment_bezier_quadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color)
{ DrawSplineSegmentBezierQuadratic(p1, c2, p3, thick, color); }

void rl_draw_spline_segment_bezier_cubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color)
{ DrawSplineSegmentBezierCubic(p1, c2, c3, p4, thick, color); }

Vector2 rl_get_spline_point_linear(Vector2 startPos, Vector2 endPos, float t)
{ return GetSplinePointLinear(startPos, endPos, t); }

Vector2 rl_get_spline_point_basis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t)
{ return GetSplinePointBasis(p1, p2, p3, p4, t); }

Vector2 rl_get_spline_point_catmull_rom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t)
{ return GetSplinePointCatmullRom(p1, p2, p3, p4, t); }

Vector2 rl_get_spline_point_bezier_quadratic(Vector2 p1, Vector2 c2, Vector2 p3, float t)
{ return GetSplinePointBezierQuadratic(p1, c2, p3, t); }

Vector2 rl_get_spline_point_bezier_cubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t)
{ return GetSplinePointBezierCubic(p1, c2, c3, p4, t); }

bool rl_check_collision_recs(Rectangle rec1, Rectangle rec2)
{ return CheckCollisionRecs(rec1, rec2); }

bool rl_check_collision_circles(Vector2 center1, float radius1, Vector2 center2, float radius2)
{ return CheckCollisionCircles(center1, radius1, center2, radius2); }

bool rl_check_collision_circle_rec(Vector2 center, float radius, Rectangle rec)
{ return CheckCollisionCircleRec(center, radius, rec); }

bool rl_check_collision_circle_line(Vector2 center, float radius, Vector2 p1, Vector2 p2)
{ return CheckCollisionCircleLine(center, radius, p1, p2); }

bool rl_check_collision_point_rec(Vector2 point, Rectangle rec)
{ return CheckCollisionPointRec(point, rec); }

bool rl_check_collision_point_circle(Vector2 point, Vector2 center, float radius)
{ return CheckCollisionPointCircle(point, center, radius); }

bool rl_check_collision_point_triangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3)
{ return CheckCollisionPointTriangle(point, p1, p2, p3); }

bool rl_check_collision_point_line(Vector2 point, Vector2 p1, Vector2 p2, int threshold)
{ return CheckCollisionPointLine(point, p1, p2, threshold); }

bool rl_check_collision_point_poly(Vector2 point, const Vector2 *points, int pointCount)
{ return CheckCollisionPointPoly(point, points, pointCount); }

bool rl_check_collision_lines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 *collisionPoint)
{ return CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint); }

Rectangle rl_get_collision_rec(Rectangle rec1, Rectangle rec2)
{ return GetCollisionRec(rec1, rec2); }

Image rl_load_image(const char *fileName)
{ return LoadImage(fileName); }

Image rl_load_image_raw(const char *fileName, int width, int height, int format, int headerSize)
{ return LoadImageRaw(fileName, width, height, format, headerSize); }

Image rl_load_image_anim(const char *fileName, int *frames)
{ return LoadImageAnim(fileName, frames); }

Image rl_load_image_anim_from_memory(const char *fileType, const unsigned char *fileData, int dataSize, int *frames)
{ return LoadImageAnimFromMemory(fileType, fileData, dataSize, frames); }

Image rl_load_image_from_memory(const char *fileType, const unsigned char *fileData, int dataSize)
{ return LoadImageFromMemory(fileType, fileData, dataSize); }

Image rl_load_image_from_texture(Texture2D texture)
{ return LoadImageFromTexture(texture); }

Image rl_load_image_from_screen(void)
{ return LoadImageFromScreen(); }

bool rl_is_image_valid(Image image)
{ return IsImageValid(image); }

void rl_unload_image(Image image)
{ UnloadImage(image); }

bool rl_export_image(Image image, const char *fileName)
{ return ExportImage(image, fileName); }

bool rl_export_image_as_code(Image image, const char *fileName)
{ return ExportImageAsCode(image, fileName); }

Image rl_gen_image_color(int width, int height, Color color)
{ return GenImageColor(width, height, color); }

Image rl_gen_image_gradient_linear(int width, int height, int direction, Color start, Color end)
{ return GenImageGradientLinear(width, height, direction, start, end); }

Image rl_gen_image_gradient_radial(int width, int height, float density, Color inner, Color outer)
{ return GenImageGradientRadial(width, height, density, inner, outer); }

Image rl_gen_image_gradient_square(int width, int height, float density, Color inner, Color outer)
{ return GenImageGradientSquare(width, height, density, inner, outer); }

Image rl_gen_image_checked(int width, int height, int checksX, int checksY, Color col1, Color col2)
{ return GenImageChecked(width, height, checksX, checksY, col1, col2); }

Image rl_gen_image_white_noise(int width, int height, float factor)
{ return GenImageWhiteNoise(width, height, factor); }

Image rl_gen_image_perlin_noise(int width, int height, int offsetX, int offsetY, float scale)
{ return GenImagePerlinNoise(width, height, offsetX, offsetY, scale); }

Image rl_gen_image_cellular(int width, int height, int tileSize)
{ return GenImageCellular(width, height, tileSize); }

Image rl_gen_image_text(int width, int height, const char *text)
{ return GenImageText(width, height, text); }

Image rl_image_copy(Image image)
{ return ImageCopy(image); }

Image rl_image_from_image(Image image, Rectangle rec)
{ return ImageFromImage(image, rec); }

Image rl_image_from_channel(Image image, int selectedChannel)
{ return ImageFromChannel(image, selectedChannel); }

Image rl_image_text(const char *text, int fontSize, Color color)
{ return ImageText(text, fontSize, color); }

Image rl_image_text_ex(Font font, const char *text, float fontSize, float spacing, Color tint)
{ return ImageTextEx(font, text, fontSize, spacing, tint); }

void rl_image_format(Image *image, int newFormat)
{ ImageFormat(image, newFormat); }

void rl_image_to_pot(Image *image, Color fill)
{ ImageToPOT(image, fill); }

void rl_image_crop(Image *image, Rectangle crop)
{ ImageCrop(image, crop); }

void rl_image_alpha_crop(Image *image, float threshold)
{ ImageAlphaCrop(image, threshold); }

void rl_image_alpha_clear(Image *image, Color color, float threshold)
{ ImageAlphaClear(image, color, threshold); }

void rl_image_alpha_mask(Image *image, Image alphaMask)
{ ImageAlphaMask(image, alphaMask); }

void rl_image_alpha_premultiply(Image *image)
{ ImageAlphaPremultiply(image); }

void rl_image_blur_gaussian(Image *image, int blurSize)
{ ImageBlurGaussian(image, blurSize); }

void rl_image_kernel_convolution(Image *image, const float *kernel, int kernelSize)
{ ImageKernelConvolution(image, kernel, kernelSize); }

void rl_image_resize(Image *image, int newWidth, int newHeight)
{ ImageResize(image, newWidth, newHeight); }

void rl_image_resize_nn(Image *image, int newWidth, int newHeight)
{ ImageResizeNN(image, newWidth, newHeight); }

void rl_image_resize_canvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill)
{ ImageResizeCanvas(image, newWidth, newHeight, offsetX, offsetY, fill); }

void rl_image_mipmaps(Image *image)
{ ImageMipmaps(image); }

void rl_image_dither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp)
{ ImageDither(image, rBpp, gBpp, bBpp, aBpp); }

void rl_image_flip_vertical(Image *image)
{ ImageFlipVertical(image); }

void rl_image_flip_horizontal(Image *image)
{ ImageFlipHorizontal(image); }

void rl_image_rotate(Image *image, int degrees)
{ ImageRotate(image, degrees); }

void rl_image_rotate_cw(Image *image)
{ ImageRotateCW(image); }

void rl_image_rotate_ccw(Image *image)
{ ImageRotateCCW(image); }

void rl_image_color_tint(Image *image, Color color)
{ ImageColorTint(image, color); }

void rl_image_color_invert(Image *image)
{ ImageColorInvert(image); }

void rl_image_color_grayscale(Image *image)
{ ImageColorGrayscale(image); }

void rl_image_color_contrast(Image *image, int contrast)
{ ImageColorContrast(image, contrast); }

void rl_image_color_brightness(Image *image, int brightness)
{ ImageColorBrightness(image, brightness); }

void rl_image_color_replace(Image *image, Color color, Color replace)
{ ImageColorReplace(image, color, replace); }

void rl_unload_image_colors(Color *colors)
{ UnloadImageColors(colors); }

void rl_unload_image_palette(Color *colors)
{ UnloadImagePalette(colors); }

Rectangle rl_get_image_alpha_border(Image image, float threshold)
{ return GetImageAlphaBorder(image, threshold); }

Color rl_get_image_color(Image image, int x, int y)
{ return GetImageColor(image, x, y); }

void rl_image_clear_background(Image *dst, Color color)
{ ImageClearBackground(dst, color); }

void rl_image_draw_pixel(Image *dst, int posX, int posY, Color color)
{ ImageDrawPixel(dst, posX, posY, color); }

void rl_image_draw_pixel_v(Image *dst, Vector2 position, Color color)
{ ImageDrawPixelV(dst, position, color); }

void rl_image_draw_line(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{ ImageDrawLine(dst, startPosX, startPosY, endPosX, endPosY, color); }

void rl_image_draw_line_v(Image *dst, Vector2 start, Vector2 end, Color color)
{ ImageDrawLineV(dst, start, end, color); }

void rl_image_draw_line_ex(Image *dst, Vector2 start, Vector2 end, int thick, Color color)
{ ImageDrawLineEx(dst, start, end, thick, color); }

void rl_image_draw_circle(Image *dst, int centerX, int centerY, int radius, Color color)
{ ImageDrawCircle(dst, centerX, centerY, radius, color); }

void rl_image_draw_circle_v(Image *dst, Vector2 center, int radius, Color color)
{ ImageDrawCircleV(dst, center, radius, color); }

void rl_image_draw_circle_lines(Image *dst, int centerX, int centerY, int radius, Color color)
{ ImageDrawCircleLines(dst, centerX, centerY, radius, color); }

void rl_image_draw_circle_lines_v(Image *dst, Vector2 center, int radius, Color color)
{ ImageDrawCircleLinesV(dst, center, radius, color); }

void rl_image_draw_rectangle(Image *dst, int posX, int posY, int width, int height, Color color)
{ ImageDrawRectangle(dst, posX, posY, width, height, color); }

void rl_image_draw_rectangle_v(Image *dst, Vector2 position, Vector2 size, Color color)
{ ImageDrawRectangleV(dst, position, size, color); }

void rl_image_draw_rectangle_rec(Image *dst, Rectangle rec, Color color)
{ ImageDrawRectangleRec(dst, rec, color); }

void rl_image_draw_rectangle_lines(Image *dst, int posX, int posY, int width, int height, Color color)
{ ImageDrawRectangleLines(dst, posX, posY, width, height, color); }

void rl_image_draw_rectangle_lines_ex(Image *dst, Rectangle rec, int thick, Color color)
{ ImageDrawRectangleLinesEx(dst, rec, thick, color); }

void rl_image_draw_triangle(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{ ImageDrawTriangle(dst, v1, v2, v3, color); }

void rl_image_draw_triangle_gradient(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3)
{ ImageDrawTriangleGradient(dst, v1, v2, v3, c1, c2, c3); }

void rl_image_draw_triangle_lines(Image *dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{ ImageDrawTriangleLines(dst, v1, v2, v3, color); }

void rl_image_draw_triangle_fan(Image *dst, const Vector2 *points, int pointCount, Color color)
{ ImageDrawTriangleFan(dst, points, pointCount, color); }

void rl_image_draw_triangle_strip(Image *dst, const Vector2 *points, int pointCount, Color color)
{ ImageDrawTriangleStrip(dst, points, pointCount, color); }

void rl_image_draw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint)
{ ImageDraw(dst, src, srcRec, dstRec, tint); }

void rl_image_draw_text(Image *dst, const char *text, int posX, int posY, int fontSize, Color color)
{ ImageDrawText(dst, text, posX, posY, fontSize, color); }

void rl_image_draw_text_ex(Image *dst, Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{ ImageDrawTextEx(dst, font, text, position, fontSize, spacing, tint); }

Texture2D rl_load_texture(const char *fileName)
{ return LoadTexture(fileName); }

Texture2D rl_load_texture_from_image(Image image)
{ return LoadTextureFromImage(image); }

TextureCubemap rl_load_texture_cubemap(Image image, int layout)
{ return LoadTextureCubemap(image, layout); }

RenderTexture2D rl_load_render_texture(int width, int height)
{ return LoadRenderTexture(width, height); }

bool rl_is_texture_valid(Texture2D texture)
{ return IsTextureValid(texture); }

void rl_unload_texture(Texture2D texture)
{ UnloadTexture(texture); }

bool rl_is_render_texture_valid(RenderTexture2D target)
{ return IsRenderTextureValid(target); }

void rl_unload_render_texture(RenderTexture2D target)
{ UnloadRenderTexture(target); }

void rl_update_texture(Texture2D texture, const void *pixels)
{ UpdateTexture(texture, pixels); }

void rl_update_texture_rec(Texture2D texture, Rectangle rec, const void *pixels)
{ UpdateTextureRec(texture, rec, pixels); }

void rl_gen_texture_mipmaps(Texture2D *texture)
{ GenTextureMipmaps(texture); }

void rl_set_texture_filter(Texture2D texture, int filter)
{ SetTextureFilter(texture, filter); }

void rl_set_texture_wrap(Texture2D texture, int wrap)
{ SetTextureWrap(texture, wrap); }

void rl_draw_texture(Texture2D texture, int posX, int posY, Color tint)
{ DrawTexture(texture, posX, posY, tint); }

void rl_draw_texture_v(Texture2D texture, Vector2 position, Color tint)
{ DrawTextureV(texture, position, tint); }

void rl_draw_texture_ex(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{ DrawTextureEx(texture, position, rotation, scale, tint); }

void rl_draw_texture_rec(Texture2D texture, Rectangle source, Vector2 position, Color tint)
{ DrawTextureRec(texture, source, position, tint); }

void rl_draw_texture_pro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
{ DrawTexturePro(texture, source, dest, origin, rotation, tint); }

void rl_draw_texture_n_patch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint)
{ DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint); }

bool rl_color_is_equal(Color col1, Color col2)
{ return ColorIsEqual(col1, col2); }

Color rl_fade(Color color, float alpha)
{ return Fade(color, alpha); }

int rl_color_to_int(Color color)
{ return ColorToInt(color); }

Vector4 rl_color_normalize(Color color)
{ return ColorNormalize(color); }

Color rl_color_from_normalized(Vector4 normalized)
{ return ColorFromNormalized(normalized); }

Vector3 rl_color_to_hsv(Color color)
{ return ColorToHSV(color); }

Color rl_color_from_hsv(float hue, float saturation, float value)
{ return ColorFromHSV(hue, saturation, value); }

Color rl_color_tint(Color color, Color tint)
{ return ColorTint(color, tint); }

Color rl_color_brightness(Color color, float factor)
{ return ColorBrightness(color, factor); }

Color rl_color_contrast(Color color, float contrast)
{ return ColorContrast(color, contrast); }

Color rl_color_alpha(Color color, float alpha)
{ return ColorAlpha(color, alpha); }

Color rl_color_alpha_blend(Color dst, Color src, Color tint)
{ return ColorAlphaBlend(dst, src, tint); }

Color rl_color_lerp(Color color1, Color color2, float factor)
{ return ColorLerp(color1, color2, factor); }

Color rl_get_color(unsigned int hexValue)
{ return GetColor(hexValue); }

Color rl_get_pixel_color(void *srcPtr, int format)
{ return GetPixelColor(srcPtr, format); }

void rl_set_pixel_color(void *dstPtr, Color color, int format)
{ SetPixelColor(dstPtr, color, format); }

int rl_get_pixel_data_size(int width, int height, int format)
{ return GetPixelDataSize(width, height, format); }

Font rl_get_font_default(void)
{ return GetFontDefault(); }

Font rl_load_font(const char *fileName)
{ return LoadFont(fileName); }

Font rl_load_font_ex(const char *fileName, int fontSize, const int *codepoints, int codepointCount)
{ return LoadFontEx(fileName, fontSize, codepoints, codepointCount); }

Font rl_load_font_from_image(Image image, Color key, int firstChar)
{ return LoadFontFromImage(image, key, firstChar); }

Font rl_load_font_from_memory(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, const int *codepoints, int codepointCount)
{ return LoadFontFromMemory(fileType, fileData, dataSize, fontSize, codepoints, codepointCount); }

bool rl_is_font_valid(Font font)
{ return IsFontValid(font); }

Image rl_gen_image_font_atlas(const GlyphInfo *glyphs, Rectangle **glyphRecs, int glyphCount, int fontSize, int padding, int packMethod)
{ return GenImageFontAtlas(glyphs, glyphRecs, glyphCount, fontSize, padding, packMethod); }

void rl_unload_font_data(GlyphInfo *glyphs, int glyphCount)
{ UnloadFontData(glyphs, glyphCount); }

void rl_unload_font(Font font)
{ UnloadFont(font); }

bool rl_export_font_as_code(Font font, const char *fileName)
{ return ExportFontAsCode(font, fileName); }

void rl_draw_fps(int posX, int posY)
{ DrawFPS(posX, posY); }

void rl_draw_text(const char *text, int posX, int posY, int fontSize, Color color)
{ DrawText(text, posX, posY, fontSize, color); }

void rl_draw_text_ex(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{ DrawTextEx(font, text, position, fontSize, spacing, tint); }

void rl_draw_text_pro(Font font, const char *text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint)
{ DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, tint); }

void rl_draw_text_codepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint)
{ DrawTextCodepoint(font, codepoint, position, fontSize, tint); }

void rl_draw_text_codepoints(Font font, const int *codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint)
{ DrawTextCodepoints(font, codepoints, codepointCount, position, fontSize, spacing, tint); }

void rl_set_text_line_spacing(int spacing)
{ SetTextLineSpacing(spacing); }

int rl_measure_text(const char *text, int fontSize)
{ return MeasureText(text, fontSize); }

Vector2 rl_measure_text_ex(Font font, const char *text, float fontSize, float spacing)
{ return MeasureTextEx(font, text, fontSize, spacing); }

Vector2 rl_measure_text_codepoints(Font font, const int *codepoints, int length, float fontSize, float spacing)
{ return MeasureTextCodepoints(font, codepoints, length, fontSize, spacing); }

int rl_get_glyph_index(Font font, int codepoint)
{ return GetGlyphIndex(font, codepoint); }

GlyphInfo rl_get_glyph_info(Font font, int codepoint)
{ return GetGlyphInfo(font, codepoint); }

Rectangle rl_get_glyph_atlas_rec(Font font, int codepoint)
{ return GetGlyphAtlasRec(font, codepoint); }

void rl_unload_utf8(char *text)
{ UnloadUTF8(text); }

void rl_unload_codepoints(int *codepoints)
{ UnloadCodepoints(codepoints); }

int rl_get_codepoint_count(const char *text)
{ return GetCodepointCount(text); }

int rl_get_codepoint(const char *text, int *codepointSize)
{ return GetCodepoint(text, codepointSize); }

int rl_get_codepoint_next(const char *text, int *codepointSize)
{ return GetCodepointNext(text, codepointSize); }

int rl_get_codepoint_previous(const char *text, int *codepointSize)
{ return GetCodepointPrevious(text, codepointSize); }

void rl_unload_text_lines(char **text, int lineCount)
{ UnloadTextLines(text, lineCount); }

int rl_text_copy(char *dst, const char *src)
{ return TextCopy(dst, src); }

bool rl_text_is_equal(const char *text1, const char *text2)
{ return TextIsEqual(text1, text2); }

unsigned int rl_text_length(const char *text)
{ return TextLength(text); }

void rl_text_append(char *text, const char *append, int *position)
{ TextAppend(text, append, position); }

int rl_text_find_index(const char *text, const char *search)
{ return TextFindIndex(text, search); }

int rl_text_to_integer(const char *text)
{ return TextToInteger(text); }

float rl_text_to_float(const char *text)
{ return TextToFloat(text); }

void rl_draw_line3_d(Vector3 startPos, Vector3 endPos, Color color)
{ DrawLine3D(startPos, endPos, color); }

void rl_draw_point3_d(Vector3 position, Color color)
{ DrawPoint3D(position, color); }

void rl_draw_circle3_d(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color)
{ DrawCircle3D(center, radius, rotationAxis, rotationAngle, color); }

void rl_draw_triangle3_d(Vector3 v1, Vector3 v2, Vector3 v3, Color color)
{ DrawTriangle3D(v1, v2, v3, color); }

void rl_draw_triangle_strip3_d(const Vector3 *points, int pointCount, Color color)
{ DrawTriangleStrip3D(points, pointCount, color); }

void rl_draw_cube(Vector3 position, float width, float height, float length, Color color)
{ DrawCube(position, width, height, length, color); }

void rl_draw_cube_v(Vector3 position, Vector3 size, Color color)
{ DrawCubeV(position, size, color); }

void rl_draw_cube_wires(Vector3 position, float width, float height, float length, Color color)
{ DrawCubeWires(position, width, height, length, color); }

void rl_draw_cube_wires_v(Vector3 position, Vector3 size, Color color)
{ DrawCubeWiresV(position, size, color); }

void rl_draw_sphere(Vector3 centerPos, float radius, Color color)
{ DrawSphere(centerPos, radius, color); }

void rl_draw_sphere_ex(Vector3 centerPos, float radius, int rings, int slices, Color color)
{ DrawSphereEx(centerPos, radius, rings, slices, color); }

void rl_draw_sphere_wires(Vector3 centerPos, float radius, int rings, int slices, Color color)
{ DrawSphereWires(centerPos, radius, rings, slices, color); }

void rl_draw_cylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)
{ DrawCylinder(position, radiusTop, radiusBottom, height, slices, color); }

void rl_draw_cylinder_ex(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color)
{ DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color); }

void rl_draw_cylinder_wires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)
{ DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color); }

void rl_draw_cylinder_wires_ex(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int slices, Color color)
{ DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, slices, color); }

void rl_draw_capsule(Vector3 startPos, Vector3 endPos, float radius, int rings, int slices, Color color)
{ DrawCapsule(startPos, endPos, radius, rings, slices, color); }

void rl_draw_capsule_wires(Vector3 startPos, Vector3 endPos, float radius, int rings, int slices, Color color)
{ DrawCapsuleWires(startPos, endPos, radius, rings, slices, color); }

void rl_draw_plane(Vector3 centerPos, Vector2 size, Color color)
{ DrawPlane(centerPos, size, color); }

void rl_draw_ray(Ray ray, Color color)
{ DrawRay(ray, color); }

void rl_draw_grid(int slices, float spacing)
{ DrawGrid(slices, spacing); }

Model rl_load_model(const char *fileName)
{ return LoadModel(fileName); }

Model rl_load_model_from_mesh(Mesh mesh)
{ return LoadModelFromMesh(mesh); }

bool rl_is_model_valid(Model model)
{ return IsModelValid(model); }

void rl_unload_model(Model model)
{ UnloadModel(model); }

BoundingBox rl_get_model_bounding_box(Model model)
{ return GetModelBoundingBox(model); }

void rl_draw_model(Model model, Vector3 position, float scale, Color tint)
{ DrawModel(model, position, scale, tint); }

void rl_draw_model_ex(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{ DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint); }

void rl_draw_model_wires(Model model, Vector3 position, float scale, Color tint)
{ DrawModelWires(model, position, scale, tint); }

void rl_draw_model_wires_ex(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{ DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint); }

void rl_draw_bounding_box(BoundingBox box, Color color)
{ DrawBoundingBox(box, color); }

void rl_draw_billboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint)
{ DrawBillboard(camera, texture, position, scale, tint); }

void rl_draw_billboard_rec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint)
{ DrawBillboardRec(camera, texture, source, position, size, tint); }

void rl_draw_billboard_pro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint)
{ DrawBillboardPro(camera, texture, source, position, up, size, origin, rotation, tint); }

void rl_upload_mesh(Mesh *mesh, bool dynamic)
{ UploadMesh(mesh, dynamic); }

void rl_update_mesh_buffer(Mesh mesh, int index, const void *data, int dataSize, int offset)
{ UpdateMeshBuffer(mesh, index, data, dataSize, offset); }

void rl_unload_mesh(Mesh mesh)
{ UnloadMesh(mesh); }

void rl_draw_mesh(Mesh mesh, Material material, Matrix transform)
{ DrawMesh(mesh, material, transform); }

void rl_draw_mesh_instanced(Mesh mesh, Material material, const Matrix *transforms, int instances)
{ DrawMeshInstanced(mesh, material, transforms, instances); }

BoundingBox rl_get_mesh_bounding_box(Mesh mesh)
{ return GetMeshBoundingBox(mesh); }

void rl_gen_mesh_tangents(Mesh *mesh)
{ GenMeshTangents(mesh); }

bool rl_export_mesh(Mesh mesh, const char *fileName)
{ return ExportMesh(mesh, fileName); }

bool rl_export_mesh_as_code(Mesh mesh, const char *fileName)
{ return ExportMeshAsCode(mesh, fileName); }

Mesh rl_gen_mesh_poly(int sides, float radius)
{ return GenMeshPoly(sides, radius); }

Mesh rl_gen_mesh_plane(float width, float length, int resX, int resZ)
{ return GenMeshPlane(width, length, resX, resZ); }

Mesh rl_gen_mesh_cube(float width, float height, float length)
{ return GenMeshCube(width, height, length); }

Mesh rl_gen_mesh_sphere(float radius, int rings, int slices)
{ return GenMeshSphere(radius, rings, slices); }

Mesh rl_gen_mesh_hemi_sphere(float radius, int rings, int slices)
{ return GenMeshHemiSphere(radius, rings, slices); }

Mesh rl_gen_mesh_cylinder(float radius, float height, int slices)
{ return GenMeshCylinder(radius, height, slices); }

Mesh rl_gen_mesh_cone(float radius, float height, int slices)
{ return GenMeshCone(radius, height, slices); }

Mesh rl_gen_mesh_torus(float radius, float size, int radSeg, int sides)
{ return GenMeshTorus(radius, size, radSeg, sides); }

Mesh rl_gen_mesh_knot(float radius, float size, int radSeg, int sides)
{ return GenMeshKnot(radius, size, radSeg, sides); }

Mesh rl_gen_mesh_heightmap(Image heightmap, Vector3 size)
{ return GenMeshHeightmap(heightmap, size); }

Mesh rl_gen_mesh_cubicmap(Image cubicmap, Vector3 cubeSize)
{ return GenMeshCubicmap(cubicmap, cubeSize); }

Material rl_load_material_default(void)
{ return LoadMaterialDefault(); }

bool rl_is_material_valid(Material material)
{ return IsMaterialValid(material); }

void rl_unload_material(Material material)
{ UnloadMaterial(material); }

void rl_set_material_texture(Material *material, int mapType, Texture2D texture)
{ SetMaterialTexture(material, mapType, texture); }

void rl_set_model_mesh_material(Model *model, int meshId, int materialId)
{ SetModelMeshMaterial(model, meshId, materialId); }

void rl_update_model_animation(Model model, ModelAnimation anim, float frame)
{ UpdateModelAnimation(model, anim, frame); }

void rl_update_model_animation_ex(Model model, ModelAnimation animA, float frameA, ModelAnimation animB, float frameB, float blend)
{ UpdateModelAnimationEx(model, animA, frameA, animB, frameB, blend); }

void rl_unload_model_animations(ModelAnimation *animations, int animCount)
{ UnloadModelAnimations(animations, animCount); }

bool rl_is_model_animation_valid(Model model, ModelAnimation anim)
{ return IsModelAnimationValid(model, anim); }

bool rl_check_collision_spheres(Vector3 center1, float radius1, Vector3 center2, float radius2)
{ return CheckCollisionSpheres(center1, radius1, center2, radius2); }

bool rl_check_collision_boxes(BoundingBox box1, BoundingBox box2)
{ return CheckCollisionBoxes(box1, box2); }

bool rl_check_collision_box_sphere(BoundingBox box, Vector3 center, float radius)
{ return CheckCollisionBoxSphere(box, center, radius); }

RayCollision rl_get_ray_collision_sphere(Ray ray, Vector3 center, float radius)
{ return GetRayCollisionSphere(ray, center, radius); }

RayCollision rl_get_ray_collision_box(Ray ray, BoundingBox box)
{ return GetRayCollisionBox(ray, box); }

RayCollision rl_get_ray_collision_mesh(Ray ray, Mesh mesh, Matrix transform)
{ return GetRayCollisionMesh(ray, mesh, transform); }

RayCollision rl_get_ray_collision_triangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3)
{ return GetRayCollisionTriangle(ray, p1, p2, p3); }

RayCollision rl_get_ray_collision_quad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4)
{ return GetRayCollisionQuad(ray, p1, p2, p3, p4); }

void rl_init_audio_device(void)
{ InitAudioDevice(); }

void rl_close_audio_device(void)
{ CloseAudioDevice(); }

bool rl_is_audio_device_ready(void)
{ return IsAudioDeviceReady(); }

void rl_set_master_volume(float volume)
{ SetMasterVolume(volume); }

float rl_get_master_volume(void)
{ return GetMasterVolume(); }

Wave rl_load_wave(const char *fileName)
{ return LoadWave(fileName); }

Wave rl_load_wave_from_memory(const char *fileType, const unsigned char *fileData, int dataSize)
{ return LoadWaveFromMemory(fileType, fileData, dataSize); }

bool rl_is_wave_valid(Wave wave)
{ return IsWaveValid(wave); }

Sound rl_load_sound(const char *fileName)
{ return LoadSound(fileName); }

Sound rl_load_sound_from_wave(Wave wave)
{ return LoadSoundFromWave(wave); }

Sound rl_load_sound_alias(Sound source)
{ return LoadSoundAlias(source); }

bool rl_is_sound_valid(Sound sound)
{ return IsSoundValid(sound); }

void rl_update_sound(Sound sound, const void *data, int frameCount)
{ UpdateSound(sound, data, frameCount); }

void rl_unload_wave(Wave wave)
{ UnloadWave(wave); }

void rl_unload_sound(Sound sound)
{ UnloadSound(sound); }

void rl_unload_sound_alias(Sound alias)
{ UnloadSoundAlias(alias); }

bool rl_export_wave(Wave wave, const char *fileName)
{ return ExportWave(wave, fileName); }

bool rl_export_wave_as_code(Wave wave, const char *fileName)
{ return ExportWaveAsCode(wave, fileName); }

void rl_play_sound(Sound sound)
{ PlaySound(sound); }

void rl_stop_sound(Sound sound)
{ StopSound(sound); }

void rl_pause_sound(Sound sound)
{ PauseSound(sound); }

void rl_resume_sound(Sound sound)
{ ResumeSound(sound); }

bool rl_is_sound_playing(Sound sound)
{ return IsSoundPlaying(sound); }

void rl_set_sound_volume(Sound sound, float volume)
{ SetSoundVolume(sound, volume); }

void rl_set_sound_pitch(Sound sound, float pitch)
{ SetSoundPitch(sound, pitch); }

void rl_set_sound_pan(Sound sound, float pan)
{ SetSoundPan(sound, pan); }

Wave rl_wave_copy(Wave wave)
{ return WaveCopy(wave); }

void rl_wave_crop(Wave *wave, int initFrame, int finalFrame)
{ WaveCrop(wave, initFrame, finalFrame); }

void rl_wave_format(Wave *wave, int sampleRate, int sampleSize, int channels)
{ WaveFormat(wave, sampleRate, sampleSize, channels); }

void rl_unload_wave_samples(float *samples)
{ UnloadWaveSamples(samples); }

Music rl_load_music_stream(const char *fileName)
{ return LoadMusicStream(fileName); }

Music rl_load_music_stream_from_memory(const char *fileType, const unsigned char *data, int dataSize)
{ return LoadMusicStreamFromMemory(fileType, data, dataSize); }

bool rl_is_music_valid(Music music)
{ return IsMusicValid(music); }

void rl_unload_music_stream(Music music)
{ UnloadMusicStream(music); }

void rl_play_music_stream(Music music)
{ PlayMusicStream(music); }

bool rl_is_music_stream_playing(Music music)
{ return IsMusicStreamPlaying(music); }

void rl_update_music_stream(Music music)
{ UpdateMusicStream(music); }

void rl_stop_music_stream(Music music)
{ StopMusicStream(music); }

void rl_pause_music_stream(Music music)
{ PauseMusicStream(music); }

void rl_resume_music_stream(Music music)
{ ResumeMusicStream(music); }

void rl_seek_music_stream(Music music, float position)
{ SeekMusicStream(music, position); }

void rl_set_music_volume(Music music, float volume)
{ SetMusicVolume(music, volume); }

void rl_set_music_pitch(Music music, float pitch)
{ SetMusicPitch(music, pitch); }

void rl_set_music_pan(Music music, float pan)
{ SetMusicPan(music, pan); }

float rl_get_music_time_length(Music music)
{ return GetMusicTimeLength(music); }

float rl_get_music_time_played(Music music)
{ return GetMusicTimePlayed(music); }

AudioStream rl_load_audio_stream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels)
{ return LoadAudioStream(sampleRate, sampleSize, channels); }

bool rl_is_audio_stream_valid(AudioStream stream)
{ return IsAudioStreamValid(stream); }

void rl_unload_audio_stream(AudioStream stream)
{ UnloadAudioStream(stream); }

void rl_update_audio_stream(AudioStream stream, const void *data, int frameCount)
{ UpdateAudioStream(stream, data, frameCount); }

bool rl_is_audio_stream_processed(AudioStream stream)
{ return IsAudioStreamProcessed(stream); }

void rl_play_audio_stream(AudioStream stream)
{ PlayAudioStream(stream); }

void rl_pause_audio_stream(AudioStream stream)
{ PauseAudioStream(stream); }

void rl_resume_audio_stream(AudioStream stream)
{ ResumeAudioStream(stream); }

bool rl_is_audio_stream_playing(AudioStream stream)
{ return IsAudioStreamPlaying(stream); }

void rl_stop_audio_stream(AudioStream stream)
{ StopAudioStream(stream); }

void rl_set_audio_stream_volume(AudioStream stream, float volume)
{ SetAudioStreamVolume(stream, volume); }

void rl_set_audio_stream_pitch(AudioStream stream, float pitch)
{ SetAudioStreamPitch(stream, pitch); }

void rl_set_audio_stream_pan(AudioStream stream, float pan)
{ SetAudioStreamPan(stream, pan); }

void rl_set_audio_stream_buffer_size_default(int size)
{ SetAudioStreamBufferSizeDefault(size); }

void rl_set_audio_stream_callback(AudioStream stream, AudioCallback callback)
{ SetAudioStreamCallback(stream, callback); }

void rl_attach_audio_stream_processor(AudioStream stream, AudioCallback processor)
{ AttachAudioStreamProcessor(stream, processor); }

void rl_detach_audio_stream_processor(AudioStream stream, AudioCallback processor)
{ DetachAudioStreamProcessor(stream, processor); }

void rl_attach_audio_mixed_processor(AudioCallback processor)
{ AttachAudioMixedProcessor(processor); }

void rl_detach_audio_mixed_processor(AudioCallback processor)
{ DetachAudioMixedProcessor(processor); }

