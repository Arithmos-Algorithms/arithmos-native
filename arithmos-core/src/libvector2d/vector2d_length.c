#include <vectorspaces/vector2d/vector2d.h>

coordinate vector2d_length(vector2d vec) {
    return vector2d_sqrt(vector2d_pow(vec.x, 2) + vector2d_pow(vec.y, 2));
}