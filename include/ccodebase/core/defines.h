#ifndef CORE_DEFINES_H_
#define CORE_DEFINES_H_

// Includes
#include <stddef.h>
#include <stdint.h>

// Typedefs
typedef size_t usize;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

#ifndef __cplusplus
#define bool _Bool
#define true 1
#define false 0
#endif

// Constants
#define KB(x) (x * 1024)
#define MB(x) (x * 1024 * 1024)
#define GB(x) (x * 1024 * 1024 * 1024)

// Macros
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define ABS(a) ((a) < 0 ? -(a) : (a))

#define SWAP(a, b)          \
    do {                    \
        typeof(a) temp = a; \
        a = b;              \
        b = temp;           \
    } while (0)

#define BIT_SET(x, n) ((x) |= (1 << (n)))
#define BIT_CLEAR(x, n) ((x) &= ~(1 << (n)))
#define BIT_FLIP(x, n) ((x) ^= (1 << (n)))
#define BIT_CHECK(x, n) ((x) & (1 << (n)))

#define IS_POWER_OF_TWO(x) ((x) && !((x) & ((x) - 1)))

#define ALIGN_DOWN(x, a) ((x) & ~((a) - 1))
#define ALIGN_UP(x, a) (((x) + (a) - 1) & ~((a) - 1))

#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))

#define STRINGIFY(x) #x

#define CONCAT(a, b) a##b

#define UNUSED(x) ((void)(x))

#define FOREACH(item, array)                    \
    for (u32 i = 0; i < ARRAY_SIZE(array); i++) \
        for (item = array[i];;) break;

// Asserts
#define ASSERT(x)                                                \
    if (!(x)) {                                                  \
        printf("Assertion failed: %s:%d\n", __FILE__, __LINE__); \
        exit(1);                                                 \
    }

#define ASSERT_MSG(x, msg)                                       \
    if (!(x)) {                                                  \
        printf("Assertion failed: %s:%d\n", __FILE__, __LINE__); \
        printf("Message: %s\n", msg);                            \
        exit(1);                                                 \
    }

#endif  // CORE_DEFINES_H_
