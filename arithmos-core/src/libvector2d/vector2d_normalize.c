#include <vectorspaces/vector2d/vector2d.h>

vector2d* vector2d_normalize(vector2d* vec) {
    coordinate length = {
        vector2d_length(*vec)
    };
    return vector2d_scalar_divide(vec, length);
}