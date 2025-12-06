#include "recursive.h"
#include "iterative.h"
#define SIZE 10

int main(void){
    double time_recur = run_hanoi(SIZE);
    double time_iter = run_hanoi_iterative(SIZE);
    printf("\n it took %f ms for iterative algorithm and %f ms for recursive one \n",time_iter,time_recur);
}
