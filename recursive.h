#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pole {
    int * disks;
    int number_of_disks;
    char pole_name[10];
}pole;

void display(pole * P);

void move(pole * A ,pole * B);

void hanoi(int n , pole * A , pole *C , pole *B);
