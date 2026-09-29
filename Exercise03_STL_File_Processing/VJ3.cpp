#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vrh {
	float x, y, z;
}Vrh;

typedef struct Trokut {
	Vrh normala;
	Vrh vrhovi[3];
	unsigned short boja;
}Trokut;

typedef struct Objekt3D {
	Trokut* niz;
	unsigned int n;
}Objekt3D;

Objekt3D* citanje(FILE* fp)
{
	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	if (!objekt)
		return NULL;
	fseek(fp, 80, SEEK_SET);
	fread(&objekt->n, sizeof(unsigned int), 1, fp);
	objekt->niz = (Trokut*)malloc(sizeof(Trokut) * objekt->n);
	if (objekt->niz)
	{
		for (int i = 0; i < objekt->n; i++)
		{
			fread(&objekt->niz[i], 50, 1, fp);
		}
		return objekt;
	}
	free(objekt);
	return NULL;
}

void zapisbin(FILE* fp, Objekt3D* obj)
{
	char buffer[80] = { 0 };
	fwrite(buffer, sizeof(char), 80, fp);
	fwrite(&obj->n, sizeof(unsigned int), 1, fp);
	for (int i = 0; i < obj->n; i++)
	{
		fwrite(&obj->niz[i], 50, 1, fp);
	}
}

void zapistxt(FILE* fp, Objekt3D* obj)
{
	fprintf(fp, "solid OpenSCAD_Model\n");
	for (int i = 0; i < obj->n; i++)
	{
		fprintf(fp, "\tfacet normal %f %f %f\n", obj->niz[i].normala.x, obj->niz[i].normala.y, obj->niz[i].normala.z);
		fprintf(fp, "\t\touter loop\n");
		fprintf(fp, "\t\t\tvertex %f %f %f\n", obj->niz[i].vrhovi[0].x, obj->niz[i].vrhovi[0].y, obj->niz[i].vrhovi[0].z);
		fprintf(fp, "\t\t\tvertex %f %f %f\n", obj->niz[i].vrhovi[1].x, obj->niz[i].vrhovi[1].y, obj->niz[i].vrhovi[1].z);
		fprintf(fp, "\t\t\tvertex %f %f %f\n", obj->niz[i].vrhovi[2].x, obj->niz[i].vrhovi[2].y, obj->niz[i].vrhovi[2].z);
		fprintf(fp, "\t\tendloop\n");
		fprintf(fp, "\tendfacet\n");
	}
	fprintf(fp, "endsolid OpenSCAD_Model\n");
}

void izbrisi(Objekt3D* obj)
{
	free(obj->niz);
	free(obj);
}



int main()
{
	FILE* fp = fopen("primjerbin.stl", "rb");
	if (!fp)
	{
		perror("Greska");
		return 0;
	}
	FILE* fp1 = fopen("primjerbin1.stl", "wb");
	if (!fp1)
	{
		perror("Greska");
		return 0;
	}
	FILE* fp2 = fopen("primjertxt1.stl", "wt");
	if (!fp2)
	{
		perror("Greska");
		return 0;
	}
	Objekt3D* rez = citanje(fp);
	printf("%d", rez->n);
	zapisbin(fp1, rez);
	zapistxt(fp2, rez);
	izbrisi(rez);
	fclose(fp);
	return 0;
}