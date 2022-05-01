#include <stdio.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0
#define size 8190
#define sizepl 8191

char flags[sizepl];

int sieve() {
    int i, prime, k, count;
    count=0 ; 
    for (i = 0; i != size; i++) { 
        if (flags[i]) {
            prime = i + i + 3; 
            k = prime + i; 
            while (size - k >= 0) { 
                flags[k] = false; 
                k += prime; 
            }
            count = count + 1;
        }
    }
    return count;
}

int main() {
    int iter, count;

    printf("10 iterations\n");
    
    clock_t t;
    t = clock();
    
    for (iter = 1; iter <= 10; iter ++) {
        memset(flags, 1, sizepl);
        count = sieve();
    }
    
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
    printf("\n%d primes\n", count);
    printf("\nTook %f seconds to execute \n", time_taken);
    printf("\nYour machine is %f times faster than Z80-Sieve-benchmark\n", 14.000/time_taken);
    return 0;
}

