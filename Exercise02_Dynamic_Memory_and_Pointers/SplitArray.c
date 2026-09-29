#include<stdio.h>
#include<stdlib.h>

int** podijeli(int* niz, int n) {
	int prvidio = n / 2;
	int drugi_dio = n - (n / 2);
	int** rezultat = (int**)malloc(2 * sizeof(int*));
	rezultat[0] = (int*)malloc(prvidio * sizeof(int));
	rezultat[1] = (int*)malloc(drugi_dio * sizeof(int));

	for (int i = 0;i < prvidio; i++) {
		rezultat[0][i] = niz[i];
	}
	for (int i = 0;i < drugi_dio; i++) {
		rezultat[1][i] = niz[i + prvidio];
	}

	return rezultat;
}


int main(void) {
	int niz[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int n = sizeof(niz) / sizeof(int);
	int** rez = podijeli(niz, n);

	printf("1:\n");
	for (int i = 0;i < (n / 2);i++) {
		printf("%d ", rez[0][i]);
	}
	printf("\n2:\n");
	for (int i = 0;i < (n-(n / 2));i++) {
		printf("%d ", rez[1][i]);
	}
	free(rez[0]);
	free(rez[1]);
	free(rez);

	return 0;
}
