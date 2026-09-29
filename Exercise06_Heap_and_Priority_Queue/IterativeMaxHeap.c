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
//iterativno
void popravi_prema_gore(gomila* heap, int indeks) {
    while (indeks > 0) {
        int roditelj = (indeks - 1) / 2;
        if (heap->niz[indeks].broj_prioritet > heap->niz[roditelj].broj_prioritet) {
            clan temp = heap->niz[indeks];
            heap->niz[indeks] = heap->niz[roditelj];
            heap->niz[roditelj] = temp;
            indeks = roditelj;
        }
        else {
            break;
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
    popravi_prema_gore(heap, heap->velicina - 1);
}
 

//iterativno
void popravi_prema_dnu(gomila* heap, int indeks) {
    if (heap == NULL) {
        printf("Greska: Gomila ne postoji.\n");
        return;
    }

    while (1) {
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
            indeks = najveci;
        }
        else {
            break;
        }
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

    popravi_prema_dnu(heap, 0);
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
