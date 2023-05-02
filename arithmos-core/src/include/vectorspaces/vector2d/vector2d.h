#ifndef _vector2d_H_
#define _vector2d_H_

#include <math.h>
#include <vector2d/coordinate.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    coordinate x;
    coordinate y;
} vector2d;

extern vector2d* vector2d_scalar_add(vector2d*, coordinate);

extern vector2d* vector2d_scalar_subtract(vector2d*, coordinate);

extern vector2d* vector2d_scalar_multiply(vector2d*, coordinate);

extern vector2d* vector2d_scalar_divide(vector2d*, coordinate);

extern vector2d* vector2d_normalize(vector2d*);

extern vector2d vector2d_add(vector2d, vector2d);

extern vector2d vector2d_subtract(vector2d, vector2d);

extern vector2d vector2d_lerp(vector2d, vector2d, coordinate);

extern coordinate vector2d_dot_product(vector2d, vector2d);

extern coordinate vector2d_angle(vector2d, vector2d);

extern coordinate vector2d_length(vector2d);

extern coordinate vector2d_polar(vector2d);

extern int vector2d_is_dependent(vector2d, vector2d);

#ifdef __cplusplus
}
#endif

#endif //_vector2d_H_
