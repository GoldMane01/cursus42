#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>



int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void *arg) {
    int index = *(int*)arg;
    int sum = 0;
    for (int j = 0; j < 5; j++) {
        sum += primes[index + j];
    }
    *(int*)arg = sum;
    return (arg);
}

int main() {
    pthread_t th[2];
    int i;
    for (i = 0; i < 2; i++) {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            return 1;
        }
    }
    int globalSum = 0;
    for (i = 0; i < 2; i++) {
        int *r;
        if (pthread_join(th[i], (void*) &r) != 0) {
            return 2;
        }
        globalSum += *r;
        free(r);
    }
    printf("Global sum: %d\n", globalSum);
    return (0);
}



/*
void* roll_dice() {
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    return ((void*) result);
}

int main() {
    int *res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return (1);
    }
    if (pthread_join(th, (void**) &res) != 0) {
        return (2);
    }
    printf("Result: %d\n", *res);
    free(res);
    return (0);
}
*/


/*
int mails = 0;
pthread_mutex_t mutex;


void* routine() {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t th[4];
    int i;

    pthread_mutex_init(&mutex, NULL);
    
    for (i = 0; i < 4; i++) {
        if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
            return 1;
        }
        printf("Thread %d has started\n", i);
    }
    for (i = 0; i < 4; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("Thread %d has finished\n", i);
    }

    pthread_mutex_destroy(&mutex);
    printf("Mails: %d\n", mails);
    
    
    //struct timeval time;
    //gettimeofday(&time, NULL);
    //printf("%ld\n%ld\n", time.tv_sec, time.tv_usec);
    return 0;
}
*/