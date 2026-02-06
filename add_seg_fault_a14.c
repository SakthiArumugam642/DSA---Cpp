#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void my_handler(int signum,siginfo_t * info, void * data)
{
        printf("Seg fault(core dumped)\n");
        printf("seg fault address is %p\n",info->si_addr);
        exit(0);
}
int main(){
        // allocating the memory for the struct sigaction
        struct sigaction new;
        //storing the information about the structure
        new.sa_sigaction = my_handler;
        new.sa_flags = SA_SIGINFO; // 0 => signal , SA_SIGINFO => sigaction
        sigaction(SIGSEGV,&new,NULL); // registering the signal
        // creating seg fault
        int * ptr = (int*)10; 
        *ptr = 10;
}