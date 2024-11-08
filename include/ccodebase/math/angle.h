#ifndef MATH_ANGLE_H_
#define MATH_ANGLE_H_

#include "ccodebase/core/defines.h"

typedef struct {
    f32 radians;
} angle_t;

extern angle_t const ANGLE_ZERO;
extern angle_t const ANGLE_RIGHT;
extern angle_t const ANGLE_UP;
extern angle_t const ANGLE_LEFT;
extern angle_t const ANGLE_DOWN;

angle_t* create_angle(f32 radians);

angle_t* angle_clone(angle_t const* angle);

void destroy_angle(angle_t* angle);

f32 angle_degrees(angle_t const* angle);

#endif  // MATH_ANGLE_H_
