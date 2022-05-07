#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main() {
    unsigned int steps = 256 * 1024 * 1024;
    static int a[2];
    clock_t start;

    start = clock();
    for (unsigned int i=0; i < steps; i++) {
        a[0]++;
        a[0]--;
        a[0]++;
        a[0]--;
    }
    double timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("Time taken for single variable: %.8f \n", timeTaken);

    start = clock();
    for (unsigned int i=0; i < steps; i++) {
        a[0]++;
        a[0]--;
        a[1]++;
        a[1]--;
    }
    timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("Time taken for double variable: %.8f \n", timeTaken);

    a[0]++;
    a[1]++;
    return 0; 
}
