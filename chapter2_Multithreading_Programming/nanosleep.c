#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct timespec relative_sleep, abs_sleep;
    struct timeval now;
    gettimeofday(&now);

    relative_sleep.tv_sec = 3;
    relative_sleep.tv_nsec = 100;

    abs_sleep.tv_sec = now.tv_sec + relative_sleep.tv_sec;
    abs_sleep.tv_nsec = now.tv_usec*1000 + 

    printf("Start\n");
    nanosleep(&time_sleep,&time_rem); 
    printf("End\n");
}

