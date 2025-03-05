#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

long long sum = 0;     // this data is shared by the threads
pthread_mutex_t mutex; // mutex for protecting the shared variable

// Structure to pass data to the thread
typedef struct
{
    long long start;
    long long end;
} ThreadData;

void *runner(void *param); // the thread function

int main(int argc, char *argv[])
{
    pthread_t tid1, tid2;    // thread identifiers
    pthread_attr_t attr;     // set of thread attributes
    ThreadData data1, data2; // data for each thread

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

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // get the default attributes
    pthread_attr_init(&attr);

    // Divide the work between the two threads
    data1.start = 1;
    data1.end = upper / 2; // first thread handles the first half

    data2.start = (upper / 2) + 1;
    data2.end = upper; // second thread handles the second half

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Create the first thread
    pthread_create(&tid1, &attr, runner, &data1);
    // Create the second thread
    pthread_create(&tid2, &attr, runner, &data2);

    // Wait for both threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("sum = %lld\n", sum);
    printf("time taken: %f seconds\n", cpu_time_used);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

// The thread will begin control in this function
void *runner(void *param)
{
    ThreadData *data = (ThreadData *)param;
    long long i, partial_sum = 0;

    for (i = data->start; i <= data->end; i++)
    {
        partial_sum += i;
    }

    // Lock mutex before updating the shared sum variable
    pthread_mutex_lock(&mutex);
    sum += partial_sum;
    // Unlock mutex after updating the shared sum variable
    pthread_mutex_unlock(&mutex);

    pthread_exit(0);
}
