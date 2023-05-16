/**
 * @brief An example showing an example :-).
 * @author pavl_g.
 * @copyright Unlicensed license.
 */
#include <stdio.h>
#include <vectorspaces/vector2d/vector2d.h>

vector2d vec0 = {
    0,
    1,
    2
};

vector2d vec1 = {
    2,
    3,
    4
};

int main() {
    printf("Summation = [%d, %d] \n", vector2d_add(vec0, vec1).x, vector2d_add(vec0, vec1).y);
    printf("Subtraction = [%d, %d] \n", vector2d_subtract(vec0, vec1).x, vector2d_subtract(vec0, vec1).y);
    printf("Product = [%d, %d] \n", vector2d_product(vec0, vec1).x, vector2d_product(vec0, vec1).y);
    printf("Division = [%d, %d] \n", vector2d_divide(vec0, vec1).x, vector2d_divide(vec0, vec1).y);
    printf("Inner Product = %d \n", vector2d_dot_product(vec0, vec1));
    printf("Inner Angle in radians = %d \n", vector2d_angle(vec0, vec1));
    printf("Are parallel = %d \n", vector2d_are_parallel(vec0, vec1));
    printf("Are perpendicular = %d \n", vector2d_are_perpendicular(vec0, vec1));
    printf("Extrapolate to 1/2 after the last vector = [%d, %d] \n", vector2d_extrapolate(vec0, vec1, 0.5).x, vector2d_extrapolate(vec0, vec1, 0.5).y);
    
    return 0;
}
