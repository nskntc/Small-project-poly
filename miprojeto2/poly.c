#include <stdio.h>
#include <stdlib.h>

typedef struct polynomio {
	char id[1000];       // string com o nome do polinômio
	int p;          // grau do polinômio
	double coef[1000];   // vetor de coeficientes do polinômio
} Poly;

Poly sum_poli(Poly p1, Poly p2, int n1, int n2) {
    int i;
    Poly p3;
    if(n1>n2) {
        for(i=0; i<=n1; i++) {
            p3.coef[i]=p1.coef[i]+p2.coef[i];
        }
    } else {
        for(i=0; i<=n2; i++) {
            p3.coef[i]=p1.coef[i]+p2.coef[i];
        }
    }
    return p3;
}

Poly sub_poli(Poly p1, Poly p2, int n1, int n2) {
    int i;
    Poly p3;
    if(n1>n2) {
        for(i=0; i<=n1; i++) {
            p3.coef[i]=p1.coef[i]-p2.coef[i];
        }
    } else {
        for(i=0; i<=n2; i++) {
            p3.coef[i]=p1.coef[i]-p2.coef[i];
        }
    }
    return p3;
}

void separa_conta(char *s1, char *s2, char *s3, int indiceOp, int tam) {
    int i, c=0;
    for(i=0; i<=tam; i++) {
        if(i<indiceOp && s3[i]!=' ') s1[i]=s3[i];
        else if(i>indiceOp && s3[i]!=' ') {
            s2[c]=s3[i];
            c++;
        }
    }
}