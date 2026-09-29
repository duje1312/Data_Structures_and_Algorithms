#include <stdio.h>
#include <stdlib.h>
#define N 10000


typedef struct {
    void* ptr;
    int broj_prioritet;
} clan;


typedef struct {
    clan* niz;
    int velicina;
} gomila;


gomila* stvaranje() {
    gomila* nova_gomila = (gomila*)malloc(sizeof(gomila));
    if (nova_gomila == NULL) {
        printf("Greska: Neuspjela alokacija memorije za gomilu.\n");
        return NULL;
    }
    nova_gomila->niz = (clan*)malloc(sizeof(clan) * N);
    if (nova_gomila->niz == NULL) {
        printf("Greska: Neuspjela alokacija memorije za niz.\n");
        free(nova_gomila);
        return NULL;
    }
    nova_gomila->velicina = 0;
    return nova_gomila;
}
void popravi_prema_gore_rekurzivno(gomila* heap, int indeks) {
    if (indeks > 0) {
        int roditelj = (indeks - 1) / 2;
        if (heap->niz[indeks].broj_prioritet > heap->niz[roditelj].broj_prioritet) {
            clan temp = heap->niz[indeks];
            heap->niz[indeks] = heap->niz[roditelj];
            heap->niz[roditelj] = temp;
            popravi_prema_gore_rekurzivno(heap, roditelj);
        }
    }
}

void umetanje(gomila* heap, clan child) {
    if (heap == NULL) {
        printf("Greska: Gomila ne postoji.\n");
        return;
    }

    if (heap->velicina >= N) {
        printf("Greska: Gomila je puna.\n");
        return;
    }
    heap->niz[heap->velicina] = child;
    heap->velicina++;
    popravi_prema_gore_rekurzivno(heap, heap->velicina - 1);
}


void popravi_prema_dnu_rekurzivno(gomila* heap, int indeks) {
    int lijevo = 2 * indeks + 1;
    int desno = 2 * indeks + 2;
    int najveci = indeks;

    if (lijevo < heap->velicina && heap->niz[lijevo].broj_prioritet > heap->niz[najveci].broj_prioritet) {
        najveci = lijevo;
    }
    if (desno < heap->velicina && heap->niz[desno].broj_prioritet > heap->niz[najveci].broj_prioritet) {
        najveci = desno;
    }

    if (najveci != indeks) {
        clan temp = heap->niz[indeks];
        heap->niz[indeks] = heap->niz[najveci];
        heap->niz[najveci] = temp;
        popravi_prema_dnu_rekurzivno(heap, najveci);
    }
}

clan uklanjanje(gomila* heap) {
    if (heap == NULL || heap->velicina == 0) {
        printf("Greska: Gomila je prazna ili ne postoji.\n");
        clan prazan = { NULL, -1 };
        return prazan;
    }

    clan vrh = heap->niz[0];
    heap->niz[0] = heap->niz[heap->velicina - 1];
    heap->velicina--;

    popravi_prema_dnu_rekurzivno(heap, 0);
    return vrh;
}


int main() {
    gomila* heap = stvaranje();
    if (heap == NULL) return 0;

    clan a = { NULL, 10 };
    clan b = { NULL, 20 };
    clan c = { NULL, 15 };
    clan d = { NULL, 30 };

    umetanje(heap, a);
    umetanje(heap, b);
    umetanje(heap, c);
    umetanje(heap, d);

    printf("Najvazniji element: %d\n", uklanjanje(heap).broj_prioritet);
    printf("Najvazniji element: %d\n", uklanjanje(heap).broj_prioritet);
    printf("Najvazniji element: %d\n", uklanjanje(heap).broj_prioritet);
    printf("Najvazniji element: %d\n", uklanjanje(heap).broj_prioritet);


    free(heap->niz);
    free(heap);

    return 0;
}
