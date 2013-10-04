#include <stdio.h>
#include <pthread.h>

void* proc(void *val);
void* proc_try(void *val);

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{
    pthread_t pth, cth;
    void *val;
    pthread_create(&pth, 0, proc, val);
    pthread_create(&cth, 0, proc_try, val);

    pthread_join(pth, NULL);
    pthread_join(cth, NULL);
}

void* proc(void *val)
{
    pthread_mutex_lock(&m);
    printf("A\n");
    sleep(10);
    pthread_mutex_lock(&m2);
    printf("B\n");
    pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m);
}

void* proc_try(void *val)
{
    while(1){
        pthread_mutex_lock(&m2);
        if(!pthread_mutex_trylock(&m))
            break;
        pthread_mutex_unlock(&m2);
    }
    printf("Critical section of the proc_try\n");
    pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m);
  
}
