
#include "recursive.h"
#define SIZE 20

int main(void){
    int disks [SIZE];
    for (int i = 0; i<SIZE ; i++){
        disks[i] = SIZE - i;
     //   printf("%d \n",disks[i]);
    }

    pole A = {disks,SIZE , "A"};
    pole B = {malloc(SIZE * sizeof(int)),0 , "B"};
    pole C = {malloc(SIZE * sizeof(int)),0 , "C"};
   
   display(&A);
   display(&B);
   display(&C);

   clock_t begin = clock();
   hanoi(SIZE, &A, &C, &B);
   clock_t end = clock();
   double time_spent = (double)(end - begin)/CLOCKS_PER_SEC ;
   time_spent *= 1000;
   printf("the time spent for %d disks is %f ms \n" , SIZE , time_spent);
}
