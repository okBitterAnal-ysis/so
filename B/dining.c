#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t forks[3];

void* philosopher(void* num) {

    int id = *(int*)num;

    int left = id;
    int right = (id + 1) % 3;

    for(int i=0;i<2;i++) {

        printf("Philosopher %d is thinking\n", id);

        sleep(1);

        if(id == 2) {

            pthread_mutex_lock(&forks[right]);
            pthread_mutex_lock(&forks[left]);
        }

        else {

            pthread_mutex_lock(&forks[left]);
            pthread_mutex_lock(&forks[right]);
        }

        printf("Philosopher %d is eating\n", id);

        sleep(1);

        pthread_mutex_unlock(&forks[left]);
        pthread_mutex_unlock(&forks[right]);
    }

    return NULL;
}

int main() {

    pthread_t p[3];

    int id[3] = {0,1,2};

    for(int i=0;i<3;i++)
        pthread_mutex_init(&forks[i], NULL);

    for(int i=0;i<3;i++)
        pthread_create(&p[i], NULL, philosopher, &id[i]);

    for(int i=0;i<3;i++)
        pthread_join(p[i], NULL);

    return 0;
}
