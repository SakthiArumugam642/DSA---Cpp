#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    if(argc <= 1){
        printf("Too few arguments\nUsage ./a.out <commands>\n");
        return 0;
    }
    int ret = fork();
    if(ret == 0){
        /*child process*/
        printf("This is the chiild process with pid %d\n",getpid());
        if(execvp(argv[1],argv+1) == -1){
            perror("Execvp");
            return 0;
        }
    }
    else if(ret > 0){
        /*parent process*/
        int sts;
        wait(&sts);
        if(WIFEXITED(sts)){
            printf("Child exited with status %d\n",WEXITSTATUS(sts));
        }
    }
}