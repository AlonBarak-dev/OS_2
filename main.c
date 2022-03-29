#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
This program is inspired by the class work file in the section SIGNALS in the moodle
*/


void sig_handler(int signum){
    int i = 5;
    int j = 0;
    int k;

    switch(signum){
        
        case SIGCHLD:
            printf("Catched signal number %d \n", signum);
            fflush(stdout);
            raise(SIGUSR1);     // raise signal 
        case SIGUSR1:
            printf("Catched signal number %d \n", signum);
            fflush(stdout);
            k = i / j;      // divide by zero
            printf("lalala \n");
            fflush(stdout);
            break;
        case SIGFPE:
            printf("Catched signal number %d \n", signum);
            fflush(stdout);
            raise(SIGINT);      // raise signal
        case SIGINT:
            printf("Catched signal number %d \n", signum);
            fflush(stdout);
            raise(SIGTERM);     // raise signal
        case SIGTERM:
            printf("Catched signal number %d \n", signum);
            fflush(stdout);
            raise(SIGILL);     // raise signal
        case SIGILL:
            printf("Catched signal number %d \n", signum);
            fflush(stdout);
            exit(1);
    }

}


int main(){

        int status;
        // defining new signal habdlers 
        signal(SIGCHLD, sig_handler);
        signal(SIGUSR1, sig_handler);
        signal(SIGFPE, sig_handler);
        signal(SIGINT, sig_handler);
        signal(SIGTERM, sig_handler);
        signal(SIGILL, sig_handler);

        // creating a child process
        if(!(fork())){
            // child
            exit(1);
        }
        // waiting for child process - parent
        wait(&status);

        return 0;
    }