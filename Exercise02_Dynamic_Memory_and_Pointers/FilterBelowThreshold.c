#include<stdio.h>
#include<stdlib.h>

int* stvori(int *niz, int n, int th, int *nth) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			cnt++;
		}
	}
	int* n_niz=(int*)malloc(cnt*sizeof(int));
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			n_niz[k] = niz[i];
			k++;
		}
	}
	*nth =cnt;
	return n_niz;
}





int main(void) {
	int niz[] = { 10,20,34,51,387,423,654,12,34,56,78,32 };
	int n = sizeof(niz) / (sizeof (int));
	int th = 30;
	int nth;
	/*
	printf("Unesi granicu");
	scanf("%d", &th);
	*/
	int* novi_niz = stvori(niz, n, th, &nth);
	printf("Velicina niza: %d\n", nth);
	for (int i = 0; i < nth; i++) {
		printf("%d\n", novi_niz[i]);
	}

	return 0;
}