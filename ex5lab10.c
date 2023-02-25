#include <stdio.h>
#include <pthread.h>

// Global variable to store the count
int count = 0;

// Function to be executed by each thread
void *increment(void *arg) 
{
    // Increment the count 100 times
    int i;
    for (i = 0; i < 100; i++) 
    {
        count++;
    }
    // Return NULL to indicate that the thread is finished
    return NULL;
}

int main() 
{
    // Create an array to hold the threads
    pthread_t threads[15];

    // Create 15 threads
    int i;
    for (i = 0; i < 15; i++) 
    {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    // Wait for all of the threads to finish
    for (i = 0; i < 15; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    // Print the final value of the count variable
    printf("%d\n", count);

    // Return 0 to indicate that the program has finished successfully
    return 0;
}