#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define KB 1024
#define MB 1024 * KB

int main() {
    unsigned int steps = 128 * 1024 * 1024;
    //static int arr[4 * 1024 * 1024];
    static char arr[128 * 1024 * 1024];
    int sizes[] = {
        1 * KB, 4 * KB, 8 * KB, 16 * KB, 32 * KB, 64 * KB, 128 * KB, 256 * KB,
        512 * KB, 1 * MB, 2 * MB, 4 * MB, 8 * MB, 12 * MB, 16 * MB, 32 * MB, 64 * MB,
    };

    for (unsigned int s = 0; s < sizeof(sizes)/sizeof(int); s++) {
	    int lengthMod = sizes[s] - 1;
	    clock_t start = clock();
        double timeTaken = 0;
        for (unsigned int t = 0; t < 10; t++ ) {
            for (unsigned int i = 0; i < steps; i++) {
                arr[(i * 32) & lengthMod]*=10;
                arr[(i * 32) & lengthMod]/=10;
            }
        }
	    timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("%d, %.1f \n", sizes[s] / KB, timeTaken);
    }

    return 0;
}
