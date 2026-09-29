#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM (rand() * rand())


int* generate(int n) {
	int* niz = (int*)malloc(n * sizeof(int));
	niz[0] = 1 + rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = RANDOM % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int check_doubles(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
			if (niz[i] == niz[j])
				return 1;
	}
	return 0;
}

int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int check_doubles_sort(int* niz, int n) {
	qsort(niz, n, sizeof(int), cmp);
	for (int i = 1; i < n; i++) {
		if (niz[i] == niz[i - 1])
			return 1;
	}
	return 0;
}
/* ZAD1
int presjek(int* niz1, int* niz2,int vel1,int vel2) {
	int cnt = 0;
	for (int i = 0;i < vel1;i++) {
		for (int j = 0;j < vel2;j++) {
			if (niz1[i] == niz2[j]) {
				cnt++;
			}

		}
	}
	return cnt;
}
*/
/* ZAD2
int presjek_jedan_sortiran(int* niz1,int* niz2,int vel1, int vel2) {
	qsort(niz2, vel2, sizeof(int), cmp);
	int cnt = 0;
	for (int i = 0;i < vel1;i++) {
		if (bsearch(&niz1[i], niz2, vel2, sizeof(int), cmp) != 0) {
			cnt++;
		}
	}
	return cnt;
*/
/*ZAD3
int presjek_oba_sortirana(int* niz1,int* niz2,int vel1,int vel2){
	qsort(niz1, vel2, sizeof(int), cmp);
	qsort(niz2, vel2, sizeof(int), cmp);
	int i = 0;
	int j = 0;
	int cnt = 0;
	while (i < vel1 && j < vel2) {
		if (niz1[i] < niz2[j]) {
			i++;
		}
		else if (niz1[i] > niz2[j]) {
			j++;
		}
		else {
			cnt++;
			j++;
			i++;
		}
	}
	return cnt;
}
*/

int presjek_po_indeksima(int* niz1, int* niz2, int vel1, int vel2) {
	int vel_A = 0;
	int vel_B = 0;
	for (int i = 0;i < vel1;i++) {
		if (niz1[i] > vel_A) {
			vel_A = niz1[i];
		}

	}
	for (int i = 0;i < vel2;i++) {
		if (niz2[i] > vel_B) {
			vel_B = niz2[i];
		}
	}
	int maxvel;
	if (vel_A > vel_B) {
		maxvel = vel_A;
	}
	else {
		maxvel = vel_B;
	}
	int* index_A = (int*)calloc(vel_A, sizeof(int));
	int* index_B = (int*)calloc(vel_B, sizeof(int));
	if(index_A==NULL){
		return 0;
	}
	if (index_B == NULL) {
		return 0;
	}
	for (int i = 0;i < vel1;i++) {
		index_A[niz1[i]] = 1;
	}
	for (int i = 0;i < vel2;i++) {
		index_B[niz2[i]] = 1;
	}
	int cnt = 0;
	int j = 0;
	int k = 0;
	while (j < vel_A && k < vel_B) {
		if (index_A[j] == index_B[k])
			cnt++;
		j++;
		k++;
	}

	return cnt;
	}
	
int main(){
	srand((unsigned int)time(NULL));
	for (int n = 1000000; n < 10000000; n += 1000000) {
		int* niz1 = generate(n);
		int vel1 = n;
		int* niz2 = generate(n);
		int vel2 = n;

		int stime = clock();
		int brojpreklapanja = presjek_po_indeksima(niz1, niz2, vel1, vel2);
		int etime = clock();

		printf("%d\t%f\n", n, ((float)(etime - stime)) / CLOCKS_PER_SEC);
		free(niz1);
		free(niz2);
	}
	return 0;
}
