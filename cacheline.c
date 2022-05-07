#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define KB 1024
#define MB 1024 * KB

int main() {
    const unsigned int size = 64*MB;
    static char arr[size];
    unsigned int trials = 10;

    int steps[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    for (unsigned int s = 0; s < sizeof(steps)/sizeof(int); s++) {
	    int step = steps[s];
        clock_t start = clock();
        for( unsigned int t = 0; t < trials*step; t++ ) {
            for( unsigned int i=0; i < size; i+=step ) {
                arr[i]++;
                arr[i]--;
            }
        }
        double timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;

        printf("Time taken for steps of %d: %.8f \n", step, timeTaken);
    }

    return 0; 
}
