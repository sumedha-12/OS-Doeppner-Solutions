#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* test(void *data);
void* test1(void *data);
void destri(void *a);

int errono;

int main(int argc, char *argv[])
{
    pthread_t th, th1;
    void *val = (void *)1;
    void *val1 = (void *)2;

    pthread_key_create(&errono, destri);

    pthread_create(&th, 0, test, val );
    pthread_create(&th1, 0, test, val1);

    printf("Global value = %d\n", errono);

    pthread_join(th, NULL);
    pthread_join(th1, NULL);
}

void* test(void *data)
{
    if (data==(void*)1) 
        pthread_setspecific(errono, (void *)1000);
    void *val = pthread_getspecific(errono);
    printf("Value = %d\n",(int) val);
}

void destri(void *a)
{
    printf("Inside Dest\n");
    void *val = pthread_getspecific(errono);
    printf("Dest Value = %d\n",(int) val);
}
