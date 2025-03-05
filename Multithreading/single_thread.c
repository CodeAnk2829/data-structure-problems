#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables for storing sums
long long sum1, sum2, sum3;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }

    long long upper = atoll(argv[1]);
    if (upper < 0)
    {
        fprintf(stderr, "%lld must be >= 0\n", upper);
        return -1;
    }

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // First third of the numbers
    for (long long i = 1; i <= upper / 3; i++)
    {
        sum1 += i;
    }

    // Second third of the numbers
    for (long long i = (upper / 3) + 1; i <= 2 * (upper / 3); i++)
    {
        sum2 += i;
    }

    // Last third of the numbers
    for (long long i = (2 * (upper / 3)) + 1; i <= upper; i++)
    {
        sum3 += i;
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the results
    printf("sum1 = %lld\nsum2 = %lld\nsum3 = %lld\n", sum1, sum2, sum3);
    printf("Total sum = %lld\n", sum1 + sum2 + sum3);
    printf("Time taken without multithreading: %f seconds\n", cpu_time_used);

    return 0;
}
