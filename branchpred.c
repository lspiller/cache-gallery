#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define KB 1024
#define MB 1024 * KB

int main() {
    const unsigned int max = 1000000000;
    for (unsigned int freq=1; freq < 20; freq++ ) {
        clock_t start = clock();
        int sum = 0;
        int other = 0;
        for (unsigned int i = 0; i < max; i++)
            if (!(i&freq)) sum++;
            else        other+=2;
        double timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("True frequency of %d: %.3f \n", freq, timeTaken);
    }
}
