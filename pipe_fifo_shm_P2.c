    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
    #include <sys/stat.h>

    int main(){
        int shmid = shmget('A',100,0666);
        char * ptr = shmat(shmid,NULL,0);
        char b[100];
        strcpy(b,ptr);

        // reversing the string
        for(int i = 0, j = strlen(b)-1; i < j ; i++, j--){
            char t = b[i];
            b[i] = b[j];
            b[j] = t;
        }
        int fd = open("/tmp/myfifo1", O_WRONLY);
        if(fd == -1){
                perror("Open");
                return -1;
        }
        write(fd, b, strlen(b)+1);
        close(fd);
    }