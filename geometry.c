#include <math.h>

#include "geometry.h"

//typedef struct{
 //   int x;
 //   int y;
//}point;

int verify(point p, point a, point b) {
    double tam_aresta = pow((pow(a.x - b.x, 2) + pow(a.y - b.y, 2)), 0.5);
    double tam_a = pow((pow(a.x - p.x, 2) + pow(a.y - p.y, 2)), 0.5);
    double tam_b = pow((pow(b.x - p.x, 2) + pow(b.y - p.y, 2)), 0.5);

    if(abs(tam_a + tam_b - tam_aresta) < 0.000001){
        return 2;
    }

    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}

