#ifndef _vector2d_H_ 
#   error "Use vector2d instead of this!"
#endif

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <inttypes.h>

#if defined (_VECTOR2D_USE_INT8_)
#   define coordinate uint8_t
#   define vector2d_pow(v, p) ((uint8_t) powf(v, p)) 
#   define vector2d_atan2(y, x) ((uint8_t) atan2f(y, x)) 
#   define vector2d_acos(v) ((uint8_t) acosf(v)) 
#elif defined (_VECTOR2D_USE_INT16_)
#   define coordinate uint16_t
#   define vector2d_pow(v, p) ((uint16_t) powf(v, p)) 
#   define vector2d_atan2(y, x) ((uint16_t) atan2f(y, x)) 
#   define vector2d_acos(v) ((uint16_t) acosf(v)) 
#elif defined (_VECTOR2D_USE_INT32_)
#   define coordinate uint32_t
#   define vector2d_pow(v, p) ((uint32_t) powf(v, p)) 
#   define vector2d_atan2(y, x) ((uint32_t) atan2f(y, x)) 
#   define vector2d_acos(v) ((uint32_t) acosf(v)) 
#elif defined (_VECTOR2D_USE_INT64_)
#   define coordinate uint64_t
#   define vector2d_pow(v, p) ((uint64_t) powf(v, p)) 
#   define vector2d_atan2(y, x) ((uint64_t) atan2l(y, x)) 
#   define vector2d_acos(v) ((uint64_t) acosl(v)) 
#elif defined (_VECTOR2D_USE_DOUBLE_)
#   define coordinate double
#   define vector2d_pow(v, p) ((double) powf(v, p)) 
#   define vector2d_atan2(y, x) ((double) atan2l(y, x)) 
#   define vector2d_acos(v) ((double) acosl(v)) 
#else 
#   define coordinate float
#   define vector2d_pow(v, p) ((float) powf(v, p)) 
#   define vector2d_atan2(y, x) ((float) atan2f(y, x)) 
#   define vector2d_acos(v) ((float) acosf(v)) 
#endif

#define vector2d_sqrt(v) vector2d_pow(v, 0.5)
#define vector2d_abs(v) ((coordinate) vector2d_sqrt(vector2d_pow(v, 2)))

#endif // _COORDINATE_H_