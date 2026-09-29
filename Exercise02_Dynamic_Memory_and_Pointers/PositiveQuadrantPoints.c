#include "Point.h"
#include <stdio.h>
#include <stdlib.h>

poligon* n_poligon(float* niz_x, float* niz_y, int n) {
	poligon* p = (poligon*)malloc(sizeof(poligon));
	p->n = n;
	p->vrhovi = (tocka*)malloc(n * sizeof(tocka));
	for (int i = 0;i < n;i++) {
		p->vrhovi[i].x = niz_x[i];
		p->vrhovi[i].y = niz_y[i];
	}
	return p;
}
tocka** pozitivni(poligon* p, int* np) {
	*np = 0;
	for (int i = 0;i < p->n;i++) {
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
			(*np)++;
		}
	}
	tocka** pozi_niz = (tocka**)malloc(*np * sizeof(tocka*));
	int j = 0;
	for (int i = 0;i < p->n;i++) {
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
			pozi_niz[j++] = &(p->vrhovi[i]);
		}
	}
	return pozi_niz;
}



int main(void) {
	int n;
	printf("Unesite broj vrhova:\n");
	scanf("%d", &n);
	if (n < 3) {
		printf("moramo imati barem 3 vrha\n");
		return 1;
	}

	float* niz_x = (float*)malloc(n * sizeof(float));
	float* niz_y = (float*)malloc(n * sizeof(float));


	for (int i = 0;i < n;i++) {
		printf("unesi kordinatu za x %d\n", i + 1);
		scanf("%f", &niz_x[i]);
		printf("unesi kordinatu za y %d\n", i + 1);
		scanf("%f", &niz_y[i]);
	}
	poligon* p = n_poligon(niz_x, niz_y, n);
	for (int i = 0;i < p->n;i++) {
		printf("\n(%f,%f)\n", p->vrhovi[i].x, p->vrhovi[i].y);
	}
	int np;
	tocka** pozi_niz = pozitivni(p,&np); 
	printf("Pozitivni:");
	for (int i = 0;i < np;i++) {
		printf("\n%p\n",pozi_niz[i]);
	}
	free(pozi_niz);
	free(niz_x);
	free(niz_y);
	free(p->vrhovi);
	free(p);

	return 0;
}


















