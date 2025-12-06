
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
 //       display(A);
  //     display(B);
  //     display(C);
        hanoi(n-1 ,B,C,A);
    }
}

double run_hanoi(int number_of_disks) {

    int disks [number_of_disks];
    for (int i = 0; i<number_of_disks; i++){
        disks[i] = number_of_disks - i;
     //   printf("%d \n",disks[i]);
    }

    pole A = {disks, number_of_disks , "A"};
    pole B = {malloc( number_of_disks * sizeof(int)),0 , "B"};
    pole C = {malloc( number_of_disks * sizeof(int)),0 , "C"};
   
 // display(&A);
 // display(&B);
 // display(&C);

   clock_t begin = clock();
   hanoi(number_of_disks, &A, &C, &B);
   clock_t end = clock();
   double time_spent = (double)(end - begin)/CLOCKS_PER_SEC ;
   time_spent *= 1000;
   //printf("the time spent for %d disks is %f ms \n" , number_of_disks , time_spent);
   return time_spent;
}



