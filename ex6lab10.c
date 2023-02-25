#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t lock;

void *increment(void *arg) 
{
    int i;
    for (i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() 
{
    pthread_mutex_init(&lock, NULL);
    pthread_t threads[15];
    int i;
    for (i = 0; i < 15; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }
    for (i = 0; i < 15; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("%d\n", count);
    return 0;
}