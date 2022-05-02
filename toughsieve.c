#include <stdio.h>
#include <string.h>
#include <time.h>

/** This is a more substantial modification of the sieve program.
    Besides the sieve1 modifications, sieve2 uses memset to clear the flag array
    and the sieve loop has been moved into its own leaf function. **/

#define true 1
#define false 0
#define size 80000000
#define sizepl 80000001

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
    printf("\nYour machine is %f times faster than Win10-X86-PC/i3-4000M(C)-ToughSieve-benchmark\n", 29.873000/time_taken);
    printf("Your machine is %f times faster than Linux-X86-PC/Ryzen7-1700X(C)-ToughSieve-benchmark\n", 23.778366/time_taken);
    printf("Your machine is %f times faster than Linux-X86-PC/i7-8850H(C)-ToughSieve-benchmark\n", 12.723097/time_taken);
           
    return 0;
}

