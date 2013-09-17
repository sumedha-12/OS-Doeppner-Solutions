#include <stdio.h>
#include <time.h>
#include <signal.h>

int handler();
void show_status();
int long_running_procedure( struct timespec time_sleep, struct timespec time_rem);

int status = 0;
sigset_t set;

int main(int argc, char *argv[])
{
    struct timespec time_sleep, time_rem;
    time_sleep.tv_sec = 3;
    time_sleep.tv_nsec = 100;

    //sigset(SIGINT, handler);
    sigset(SIGINT, show_status);
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    long_running_procedure(time_sleep, time_rem);
}

int handler()
{
    printf("Handler is called\n");
}

void show_status()
{
    printf("Status = %d\n", status);
}

int long_running_procedure( struct timespec time_sleep, struct timespec time_rem)
{
    //extern int status;
    sigset_t old_set;
    while(1){
        nanosleep(&time_sleep, &time_rem);
        sigprocmask(SIG_BLOCK, &set, &old_set);
        status=status+1;
        //sigprocmask(SIG_SETMASK, &old_set, 0);
    }
}
