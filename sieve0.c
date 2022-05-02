#include <stdio.h>
#include <time.h>

/** This is the genuine C program of the sieve benchmark.
    The only additions are the #include directives above
    and the timing code enabled by the preprocessor symbol TIMER. **/

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
    printf("\nYour machine is %f times faster than Z80(PL/I)-Sieve-benchmark\n", 14.000/time_taken);
    printf("Your machine is %f times faster than Intel 8086(Asm)(8 MHz)-Sieve-benchmark\n", 1.90/time_taken);
    printf("Your machine is %f times faster than Motorola 68000(Asm)(8 MHz)-Sieve-benchmark\n", 1.12/time_taken);
    printf("Your machine is %f times faster than Cray1 supercomputer(Fortran)-Sieve-benchmark\n", 0.110/time_taken);
    printf("Your machine is %f times faster than RPi modelB(C)-Sieve-benchmark\n", 0.0205/time_taken);
    printf("Your machine is %f times faster than Linux-X86-PC/Ryzen7-1700X(C)-Sieve-benchmark\n", 0.000893/time_taken);
    printf("Your machine is %f times faster than Linux-X86-PC/i7-4770K(C)-Sieve-benchmark\n", 0.00071/time_taken);
    printf("Your machine is %f times faster than Linux-X86-PC/i7-8850H(C)-Sieve-benchmark\n", 0.000582/time_taken);

}
