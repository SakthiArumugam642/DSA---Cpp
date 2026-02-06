#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    if(argc < 4){
        printf("Error : Invalid arguments\nUsage : ./a.out <command1> '|' <command2>\n");
        return 0;
    }
    // printf("%s",argv[argc-1]);
    if((strcmp(argv[argc-1],"|") == 0) || (strcmp(argv[1],"|") == 0) ){
        printf("Error : Invalid arguments\nUsage : ./a.out <command1> '|' <command2>\n");
        return 0;
    }
    // for finding the '|' in command line argument vector
    int ind;
    for(int i = 0 ; i < argc ; i++){
        if(strcmp(argv[i],"|") == 0){
            argv[i] = NULL;
            ind = i+1;
            break;
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
        close(fd[0]); // closing the pipe_read
        dup2(fd[1],1);
        close(fd[1]);
        execvp(argv[1],argv+1);
        perror("execvp child1");
    }
    else if(ret > 0){
        /*parent process*/
        int ret1 = fork();
        if(ret1 == 0){
            /*child 2 process*/
            close(fd[1]); // closing the pipe_read
            dup2(fd[0],0);
            close(fd[0]);
            execvp(argv[ind],argv+ind);
            perror("execvp child2");
        }
        else if(ret1 > 0){
            /*parent process*/
            close(fd[0]);
            close(fd[1]);   
            wait(NULL);
            wait(NULL);
        }
    }
}