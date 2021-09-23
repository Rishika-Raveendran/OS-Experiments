#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SHARED 1
#define buffersize 1
void *Producer();      // Make Declaration of Producer
void *Consumer();      // Make Declaration of Consumer
sem_t empty, full, sm; //Declare semaphores to be used
int data;

int main()
{
    pthread_t ptid, ctid;
    printf("\nMain Started");
    sem_init(&empty, SHARED, 1);
    sem_init(&full, SHARED, 0);
    sem_init(&sm, SHARED, 1);
    pthread_create(&ptid, NULL, Producer, NULL);
    pthread_create(&ctid, NULL, Consumer, NULL);
    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);
    printf("\nMain done\n");
}

void *Producer()
{

    int produced;
    printf("\nProducer created");
    printf("\nProducer id is %ld\n", pthread_self());
    for (produced = 0; produced < 100; produced++)
    {
        sem_wait(&empty);

        sem_wait(&sm);

        data = produced;

        sem_post(&sm);

        sem_post(&full);
        printf("\nProducer: %d", data);
    }
}

void *Consumer()
{
    int consumed, total = 0;
    printf("\nConsumer created\n");
    printf("\nConsumer id is %ld\n", pthread_self());
    for (consumed = 0; consumed < 100; consumed++)
    {
        sem_wait(&full);

        sem_wait(&sm);

        total = total + data;

        sem_post(&sm);

        sem_post(&empty);
        printf("\nConsumed: %d", data);
    }
}