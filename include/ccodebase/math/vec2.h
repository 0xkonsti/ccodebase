#ifndef MATH_VEC2_H_
#define MATH_VEC2_H_

#include "ccodebase/core/defines.h"
#include "ccodebase/math/angle.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2;

extern Vec2 const VEC2_ZERO;
extern Vec2 const VEC2_ONE;
extern Vec2 const VEC2_NORTH;
extern Vec2 const VEC2_SOUTH;
extern Vec2 const VEC2_EAST;
extern Vec2 const VEC2_WEST;
extern Vec2 const VEC2_NORTH_EAST;
extern Vec2 const VEC2_NORTH_WEST;
extern Vec2 const VEC2_SOUTH_EAST;
extern Vec2 const VEC2_SOUTH_WEST;

Vec2* create_vec2(f32 x, f32 y);

Vec2* vec2_clone(Vec2 const* vec2);

void destroy_vec2(Vec2* vec2);

void vec2_add(Vec2* vec2, Vec2 const* other);

void vec2_sub(Vec2* vec2, Vec2 const* other);

void vec2_mul(Vec2* vec2, f32 scalar);

void vec2_div(Vec2* vec2, f32 scalar);

f32 vec2_dot(Vec2 const* vec2, Vec2 const* other);

f32 vec2_sqrt_length(Vec2 const* vec2);

f32 vec2_length(Vec2 const* vec2);

void vec2_normalize(Vec2* vec2);

void vec2_normalize_or_zero(Vec2* vec2);

void vec2_rotate(Vec2* vec2, angle_t const* angle);

void vec2_set(Vec2* vec2, f32 x, f32 y);

void vec2_copy(Vec2* vec2, Vec2 const* other);

void vec2_lerp(Vec2* vec2, Vec2 const* other, f32 alpha);

void vec2_clamp(Vec2* vec2, f32 min, f32 max);

void vec2_set_length(Vec2* vec2, f32 length);

void vec2_clamp_length(Vec2* vec2, f32 min, f32 max);

void vec2_min(Vec2* vec2, Vec2 const* other);

void vec2_max(Vec2* vec2, Vec2 const* other);

void vec2_abs(Vec2* vec2);

void vec2_negate(Vec2* vec2);

void vec2_floor(Vec2* vec2);

void vec2_ceil(Vec2* vec2);

void vec2_round(Vec2* vec2);

#endif  // MATH_VEC2_H_
