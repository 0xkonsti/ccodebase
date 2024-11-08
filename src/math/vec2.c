#include "ccodebase/math/vec2.h"
#include <math.h>
#include <stdlib.h>

Vec2 const VEC2_ZERO = {0.0f, 0.0f};
Vec2 const VEC2_ONE = {1.0f, 1.0f};
Vec2 const VEC2_NORTH = {0.0f, 1.0f};
Vec2 const VEC2_SOUTH = {0.0f, -1.0f};
Vec2 const VEC2_EAST = {1.0f, 0.0f};
Vec2 const VEC2_WEST = {-1.0f, 0.0f};
Vec2 const VEC2_NORTH_EAST = {1.0f, 1.0f};
Vec2 const VEC2_NORTH_WEST = {-1.0f, 1.0f};
Vec2 const VEC2_SOUTH_EAST = {1.0f, -1.0f};
Vec2 const VEC2_SOUTH_WEST = {-1.0f, -1.0f};

Vec2* create_vec2(f32 x, f32 y) {
    Vec2* vec2 = malloc(sizeof(Vec2));
    vec2->x = x;
    vec2->y = y;
    return vec2;
}

Vec2* vec2_clone(Vec2 const* vec2) {
    Vec2* clone = malloc(sizeof(Vec2));
    clone->x = vec2->x;
    clone->y = vec2->y;
    return clone;
}

void destroy_vec2(Vec2* vec2) {
    free(vec2);
}

void vec2_add(Vec2* vec2, Vec2 const* other) {
    vec2->x += other->x;
    vec2->y += other->y;
}

void vec2_sub(Vec2* vec2, Vec2 const* other) {
    vec2->x -= other->x;
    vec2->y -= other->y;
}

void vec2_mul(Vec2* vec2, f32 scalar) {
    vec2->x *= scalar;
    vec2->y *= scalar;
}

void vec2_div(Vec2* vec2, f32 scalar) {
    vec2->x /= scalar;
    vec2->y /= scalar;
}

f32 vec2_dot(Vec2 const* vec2, Vec2 const* other) {
    return vec2->x * other->x + vec2->y * other->y;
}

f32 vec2_sqrt_length(Vec2 const* vec2) {
    return vec2->x * vec2->x + vec2->y * vec2->y;
}

f32 vec2_length(Vec2 const* vec2) {
    return sqrt(vec2_sqrt_length(vec2));
}

void vec2_normalize(Vec2* vec2) {
    f32 length = vec2_length(vec2);
    if (length != 0.0f) {
        vec2->x /= length;
        vec2->y /= length;
    }
}

void vec2_normalize_or_zero(Vec2* vec2) {
    f32 length = vec2_length(vec2);
    if (length != 0.0f) {
        vec2->x /= length;
        vec2->y /= length;
    } else {
        vec2->x = 0.0f;
        vec2->y = 0.0f;
    }
}

void vec2_rotate(Vec2* vec2, angle_t const* angle) {
    f32 x = vec2->x;
    f32 y = vec2->y;
    f32 cos_angle = cos(angle->radians);
    f32 sin_angle = sin(angle->radians);
    vec2->x = x * cos_angle - y * sin_angle;
    vec2->y = x * sin_angle + y * cos_angle;
}

void vec2_set(Vec2* vec2, f32 x, f32 y) {
    vec2->x = x;
    vec2->y = y;
}

void vec2_copy(Vec2* vec2, Vec2 const* other) {
    vec2->x = other->x;
    vec2->y = other->y;
}

void vec2_lerp(Vec2* vec2, Vec2 const* other, f32 alpha) {
    vec2->x = vec2->x + alpha * (other->x - vec2->x);
    vec2->y = vec2->y + alpha * (other->y - vec2->y);
}

void vec2_clamp(Vec2* vec2, f32 min, f32 max) {
    vec2->x = fmax(min, fmin(max, vec2->x));
    vec2->y = fmax(min, fmin(max, vec2->y));
}

void vec2_set_length(Vec2* vec2, f32 length) {
    vec2_normalize(vec2);
    vec2_mul(vec2, length);
}

void vec2_clamp_length(Vec2* vec2, f32 min, f32 max) {
    f32 length = vec2_length(vec2);
    vec2->x = fmax(min, fmin(max, vec2->x));
    vec2->y = fmax(min, fmin(max, vec2->y));
    vec2_set_length(vec2, length);
}

void vec2_min(Vec2* vec2, Vec2 const* other) {
    vec2->x = fmin(vec2->x, other->x);
    vec2->y = fmin(vec2->y, other->y);
}

void vec2_max(Vec2* vec2, Vec2 const* other) {
    vec2->x = fmax(vec2->x, other->x);
    vec2->y = fmax(vec2->y, other->y);
}

void vec2_abs(Vec2* vec2) {
    vec2->x = fabs(vec2->x);
    vec2->y = fabs(vec2->y);
}

void vec2_negate(Vec2* vec2) {
    vec2->x = -vec2->x;
    vec2->y = -vec2->y;
}

void vec2_floor(Vec2* vec2) {
    vec2->x = floor(vec2->x);
    vec2->y = floor(vec2->y);
}

void vec2_ceil(Vec2* vec2) {
    vec2->x = ceil(vec2->x);
    vec2->y = ceil(vec2->y);
}

void vec2_round(Vec2* vec2) {
    vec2->x = round(vec2->x);
    vec2->y = round(vec2->y);
}
