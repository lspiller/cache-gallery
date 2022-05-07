#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define KB 1024
#define MB 1024 * KB

int main() {
    const unsigned int size = 64*MB;
    static char arr[size];

    const unsigned int reps = 1024 * 1024;
    

    int steps[] = {1, 2, 4, 5, 6, 7, 8, 16, 32, 50, 64, 100, 128, 150, 256, 500, 512, 520, 1024};
    int sizes[] = {
        1 * KB, 4 * KB, 8 * KB,
        16 * KB, 32 * KB, 64 * KB,
        128 * KB, 256 * KB, 512 * KB,
        1 * MB, 2 * MB, 4 * MB, 8 * MB, 16 * MB, 32 * MB,
    };

    for (unsigned int st = 0; st < sizeof(steps)/sizeof(int); st++) {
        for (unsigned int si = 0; si < sizeof(sizes)/sizeof(int); si++) {
            clock_t start = clock();
            int length = sizes[si];
            int step = steps[st];
            unsigned int p = 0;
            for (unsigned int i=0; i < reps; i++) {
                arr[p]++;
                arr[p]--;
                p += step;
                //if (p > length) p = 0;
                p = (p <= length) * p;
            }
            double timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
            printf("Time taken for step %d, length %d: %.4f \n", step, length, timeTaken);
        }
    }


    return 0; 
}
