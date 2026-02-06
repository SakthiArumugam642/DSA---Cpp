#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
    // pipe creation
    int fd[2];
    if(pipe(fd) == -1) {
        perror("Pipe");
        return -1;
    }
    // FIFO creation
     if(mkfifo("/tmp/myfifo1", 0666) == -1 && errno != EEXIST){
        perror("mkfifo");
        return -1;
    }
    // shm
    int shmid = shmget('A',100,IPC_CREAT | 0666);
    char * ptr = shmat(shmid,NULL,0);

    int pid = fork();
    if(pid == 0){
        /*child process*/
        close(fd[1]);
        char a[100];
        // reading from pipe
        read(fd[0],a,100);
        // uppercase op.
        int i = 0;
        while(a[i]){
            a[i] = toupper(a[i]);
            i++;
        }
        // writing into shm
        strcpy(ptr,a);
        close(fd[0]);
    }
    else if(pid > 0){
        close(fd[0]);
        printf("Enter the string : ");
        char b[100];
        scanf("%[^\n]",b);
        getchar();
        write(fd[1],b,strlen(b)+1);
        close(fd[1]);
        char input[100];
        int fd1 = open("/tmp/myfifo1", O_RDONLY);
        if(fd1 == -1){
            perror("Open");
            return 0;
        }
        read(fd1, input,100);
        printf("The string is %s\n",input);
        close(fd1);
    }

}