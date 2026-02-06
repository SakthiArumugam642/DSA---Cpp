#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    if(argc < 6){
        printf("Error : Invalid arguments\nUsage : ./a.out <command1> '|' <command2> '|' <command3>\n");
        return 0;
    }
    // printf("%s",argv[argc-1]);
    if((strcmp(argv[argc-1],"|") == 0) || (strcmp(argv[1],"|") == 0) ){
        printf("Error : Invalid arguments\nUsage : ./a.out <command1> '|' <command2> '|' <command3>\n");
        return 0;
    }
    // for finding the '|' in command line argument vector
    int in[2], k = 0;
    for(int i = 0 ; i < argc ; i++){
        if(strcmp(argv[i],"|") == 0){
            argv[i] = NULL;
            in[k++] = i+1;
        }
    }
    int fd[2];
    if(pipe(fd) == -1) {
        perror("Pipe");
        return -1;
    }
    int ret = fork();
    if(ret == 0){
        /*child 1 process*/
        close(fd[0]);
        dup2(fd[1],0);
        execvp(argv[1],argv+1);
    }
    else if(ret > 0){
        /*parent process*/
        int fd1[2];
        if(pipe(fd1) == -1) {
            perror("Pipe");
            return -1;
        }
        int ret1 = fork();
        if(ret1 == 0){
            /*child 2 process*/
            close(fd[1]);
            dup2(fd[0],0);
            close(fd1[0]);
            dup2(fd[1],1);
            execvp(argv[in[0]],argv+in[0]);
        }
        else if(ret1 > 0){
            int ret2 = fork();
            if(ret2 == 0){
                /*child 3 process*/
                close(fd1[1]);
                dup2(fd1[0],0);
                execvp(argv[in[1]],argv+in[1]);
            }
            else if(ret1 > 0){
                /*parent process*/
                close(fd[0]);
                close(fd[1]);
                close(fd1[0]);
                close(fd1[1]);
                wait(NULL);
                wait(NULL);
                wait(NULL);
            }
        }
    }
}