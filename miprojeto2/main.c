#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poly.h"

int main(void) {

    Poly *poly, polyResult;
    int i, k, t, c;
    int quantPoly;
    char verificaEnter;
    int potencia, maiorExp=0;
    char auxCoef[100];
    int quantOp;
    char op, poly1[100], poly2[100], opTotal[200];
    int indiceOp;
    int verificaPrintMais=0;
    scanf("%d%*c", &quantPoly);
    poly=(Poly *)malloc(quantPoly*sizeof(Poly));
    for(i=0; i<quantPoly; i++) {       
        scanf("%[^:]%*c", poly[i].id);
        // escaneia os valores do polinomio ate o enter
        while(1) {
            scanf("%c", &verificaEnter);
            if(verificaEnter=='\n') break;
            scanf("%[^x]%*c%*c%d", auxCoef, &potencia);
            poly[i].coef[potencia]=atof(auxCoef);
            if(verificaEnter=='-') poly[i].coef[potencia]=-poly[i].coef[potencia];
            memset(auxCoef, 0, 100);
            if(potencia>maiorExp) maiorExp=potencia;
        }
        poly[i].p=maiorExp;
        maiorExp=0;
    }
    scanf("%d%*c", &quantOp);
    for(i=0; i<quantOp; i++) {
        // le a conta em uma string so e identifica o operador
        for(k=0; opTotal[k]!='\n'; k++) {
            scanf("%c", &opTotal[k]);
            if(opTotal[k]=='\n') {
                opTotal[k]='\0';
                break;
            }
            if(opTotal[k]=='-' || opTotal[k]=='+') {
                op=opTotal[k];
                indiceOp=k;
            }
        }
        // identifica o polinomio1, e o polinomio2
        separa_conta(poly1, poly2, opTotal, indiceOp, (k-1));
        // verifica quais polinomios foram escaneados
        for(k=0; k<quantPoly; k++) {
            if(strcmp(poly[k].id, poly1)==0) break;
        }
        for(t=0; t<quantPoly; t++) {
            if(strcmp(poly[t].id, poly2)==0) break;
        }
        // verificar qual operação deve ser feita
        if(op=='+') polyResult=sum_poli(poly[k], poly[t], poly[k].p, poly[t].p);
        if(op=='-') polyResult=sub_poli(poly[k], poly[t], poly[k].p, poly[t].p);
        // printa o polinomio do menor para o maior
        if(poly[k].p>poly[t].p) {
            for(c=0; c<=poly[k].p; c++) {
                if(polyResult.coef[c]!=0) {
                    if(polyResult.coef[c]>0 && verificaPrintMais>0) printf("+");
                    printf("%.2lfx^%d", polyResult.coef[c], c);
                    verificaPrintMais++;
                }
            }
        } else {
            for(c=0; c<=poly[t].p; c++) {
                if(polyResult.coef[c]!=0) {
                    if(polyResult.coef[c]>0 && verificaPrintMais>0) printf("+");
                    printf("%.2lfx^%d", polyResult.coef[c], c);
                    verificaPrintMais++;
                }
            }
        }
        printf("\n");
        verificaPrintMais=0;
        memset(poly1, '\0', 100);
        memset(poly2, '\0', 100);
        memset(opTotal, '\0', 200);
    }
        
    return 0;
}