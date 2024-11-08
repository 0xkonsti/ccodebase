#include "ccodebase/math/angle.h"
#include <math.h>
#include <stdlib.h>
#include "ccodebase/math/constants.h"

angle_t const ANGLE_ZERO = {0.0f};
angle_t const ANGLE_RIGHT = {0.0f};
angle_t const ANGLE_UP = {TWO_PI};
angle_t const ANGLE_LEFT = {PI};
angle_t const ANGLE_DOWN = {HALF_PI};

angle_t* create_angle(f32 radians) {
    angle_t* angle = malloc(sizeof(angle_t));
    angle->radians = radians;
    return angle;
}

angle_t* angle_clone(angle_t const* angle) {
    angle_t* clone = malloc(sizeof(angle_t));
    clone->radians = angle->radians;
    return clone;
}

void destroy_angle(angle_t* angle) {
    free(angle);
}

f32 angle_degrees(angle_t const* angle) {
    return angle->radians * 180.0f / PI;
}
