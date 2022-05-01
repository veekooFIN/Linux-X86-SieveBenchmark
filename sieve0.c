#include <stdio.h>
#include <time.h>

#define true 1
#define false 0
#define size 8190
#define sizepl 8191
char flags[sizepl];

void main() {
    int i, prime, k, count, iter;

    printf("10 iterations\n");
    
    clock_t t;
    t = clock();

    for (iter = 1; iter <= 10; iter ++) {
        count=0 ; 
	for (i = 0; i <= size; i++)
	    flags[i] = true; 
        for (i = 0; i <= size; i++) { 
	    if (flags[i]) {
                prime = i + i + 3; 
                k = i + prime; 
                while (k <= size) { 
                    flags[k] = false; 
                    k += prime; 
                }
                count = count + 1;
            }
        }

    }


    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("\n%d primes\n", count);
    printf("\nTook %f seconds to execute \n", time_taken);
    printf("\nYour machine is %f times faster than Z80-Sieve-benchmark\n", 14.000/time_taken);


}
