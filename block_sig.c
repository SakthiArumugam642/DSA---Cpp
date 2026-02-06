#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void my_handler(int signum,siginfo_t * info, void * data)
{
        for(int i= 0 ; i < 5 ; i++){
                if(signum == SIGINT) printf("SIGINT is received\n");
                if(signum == SIGTSTP) printf("SIGTSTP is received\n");
                if(signum == SIGQUIT) printf("SIGQUIT is received\n");
                sleep(1);
        }
}
int main(){
        // allocating the memory for the struct sigaction
        struct sigaction new;
        //storing the information about the structure
        new.sa_sigaction = my_handler;
        new.sa_flags = SA_SIGINFO;

        sigaddset(&new.sa_mask,SIGINT);   // ctrl + c
        sigaddset(&new.sa_mask,SIGTSTP);  // ctrl + z
        sigaddset(&new.sa_mask,SIGQUIT);  // ctrl + \

        sigaction(SIGINT,&new,NULL);
        sigaction(SIGTSTP,&new,NULL);
        sigaction(SIGQUIT,&new,NULL);
        printf("Process %d waiting for the signal\n",getpid());
        while(1);

}




            