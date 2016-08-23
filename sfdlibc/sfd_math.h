#include <math.h>

#define MATH_E        2.718281828459045
#define MATH_LOG2E    1.442695
#define MATH_LOG10E   0.4342945
#define MATH_LN2      0.6931472
#define MATH_LN10     2.302585
#define MATH_PI       3.141592653589793
#define MATH_SQRT2    1.414213562373095
#define MATH_SQRT3    1.732050807568877
#define MATH_SQRT5    2.236067977499789
#define MATH_GOLDEN_R 1.618033988749894

typedef struct vec4 {
    int x, y, z, w;
} vec4;

int   sfd_isprime(const int x);
int   sfd_pow(const int x, const int y);
float sfd_sqrt(float x);


float sfd_sqrt(float x) {
    return (float)sqrt((double)x);
}

int sfd_isprime(const int x) {
    int i;
    if (x == 2)
        return 1;
    if (x < 2 || !(x % 2))
        return 0;
    for (i = 3; i <= (int)sfd_sqrt((float)x); i += 2)
        if (!(x % i))
            return 0;
    return 1;
}

int sfd_pow(const int x, const int y) {
    int i;
    for (i = 1; i < y; i++)
        x *= x;
    return x;
}

float sfd_math_slope2D(vec4 p1, vec4 p2) {
    return (p2.y - p1.y) - (p2.x - p1.x);
}
