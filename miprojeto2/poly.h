typedef struct polynomio {
	char id[1000];       // string com o nome do polinômio
	int p;          // grau do polinômio
	double coef[1000];   // vetor de coeficientes do polinômio
} Poly;

Poly sum_poli(Poly p1, Poly p2, int n1, int n2);

Poly sub_poli(Poly p1, Poly p2, int n1, int n2);

void separa_conta(char *s1, char *s2, char *s3, int indiceOp, int tam);