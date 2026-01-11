#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Insufficient arguments\nUsage:- ./a.out filename\n");
        return 1;
    }
    int n;
    printf("Enter the value of n:");
    scanf("%d", &n);
    struct flock lock;

    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644);
    int new_fd, std_out;

    if (fd == -1)
    {
        perror("File open failed");
        return 1;
    }
    int ret = fork();
    if (ret == -1)
    {
        perror("Fork failed");
        return 1;
    }
    if (ret == 0)
    {
        lock.l_type = F_WRLCK; /*write lock*/
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0; /*lock the whole file*/
        /*child process*/
        fcntl(fd, F_SETLKW, &lock); /*blocking call till lock is acquired*/
        printf("CHILD PROCESS: locked file\n");
        printf("CHILD PROCESS: writing to file %s\n", argv[1]);
        int saved_stdout = dup(1); /*save original stdout*/
        dup2(fd, 1);

        // fibonacci series upto n
        printf("child process : ");
        int term1 = 0, term2 = 1, nextTerm;
        while(nextTerm <= n){
            printf("%d ",term1);
            fflush(stdout);
            nextTerm = term1 + term2;
            term1 = term2;
            term2 = nextTerm;
        }
        dup2(saved_stdout, 1);
        printf("\n");
    
        printf("CHILD PROCESS: unlocked file\n");
        lock.l_type = F_UNLCK;      /*unlock the file*/
        fcntl(fd, F_SETLKW, &lock); /*blocking call till lock is acquired*/
    }
    else if (ret > 0)
    {
        lock.l_type = F_WRLCK; /*write lock*/
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0; /*lock the whole file*/
        /*parent process*/
        fcntl(fd, F_SETLKW, &lock); /*blocking call till lock is acquired*/
        printf("PARENT PROCESS: locked file\n");
        printf("PARENT PROCESS: writing to file %s\n", argv[1]);
        int saved_stdout = dup(1); /*save original stdout*/
        dup2(fd, 1);
        printf("parent process : ");
        for (int i = 2; i <= n; i++)
        {
            int j = 2;
            for (j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    break;
                }
            }
            if (j * j > i)
            {
                printf("%d ", i);
                fflush(stdout);
            }
        }
        printf("\n");

        dup2(saved_stdout, 1);

        printf("PARENT PROCESS: unlocked file\n");
        lock.l_type = F_UNLCK;      /*unlock the file*/
        fcntl(fd, F_SETLKW, &lock); /*blocking call till lock is acquired*/
    }
}