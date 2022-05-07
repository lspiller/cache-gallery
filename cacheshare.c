#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define KB 1024
#define MB 1024 * 1024

int main(int argc, char *argv[]) {
    const unsigned int size = 4 * MB;
    if ( argc != 5 )
        goto badexit;
    int proc = fork();
    int proc2 = fork();
    int position;
    if (proc && proc2) position = atoi(argv[0]);
    else if (proc2)    position = atoi(argv[1]);
    else if (proc)     position = atoi(argv[2]);
    else               position = atoi(argv[3]);
    printf("proc: %d\n", position);

    char *arr =malloc(size*sizeof(char));

    clock_t start = clock();
    for( unsigned int j=0; j < 1000000000; j++ ) {
        arr[position] += 3;
    }

    double timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("time: %.8f \n", timeTaken);

    return 0;
    badexit: printf("ERROR\n"); return 1;
}
//private static int[] s_counter = new int[1024];
//private void UpdateCounter(int position)
//{
//    for (int j = 0; j < 100000000; j++)
//    {
//        s_counter[position] = s_counter[position] + 3;
//    }
//}
//}
