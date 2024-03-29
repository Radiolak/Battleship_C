#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void pid_handler(int signum, siginfo_t *siginfo, void *other)
{
    sig_reception = siginfo->si_pid;
    (void)siginfo;
    (void)other;
    (void)signum;
    return ;
}

void get_calling_pid(void)
{
    struct sigaction sa;

    sa.sa_sigaction = &pid_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}