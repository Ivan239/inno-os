#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int integer_num = INT_MAX;
    float float_num = FLT_MAX;
    double double_num = DBL_MAX;
    printf("integer: %d bytes %d\n"
           "float: %d bytes %f\n"
           "double: %d bytes %f", sizeof(integer_num), integer_num,
           sizeof(float_num), float_num,
           sizeof(double_num), double_num);
    return 0;
}
