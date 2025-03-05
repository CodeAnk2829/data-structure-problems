#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

// Global variables for storing sums
long long sum1, sum2, sum3;

// Structure to pass data to the thread
typedef struct
{
    long long start;
    long long end;
    long long *partial_sum; // to store the sum calculated by the thread
} ThreadData;

// Thread functions
void *runner(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid1, tid2, tid3; // Thread identifiers
    pthread_attr_t attr;        // Set of thread attributes

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

    // Initialize thread data for each thread
    ThreadData data1 = {1, upper / 3, &sum1};                     // First thread sums from 1 to upper/3
    ThreadData data2 = {(upper / 3) + 1, 2 * (upper / 3), &sum2}; // Second thread sums from upper/3 + 1 to 2 * upper/3
    ThreadData data3 = {(2 * (upper / 3)) + 1, upper, &sum3};     // Third thread sums from 2 * upper/3 + 1 to upper

    // Get the default attributes
    pthread_attr_init(&attr);

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Create the threads
    pthread_create(&tid1, &attr, runner, &data1);
    pthread_create(&tid2, &attr, runner, &data2);
    pthread_create(&tid3, &attr, runner, &data3);

    // Wait for the threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the results
    printf("sum1 = %lld\nsum2 = %lld\nsum3 = %lld\n", sum1, sum2, sum3);
    printf("Total sum = %lld\n", sum1 + sum2 + sum3);
    printf("Time taken with multithreading: %f seconds\n", cpu_time_used);

    return 0;
}

// The thread function calculates the sum for its range
void *runner(void *param)
{
    ThreadData *data = (ThreadData *)param;
    long long i, partial_sum = 0;

    for (i = data->start; i <= data->end; i++)
    {
        partial_sum += i;
    }

    *(data->partial_sum) = partial_sum; // Store the partial sum

    pthread_exit(0);
}
