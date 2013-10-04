#include <stdio.h>
#include <pthread.h>

void* proc(void *val);
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{
    pthread_t pth, cth;
    void *val;
    pthread_create(&pth, 0, proc, val);
    pthread_create(&cth, 0, proc, val);

    pthread_join(pth, NULL);
    pthread_join(cth, NULL);
}

void* proc(void *val)
{
    pthread_mutex_lock(&m);
    printf("A\n");
    sleep(5);
    printf("B\n");
    sleep(5);
    printf("C\n");
    sleep(5);
    printf("D\n");
    sleep(5);
    pthread_mutex_unlock(&m);
}
