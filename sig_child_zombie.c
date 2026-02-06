#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/*method 1*/
void my_handler(int signum,siginfo_t * info, void * data)
{
        int sts;
        if(signum == SIGCHLD){
            waitpid(info->si_pid,&sts,WNOHANG);
            printf("child with pid %d terminates successfully with exit status %d\n",info->si_pid,sts);
            exit(0);
        }
}
int main(){
        // allocating the memory for the struct sigaction
        struct sigaction new;
        //storing the information about the structure
        new.sa_sigaction = my_handler;
        new.sa_flags = SA_SIGINFO;
        sigaction(SIGCHLD,&new,NULL); // registering the signal
        int pid = fork();
        if(pid > 0){
            /*parent process*/
            sleep(1);
        }
        else if(pid == 0){
            /*child process*/
        }
}
#if 0
/*method 2*/
void my_handler(int signum,siginfo_t * info, void * data)
{
        printf("child with pid %d terminates successfully with exit status %d\n",info->si_pid,info->si_status);
        exit(0);
}
int main(){
        // allocating the memory for the struct sigaction
        struct sigaction new;
        //storing the information about the structure
        new.sa_sigaction = my_handler;
        new.sa_flags = SA_SIGINFO | SA_NOCLDWAIT;
        sigaction(SIGCHLD,&new,NULL); // registering the signal
        int pid = fork();
        if(pid > 0){
            /*parent process*/
            sleep(1);
        }
        else if(pid == 0){
            /*child process*/
        }
}
#endif