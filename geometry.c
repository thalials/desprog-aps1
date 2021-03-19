#include <math.h>
#include <stdio.h>
#include "geometry.h"

double absolute(double n) {
    if(n < 0) {
        return -n;
    }
    return n;     
}

double tangente(point a1, point b1) {
    double tangente;

    tangente = (b1.y - a1.y)/(double)(b1.x - a1.x);

    return tangente;
}

int verify(point p, point a, point b) {
    double tam_aresta = pow((pow(a.x - b.x, 2) + pow(a.y - b.y, 2)), 0.5);
    double tam_a = pow((pow(a.x - p.x, 2) + pow(a.y - p.y, 2)), 0.5);
    double tam_b = pow((pow(b.x - p.x, 2) + pow(b.y - p.y, 2)), 0.5);

    if (absolute(tam_a + tam_b) - absolute(tam_aresta) < 0.000001) {
        return 2;
    }

    if ((a.y >= p.y) && (b.y <= p.y)) { 
        
        // caso em que o segmento de reta preto é inclinado ou horizontal
        if ( a.x != b.x ) {

            // caso em que o seg de reta é horizontal
            if (a.y == b.y) {
                if (p.y == a.y) {
                    if (a.x < b.x) {
                        if (p.x < a.x) {
                            return 0;
                        }
                    }
                    if (b.x < a.x) {
                        if (p.x < b.x) {
                            return 0;
                        }
                    }
                }
                if (p.x > b.x || p.x > a.x) {
                    return 0;
                }
            }

            // caso em que p esta alinhado com b
            if (p.x == b.x ) {
                double tangente_beta = tangente(b, a);

                if (tangente_beta < 0) {
                    return 0;
                }
            }

            // else
            if (p.x != b.x) {
                double tangente_theta = tangente(b, p);
                double tangente_beta = tangente(b, a);

                // caso em que o seg de reta tem coef angular > 0
                if (tangente_beta > 0) { 
                    if (tangente_theta < 0) {
                        return 1;
                    }
                    if (tangente_beta > tangente_theta) {
                        return 0;
                    }

                    if (tangente_theta == 0) {
                        return 0;
                    }
                }

                // caso em que o seg de reta tem coef angular < 0
                if (tangente_beta < 0 && tangente_theta < 0 ) {
                    if (absolute(tangente_theta) > absolute(tangente_beta)) {
                        return 0;
                    }
                } 
                if (tangente_beta < 0 && tangente_theta > 0) {
                    return 0;
                }

                if(tangente_beta < 0 && tangente_theta == 0) {
                    return 0;
                }
            }            
        }

        // caso em que o segmento de reta é pontual a(x, y) = b(x, y)
        if (a.x == b.x && a.y == b.y) {
            return 0;
        }

        // caso em que o segmento de reta preto é vertical 
        if (a.x == b.x) {
            if (p.x > a.x) {
                return 0;
            }
            if (a.y == p.y && p.x < a.x ) {
                return 1;
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
        
        // caso em que o segmento de reta é inclinado ou horizontal
        if ( a.x != b.x ) {

            // caso em que o seg de reta é horizontal
            if (a.y == b.y) {
                if (p.x > b.x || p.x > a.x) {
                    return 0;
                }
            }

            // caso em que p esta alinhado com a
            if (p.x == a.x ) {
                double tg_beta1 = tangente(a, b);

                if (tg_beta1 < 0) {
                    return 0;
                }
            }

            if (p.x != a.x) {
                double tg_theta1 = tangente(a, p);
                double tg_beta1 = tangente(a, b);

                // caso em que o seg de reta tem coef angular > 0 
                if (tg_beta1 > 0) {
                    if (tg_theta1 < 0) {
                        return 1;
                    }
                    if (tg_beta1 > tg_theta1 ) {
                        return 0;
                    }

                    if (tg_theta1 == 0) {
                        return 0;
                    }

                }

            // caso em que o seg de reta tem coef angular < 0
                if (tg_beta1 < 0 && tg_theta1 < 0 ) {
                    if (absolute(tg_theta1) > absolute(tg_beta1)) {
                        return 0;
                    }
                } 
                if (tg_beta1 < 0 && tg_theta1 > 0) {
                    return 0;
                }

                if(tg_beta1 < 0 && tg_theta1 == 0) {
                    return 0;
                }
            }

        }

        // caso em que o seg de reta é vertical 
        if (b.x == a.x) {
            if ( p.x > b.x ) {
                return 0;
            }

            if (b.y == p.y && p.x < b.x ) {
                return 1;
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

    else {
        return 0;
    }


}

int verifica_par_impar (int n) {
    // n é impar
    if (n%2 == 1) {
        return 1;
    }
    // n é par
    return 0;
}

int inside(point p, point poly[], int n) {
    int verifica;
    int soma = 0;
    
    // para cada i entre 0 e n-2
    for (int i = 0; i <= n-2; i++) {
        
        // retorna 0, 1, 2
        verifica = verify(p, poly[i], poly[i+1]);
        
        // se o ponto estiver na parede, considera-se que ele esta dentro do poligono
        if (verifica == 2) {
            return 1;
        }

        // para que o ponto esteja dentro do poligono, a soma deve ser impar
        soma += verifica;
    }

    for (int i = n-1; i >= 0; i-- ) {
        verifica = verify(p, poly[n-1], poly[0]);
        if (verifica == 2) {
            return 1;
        } 
        // para que o ponto esteja dentro do poligono, a soma deve ser impar
        soma += verifica;
        return verifica_par_impar(soma); 
    }

    return 0;
}



