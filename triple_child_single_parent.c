#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
        int ret = fork();
        int status;
        if(ret == -1){
                perror("Fork1");
                return -1;
        }
        if(ret == 0 ){
            printf("Child 1 with pid %d created\n",getpid());
            sleep(1);
            return 0;
        }
        if(ret > 0){
                int ret2 = fork();
                if(ret2 == -1){
                        perror("Fork2");
                        return -1;
                }
                if(ret2 == 0){
                    printf("Child 2 with pid %d created\n",getpid());
                    sleep(2);
                    return 0;
                }
                if(ret2 > 0){
                    int ret3 = fork();
                    if(ret3 == -1){
                            perror("Fork3");
                            return -1;
                    }
                    if(ret3 == 0){
                        printf("Child 3 with pid %d created\n",getpid());
                        sleep(3);
                        return 0;
                    }
                    if(ret3 > 0){
                       int ret= wait(&status);
                        if(WIFEXITED(status)){
                            printf("Child %d is terminated with code %d\n",ret,WEXITSTATUS(status));
                        }
                        ret = wait(&status);
                        if(WIFEXITED(status)){
                            printf("Child %d is terminated with code %d\n",ret,WEXITSTATUS(status));
                        }
                       ret = wait(&status);
                       if(WIFEXITED(status)){
                            printf("Child %d is terminated with code %d\n",ret,WEXITSTATUS(status));
                        }
                    }
                }
        }
        return 0;
}