#include "Tocka.h"
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




int main(void){
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
		printf("unesi kordinatu za x %d\n",i+1);
		scanf("%f", &niz_x[i]);
		printf("unesi kordinatu za y %d\n",i+1);
		scanf("%f", &niz_y[i]);
	}
	poligon* p = n_poligon(niz_x, niz_y, n);
	for (int i = 0;i < p->n;i++) {
		printf("(%f,%f)", p->vrhovi[i].x, p->vrhovi[i].y);
	}
	free(niz_x);
	free(niz_y);
	free(p->vrhovi);
	free(p);

	return 0;
}


















