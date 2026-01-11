#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int ret;
    ret = fork();
    if(ret == 0){
        /*child 1 process*/
        printf("A child is created with pid %d\n",getpid());
        sleep(5);
    }
    else if(ret > 0){
        /*Process process*/
        sleep(10);
         char buf[30];
        sprintf(buf,"/proc/%d/status",ret);
        int fd = open(buf,O_RDONLY);
        if(fd == -1){
            perror("Open");
            return 0;
        }
        int line_cnt = 0;
        char ch;
        while(read(fd,&ch,1) != 0){
            if(ch == '\n') line_cnt++;
            if(line_cnt == 4) break;
            printf("%c",ch);
        }
        close(fd);
        int old_pid = getpid();
        int ret1 = fork();
        if(ret1 == 0){
            /*child 2 process*/
            if(getppid() != 1){
                sleep(1);
            }
            if(getppid() == 1){
                printf("Child is cleared by init\n");
            }
        }

    }
}
