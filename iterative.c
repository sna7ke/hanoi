/* iterative.c
   Version itérative du Tower of Hanoi.
   Les noms des helpers sont suffixés _iter pour éviter conflit avec recursive.c.
   Comportement et affichages identiques à ta version originale.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "iterative.h"

/* même séparateur visuel */
void separator_iter() {
    printf("\n----------------------------------------\n\n");
}

/* affichage (itératif) */
void display_iter(pole *P) {
    printf("Poteau %s :\n", P->pole_name);
    if (P->number_of_disks == 0) {
        printf("  (vide)\n");
        return;
    }
    for (int i = P->number_of_disks - 1; i >= 0; i--) {
        printf("  disque %d\n", P->disks[i]);
    }
}

/* déplace un disque d'un poteau à un autre (itératif) */
void move_iter(pole *A, pole *B) {
    if (A->number_of_disks <= 0) return;
    int d = A->disks[A->number_of_disks - 1];
    A->number_of_disks--;
    B->disks[B->number_of_disks] = d;
    B->number_of_disks++;
    printf("Déplacement disque %d : %s -> %s\n", d, A->pole_name, B->pole_name);
}

/* choix légal d'un mouvement entre X et Y (itératif) */
void legal_move_iter(pole *X, pole *Y) {
    if (X->number_of_disks == 0) {
        move_iter(Y, X);
    } else if (Y->number_of_disks == 0) {
        move_iter(X, Y);
    } else if (X->disks[X->number_of_disks - 1] < Y->disks[Y->number_of_disks - 1]) {
        move_iter(X, Y);
    } else {
        move_iter(Y, X);
    }
}

/* fonction itérative principale — même algorithme que celui que tu as donné */
void hanoi_iterative(int n, pole *A, pole *B, pole *C) {
    long total_moves = (1L << n) - 1;  /* pow(2,n)-1 en entier */

    pole *dest = C;
    pole *aux = B;
    if (n % 2 == 0) {
        dest = B;
        aux = C;
    }

    for (long i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) {
            legal_move_iter(A, dest);
        } else if (i % 3 == 2) {
            legal_move_iter(A, aux);
        } else {
            legal_move_iter(aux, dest);
        }

        /* prints identiques (mais avec les helpers itératifs) */
        display_iter(A);
       display_iter(B);
       display_iter(C);
        separator_iter();
    }
}
 double run_hanoi_iterative (int number_of_disks) {

    int *base_iter = malloc(number_of_disks * sizeof(int));
    if (!base_iter) { perror("malloc"); return -1 ; }
    for (int i = 0; i < number_of_disks; i++) base_iter[i] = number_of_disks - i;

    pole Ait = { base_iter, number_of_disks, "A" };
    pole Bit = { malloc(number_of_disks * sizeof(int)), 0, "B" };
    pole Cit = { malloc(number_of_disks * sizeof(int)), 0, "C" };

    if (!Bit.disks || !Cit.disks) { perror("malloc"); free(base_iter); return -1; }

    display_iter(&Ait);
   display_iter(&Bit);
   display_iter(&Cit);

    clock_t begin_it = clock();
    hanoi_iterative(number_of_disks, &Ait, &Bit, &Cit);
    clock_t end_it = clock();

    double time_it_ms = ((double)(end_it - begin_it) / CLOCKS_PER_SEC) * 1000.0;
 //   printf("Temps total (iteratif) pour %d disques : %.3f ms\n\n", number_of_disks, time_it_ms);
    return time_it_ms;

    free(Ait.disks);
    free(Bit.disks);
    free(Cit.disks);

}
