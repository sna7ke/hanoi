
#include "recursive.h"


void display(pole * P) {
    printf("\n the disks on pole %s are as follows : \n",P->pole_name);
    for(int n =0 ; n<P->number_of_disks; n++) {
        printf("| disk : %d |\n", P->disks[n]);
    }
}

void move(pole * A ,pole * B){

    int disk = A->disks[A->number_of_disks-1];
    A->number_of_disks--;

    B ->disks[B->number_of_disks] = disk;
    B->number_of_disks++;

   //printf("we moved from the pole %s the disk with size %d to the pole %s \n",A->pole_name,disk,B->pole_name);
   //printf("current number of disks in %s would be : %d \n",A->pole_name,A->number_of_disks);
}

void hanoi(int n , pole * A , pole *C , pole *B) {
    if(n != 0) {
        hanoi(n-1,A,B,C);
        move(A ,C);
        display(A);
        display(B);
        display(C);
        hanoi(n-1 ,B,C,A);
    }
}



