#include "rlm.h"

/* -- raymath.h -- */

float rl_clamp(float value, float min, float max)
{ return Clamp(value, min, max); }

float rl_lerp(float start, float end, float amount)
{ return Lerp(start, end, amount); }

float rl_normalize(float value, float start, float end)
{ return Normalize(value, start, end); }

float rl_remap(float value, float inputStart, float inputEnd, float outputStart, float outputEnd)
{ return Remap(value, inputStart, inputEnd, outputStart, outputEnd); }

float rl_wrap(float value, float min, float max)
{ return Wrap(value, min, max); }

int rl_float_equals(float x, float y)
{ return FloatEquals(x, y); }

Vector2 rl_vector2_zero(void)
{ return Vector2Zero(); }

Vector2 rl_vector2_one(void)
{ return Vector2One(); }

Vector2 rl_vector2_add(Vector2 v1, Vector2 v2)
{ return Vector2Add(v1, v2); }

Vector2 rl_vector2_add_value(Vector2 v, float add)
{ return Vector2AddValue(v, add); }

Vector2 rl_vector2_subtract(Vector2 v1, Vector2 v2)
{ return Vector2Subtract(v1, v2); }

Vector2 rl_vector2_subtract_value(Vector2 v, float sub)
{ return Vector2SubtractValue(v, sub); }

float rl_vector2_length(Vector2 v)
{ return Vector2Length(v); }

float rl_vector2_length_sqr(Vector2 v)
{ return Vector2LengthSqr(v); }

float rl_vector2_dot_product(Vector2 v1, Vector2 v2)
{ return Vector2DotProduct(v1, v2); }

float rl_vector2_cross_product(Vector2 v1, Vector2 v2)
{ return Vector2CrossProduct(v1, v2); }

float rl_vector2_distance(Vector2 v1, Vector2 v2)
{ return Vector2Distance(v1, v2); }

float rl_vector2_distance_sqr(Vector2 v1, Vector2 v2)
{ return Vector2DistanceSqr(v1, v2); }

float rl_vector2_angle(Vector2 v1, Vector2 v2)
{ return Vector2Angle(v1, v2); }

float rl_vector2_line_angle(Vector2 start, Vector2 end)
{ return Vector2LineAngle(start, end); }

Vector2 rl_vector2_scale(Vector2 v, float scale)
{ return Vector2Scale(v, scale); }

Vector2 rl_vector2_multiply(Vector2 v1, Vector2 v2)
{ return Vector2Multiply(v1, v2); }

Vector2 rl_vector2_negate(Vector2 v)
{ return Vector2Negate(v); }

Vector2 rl_vector2_divide(Vector2 v1, Vector2 v2)
{ return Vector2Divide(v1, v2); }

Vector2 rl_vector2_normalize(Vector2 v)
{ return Vector2Normalize(v); }

Vector2 rl_vector2_transform(Vector2 v, Matrix mat)
{ return Vector2Transform(v, mat); }

Vector2 rl_vector2_lerp(Vector2 v1, Vector2 v2, float amount)
{ return Vector2Lerp(v1, v2, amount); }

Vector2 rl_vector2_reflect(Vector2 v, Vector2 normal)
{ return Vector2Reflect(v, normal); }

Vector2 rl_vector2_min(Vector2 v1, Vector2 v2)
{ return Vector2Min(v1, v2); }

Vector2 rl_vector2_max(Vector2 v1, Vector2 v2)
{ return Vector2Max(v1, v2); }

Vector2 rl_vector2_rotate(Vector2 v, float angle)
{ return Vector2Rotate(v, angle); }

Vector2 rl_vector2_move_towards(Vector2 v, Vector2 target, float maxDistance)
{ return Vector2MoveTowards(v, target, maxDistance); }

Vector2 rl_vector2_invert(Vector2 v)
{ return Vector2Invert(v); }

Vector2 rl_vector2_clamp(Vector2 v, Vector2 min, Vector2 max)
{ return Vector2Clamp(v, min, max); }

Vector2 rl_vector2_clamp_value(Vector2 v, float min, float max)
{ return Vector2ClampValue(v, min, max); }

int rl_vector2_equals(Vector2 p, Vector2 q)
{ return Vector2Equals(p, q); }

Vector2 rl_vector2_refract(Vector2 v, Vector2 n, float r)
{ return Vector2Refract(v, n, r); }

Vector3 rl_vector3_zero(void)
{ return Vector3Zero(); }

Vector3 rl_vector3_one(void)
{ return Vector3One(); }

Vector3 rl_vector3_add(Vector3 v1, Vector3 v2)
{ return Vector3Add(v1, v2); }

Vector3 rl_vector3_add_value(Vector3 v, float add)
{ return Vector3AddValue(v, add); }

Vector3 rl_vector3_subtract(Vector3 v1, Vector3 v2)
{ return Vector3Subtract(v1, v2); }

Vector3 rl_vector3_subtract_value(Vector3 v, float sub)
{ return Vector3SubtractValue(v, sub); }

Vector3 rl_vector3_scale(Vector3 v, float scalar)
{ return Vector3Scale(v, scalar); }

Vector3 rl_vector3_multiply(Vector3 v1, Vector3 v2)
{ return Vector3Multiply(v1, v2); }

Vector3 rl_vector3_cross_product(Vector3 v1, Vector3 v2)
{ return Vector3CrossProduct(v1, v2); }

Vector3 rl_vector3_perpendicular(Vector3 v)
{ return Vector3Perpendicular(v); }

float rl_vector3_length(const Vector3 v)
{ return Vector3Length(v); }

float rl_vector3_length_sqr(const Vector3 v)
{ return Vector3LengthSqr(v); }

float rl_vector3_dot_product(Vector3 v1, Vector3 v2)
{ return Vector3DotProduct(v1, v2); }

float rl_vector3_distance(Vector3 v1, Vector3 v2)
{ return Vector3Distance(v1, v2); }

float rl_vector3_distance_sqr(Vector3 v1, Vector3 v2)
{ return Vector3DistanceSqr(v1, v2); }

float rl_vector3_angle(Vector3 v1, Vector3 v2)
{ return Vector3Angle(v1, v2); }

Vector3 rl_vector3_negate(Vector3 v)
{ return Vector3Negate(v); }

Vector3 rl_vector3_divide(Vector3 v1, Vector3 v2)
{ return Vector3Divide(v1, v2); }

Vector3 rl_vector3_normalize(Vector3 v)
{ return Vector3Normalize(v); }

Vector3 rl_vector3_project(Vector3 v1, Vector3 v2)
{ return Vector3Project(v1, v2); }

Vector3 rl_vector3_reject(Vector3 v1, Vector3 v2)
{ return Vector3Reject(v1, v2); }

void rl_vector3_ortho_normalize(Vector3 *v1, Vector3 *v2)
{ Vector3OrthoNormalize(v1, v2); }

Vector3 rl_vector3_transform(Vector3 v, Matrix mat)
{ return Vector3Transform(v, mat); }

Vector3 rl_vector3_rotate_by_quaternion(Vector3 v, Quaternion q)
{ return Vector3RotateByQuaternion(v, q); }

Vector3 rl_vector3_rotate_by_axis_angle(Vector3 v, Vector3 axis, float angle)
{ return Vector3RotateByAxisAngle(v, axis, angle); }

Vector3 rl_vector3_move_towards(Vector3 v, Vector3 target, float maxDistance)
{ return Vector3MoveTowards(v, target, maxDistance); }

Vector3 rl_vector3_lerp(Vector3 v1, Vector3 v2, float amount)
{ return Vector3Lerp(v1, v2, amount); }

Vector3 rl_vector3_cubic_hermite(Vector3 v1, Vector3 tangent1, Vector3 v2, Vector3 tangent2, float amount)
{ return Vector3CubicHermite(v1, tangent1, v2, tangent2, amount); }

Vector3 rl_vector3_reflect(Vector3 v, Vector3 normal)
{ return Vector3Reflect(v, normal); }

Vector3 rl_vector3_min(Vector3 v1, Vector3 v2)
{ return Vector3Min(v1, v2); }

Vector3 rl_vector3_max(Vector3 v1, Vector3 v2)
{ return Vector3Max(v1, v2); }

Vector3 rl_vector3_barycenter(Vector3 p, Vector3 a, Vector3 b, Vector3 c)
{ return Vector3Barycenter(p, a, b, c); }

Vector3 rl_vector3_unproject(Vector3 source, Matrix projection, Matrix view)
{ return Vector3Unproject(source, projection, view); }

float3 rl_vector3_to_float_v(Vector3 v)
{ return Vector3ToFloatV(v); }

Vector3 rl_vector3_invert(Vector3 v)
{ return Vector3Invert(v); }

Vector3 rl_vector3_clamp(Vector3 v, Vector3 min, Vector3 max)
{ return Vector3Clamp(v, min, max); }

Vector3 rl_vector3_clamp_value(Vector3 v, float min, float max)
{ return Vector3ClampValue(v, min, max); }

int rl_vector3_equals(Vector3 p, Vector3 q)
{ return Vector3Equals(p, q); }

Vector3 rl_vector3_refract(Vector3 v, Vector3 n, float r)
{ return Vector3Refract(v, n, r); }

Vector4 rl_vector4_zero(void)
{ return Vector4Zero(); }

Vector4 rl_vector4_one(void)
{ return Vector4One(); }

Vector4 rl_vector4_add(Vector4 v1, Vector4 v2)
{ return Vector4Add(v1, v2); }

Vector4 rl_vector4_add_value(Vector4 v, float add)
{ return Vector4AddValue(v, add); }

Vector4 rl_vector4_subtract(Vector4 v1, Vector4 v2)
{ return Vector4Subtract(v1, v2); }

Vector4 rl_vector4_subtract_value(Vector4 v, float add)
{ return Vector4SubtractValue(v, add); }

float rl_vector4_length(Vector4 v)
{ return Vector4Length(v); }

float rl_vector4_length_sqr(Vector4 v)
{ return Vector4LengthSqr(v); }

float rl_vector4_dot_product(Vector4 v1, Vector4 v2)
{ return Vector4DotProduct(v1, v2); }

float rl_vector4_distance(Vector4 v1, Vector4 v2)
{ return Vector4Distance(v1, v2); }

float rl_vector4_distance_sqr(Vector4 v1, Vector4 v2)
{ return Vector4DistanceSqr(v1, v2); }

Vector4 rl_vector4_scale(Vector4 v, float scale)
{ return Vector4Scale(v, scale); }

Vector4 rl_vector4_multiply(Vector4 v1, Vector4 v2)
{ return Vector4Multiply(v1, v2); }

Vector4 rl_vector4_negate(Vector4 v)
{ return Vector4Negate(v); }

Vector4 rl_vector4_divide(Vector4 v1, Vector4 v2)
{ return Vector4Divide(v1, v2); }

Vector4 rl_vector4_normalize(Vector4 v)
{ return Vector4Normalize(v); }

Vector4 rl_vector4_min(Vector4 v1, Vector4 v2)
{ return Vector4Min(v1, v2); }

Vector4 rl_vector4_max(Vector4 v1, Vector4 v2)
{ return Vector4Max(v1, v2); }

Vector4 rl_vector4_lerp(Vector4 v1, Vector4 v2, float amount)
{ return Vector4Lerp(v1, v2, amount); }

Vector4 rl_vector4_move_towards(Vector4 v, Vector4 target, float maxDistance)
{ return Vector4MoveTowards(v, target, maxDistance); }

Vector4 rl_vector4_invert(Vector4 v)
{ return Vector4Invert(v); }

int rl_vector4_equals(Vector4 p, Vector4 q)
{ return Vector4Equals(p, q); }

float rl_matrix_determinant(Matrix mat)
{ return MatrixDeterminant(mat); }

float rl_matrix_trace(Matrix mat)
{ return MatrixTrace(mat); }

Matrix rl_matrix_transpose(Matrix mat)
{ return MatrixTranspose(mat); }

Matrix rl_matrix_invert(Matrix mat)
{ return MatrixInvert(mat); }

Matrix rl_matrix_identity(void)
{ return MatrixIdentity(); }

Matrix rl_matrix_add(Matrix left, Matrix right)
{ return MatrixAdd(left, right); }

Matrix rl_matrix_subtract(Matrix left, Matrix right)
{ return MatrixSubtract(left, right); }

Matrix rl_matrix_multiply(Matrix left, Matrix right)
{ return MatrixMultiply(left, right); }

Matrix rl_matrix_multiply_value(Matrix left, float value)
{ return MatrixMultiplyValue(left, value); }

Matrix rl_matrix_translate(float x, float y, float z)
{ return MatrixTranslate(x, y, z); }

Matrix rl_matrix_rotate(Vector3 axis, float angle)
{ return MatrixRotate(axis, angle); }

Matrix rl_matrix_rotate_x(float angle)
{ return MatrixRotateX(angle); }

Matrix rl_matrix_rotate_y(float angle)
{ return MatrixRotateY(angle); }

Matrix rl_matrix_rotate_z(float angle)
{ return MatrixRotateZ(angle); }

Matrix rl_matrix_rotate_xyz(Vector3 angle)
{ return MatrixRotateXYZ(angle); }

Matrix rl_matrix_rotate_zyx(Vector3 angle)
{ return MatrixRotateZYX(angle); }

Matrix rl_matrix_scale(float x, float y, float z)
{ return MatrixScale(x, y, z); }

Matrix rl_matrix_frustum(double left, double right, double bottom, double top, double nearPlane, double farPlane)
{ return MatrixFrustum(left, right, bottom, top, nearPlane, farPlane); }

Matrix rl_matrix_perspective(double fovY, double aspect, double nearPlane, double farPlane)
{ return MatrixPerspective(fovY, aspect, nearPlane, farPlane); }

Matrix rl_matrix_ortho(double left, double right, double bottom, double top, double nearPlane, double farPlane)
{ return MatrixOrtho(left, right, bottom, top, nearPlane, farPlane); }

Matrix rl_matrix_look_at(Vector3 eye, Vector3 target, Vector3 up)
{ return MatrixLookAt(eye, target, up); }

float16 rl_matrix_to_float_v(Matrix mat)
{ return MatrixToFloatV(mat); }

Quaternion rl_quaternion_add(Quaternion q1, Quaternion q2)
{ return QuaternionAdd(q1, q2); }

Quaternion rl_quaternion_add_value(Quaternion q, float add)
{ return QuaternionAddValue(q, add); }

Quaternion rl_quaternion_subtract(Quaternion q1, Quaternion q2)
{ return QuaternionSubtract(q1, q2); }

Quaternion rl_quaternion_subtract_value(Quaternion q, float sub)
{ return QuaternionSubtractValue(q, sub); }

Quaternion rl_quaternion_identity(void)
{ return QuaternionIdentity(); }

float rl_quaternion_length(Quaternion q)
{ return QuaternionLength(q); }

Quaternion rl_quaternion_normalize(Quaternion q)
{ return QuaternionNormalize(q); }

Quaternion rl_quaternion_invert(Quaternion q)
{ return QuaternionInvert(q); }

Quaternion rl_quaternion_multiply(Quaternion q1, Quaternion q2)
{ return QuaternionMultiply(q1, q2); }

Quaternion rl_quaternion_scale(Quaternion q, float mul)
{ return QuaternionScale(q, mul); }

Quaternion rl_quaternion_divide(Quaternion q1, Quaternion q2)
{ return QuaternionDivide(q1, q2); }

Quaternion rl_quaternion_lerp(Quaternion q1, Quaternion q2, float amount)
{ return QuaternionLerp(q1, q2, amount); }

Quaternion rl_quaternion_nlerp(Quaternion q1, Quaternion q2, float amount)
{ return QuaternionNlerp(q1, q2, amount); }

Quaternion rl_quaternion_slerp(Quaternion q1, Quaternion q2, float amount)
{ return QuaternionSlerp(q1, q2, amount); }

Quaternion rl_quaternion_cubic_hermite_spline(Quaternion q1, Quaternion outTangent1, Quaternion q2, Quaternion inTangent2, float t)
{ return QuaternionCubicHermiteSpline(q1, outTangent1, q2, inTangent2, t); }

Quaternion rl_quaternion_from_vector3_to_vector3(Vector3 from, Vector3 to)
{ return QuaternionFromVector3ToVector3(from, to); }

Quaternion rl_quaternion_from_matrix(Matrix mat)
{ return QuaternionFromMatrix(mat); }

Matrix rl_quaternion_to_matrix(Quaternion q)
{ return QuaternionToMatrix(q); }

Quaternion rl_quaternion_from_axis_angle(Vector3 axis, float angle)
{ return QuaternionFromAxisAngle(axis, angle); }

void rl_quaternion_to_axis_angle(Quaternion q, Vector3 *outAxis, float *outAngle)
{ QuaternionToAxisAngle(q, outAxis, outAngle); }

Quaternion rl_quaternion_from_euler(float pitch, float yaw, float roll)
{ return QuaternionFromEuler(pitch, yaw, roll); }

Vector3 rl_quaternion_to_euler(Quaternion q)
{ return QuaternionToEuler(q); }

Quaternion rl_quaternion_transform(Quaternion q, Matrix mat)
{ return QuaternionTransform(q, mat); }

int rl_quaternion_equals(Quaternion p, Quaternion q)
{ return QuaternionEquals(p, q); }

Matrix rl_matrix_compose(Vector3 translation, Quaternion rotation, Vector3 scale)
{ return MatrixCompose(translation, rotation, scale); }

void rl_matrix_decompose(Matrix mat, Vector3 *translation, Quaternion *rotation, Vector3 *scale)
{ MatrixDecompose(mat, translation, rotation, scale); }

