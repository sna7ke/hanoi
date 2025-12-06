#include "recursive.h"
#include "iterative.h"
#define SIZE 40

int main(void){
    double time_recur = run_hanoi(SIZE);
    double time_iter = run_hanoi_iterative(SIZE);
    printf("\n it took %f ms for iterative algorithm and %f ms for recursive one \n",time_iter,time_recur);



    /* --------------------------
       Résumé comparatif simple
       -------------------------- */
    //printf("==== Résumé ====\n");
    //printf("Recursif : %.3f ms\n", time_rec_ms);
   // printf("Iteratif : %.3f ms\n", time_it_ms);

}
