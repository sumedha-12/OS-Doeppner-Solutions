#include <stdio.h>
#include <pthread.h>
#include<semaphore.h>

sem_t empty, occupied;
int arr[10];
void* prod(void *val);
void* cons(void *val);

int main(int argc, char *argv[])
{
    pthread_t pth, cth;
    void *val;

    sem_init(&empty, 0, 10);  
    sem_init(&occupied, 0, 0);  
    pthread_create(&pth, 0, prod, val);
    pthread_create(&cth, 0, cons, val);

    pthread_join(pth, NULL);
    pthread_join(cth, NULL);
}

void* prod(void *val)
{
    sem_wait(&empty);
    if (next_write == 10)
        next_write = 0;
    arr[next_write++]=1234;
    sem_post(&occupied);
}

void* cons(void *val)
{
    sem_wait(&occupied);
    if (next_read == 10)
        next_read=0;
    printf("Read %d\n", arr[next_read]);
    sem_post(&empty);
}


}
