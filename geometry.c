#include <math.h>

#include "geometry.h"

double absolute(double n) {
    if(n < 0) {
        return -n;
    }
    return n;     
}

double tangente(point a1, point b1) {
    double tangente;

    tangente = (b1.y - a1.y)/(b1.x - a1.x);

    return tangente;
}

int verify(point p, point a, point b) {
    double tam_aresta = pow((pow(a.x - b.x, 2) + pow(a.y - b.y, 2)), 0.5);
    double tam_a = pow((pow(a.x - p.x, 2) + pow(a.y - p.y, 2)), 0.5);
    double tam_b = pow((pow(b.x - p.x, 2) + pow(b.y - p.y, 2)), 0.5);

    // 89 testes que devem retornar 2
    if (absolute(tam_a + tam_b) - absolute(tam_aresta) < 0.000001) {
        return 2;
    }

    if ((a.y >= p.y) && (b.y <= p.y)) { 
        
        // caso em que o segmento de reta preto é inclinado 
        if ( a.x != b.x ) {
            if (p.x != b.x) {
                double tangente_theta = tangente(b, p);
                double tangente_beta = tangente(b, a);

                // caso em que o seg de reta tem coef angular > 0
                if (tangente_beta > 0) { 
                    if (tangente_beta > tangente_theta) {
                        return 0;
                    }
                }

            }
        }

        // caso em que o segmento de reta preto é vertical 
        if (a.x == b.x) {
            if (p.x > a.x) {
                return 0;
            }

            if ((b.y == p.y) || (a.y == p.y)) {
                if (p.x < b.x) {
                    return 0;
                }
            }
            else {
                return 1;
            }
        }

        return 1; 
    }

    if ((b.y >= p.y) && (a.y <= p.y)) {
        
        // caso em que o segmento de reta preto é inclinado 
        if ( a.x != b.x ) {
            if (p.x != a.x) {
                double tg_theta1 = tangente(a, p);
                double tg_beta1 = tangente(a, b);

                if (tg_beta1 > 0) {
                    if (tg_beta1 > tg_theta1) {
                        return 0;
                    }

                }
            }
        }

        // caso em que o seg de reta é vertical 
        if (b.x == a.x) {
            if ( p.x > b.x ) {
                return 0;
            }

            if ( (p.y == a.y) || (p.y == b.y) ) {
                if (p.x < b.x) {
                    return 0;
                }
            }

            else {
                return 1;
            }
        }
        
        return 1;
    }

    // 412 testes que devem retornar 0
    else {
        return 0;
    }


}

int inside(point p, point poly[], int n) {
    return 0;
}

