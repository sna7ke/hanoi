#ifndef ITERATIVE_H
#define ITERATIVE_H

#include "recursive.h" /* utilise le type pole */

void display_iter(pole *P);
void move_iter(pole *A, pole *B);
void hanoi_iterative(int n, pole *A, pole *B, pole *C);
double run_hanoi_iterative (int number_of_disks);

#endif // ITERATIVE_H
