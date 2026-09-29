#include<stdio.h>
#include<stdlib.h>

int* stvori_niz(int *niz, int start, int stop) {
	int* n_niz=(int*)malloc((stop-start)*sizeof(int));
	if (n_niz == NULL){
		printf("greska\n");
		return NULL;
	}
	for (int i = start; i < stop; i++){
		n_niz[i-start] = niz[i];
	}
	return n_niz;
}






int main(void) {
	int niz[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int start, stop;
	printf("unesi start\n");
	scanf("%d", &start);
	printf("unesi stop\n");
	scanf("%d", &stop);
	int *novi_niz = stvori_niz(niz, start, stop);
	int len = stop - start;
	for (int j = 0; j < len; j++) {
		printf("%d\n", novi_niz[j]);
	}

	return 0;
}