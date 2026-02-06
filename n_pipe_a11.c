#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf("Error : Invalid arguments\nUsage : ./a.out <cmd1> '|' <cmd2> ...\n");
        return 0;
    }
    if ((strcmp(argv[argc - 1], "|") == 0) || (strcmp(argv[1], "|") == 0)) {
        printf("Error : Invalid arguments\n");
        return 0;
    }

    int in[argc], k = 0;
    in[k++] = 1;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0) {
            argv[i] = NULL;
            in[k++] = i + 1;
        }
    }

    int fd[2];
    for (int i = 0; i < k; i++) {
        if (i != k - 1) {   // not last command
            if (pipe(fd) == -1) {
                perror("pipe");
                return -1;
            }
        }

        pid_t pid = fork();
        if (pid == 0) {
            // child
            if (i != k - 1) {
                close(fd[0]);
                dup2(fd[1], 1);
            }
            execvp(argv[in[i]], argv + in[i]);
            perror("execvp");
            _exit(1);
        } else {
            // parent
            if (i != k - 1) {
                close(fd[1]);
                dup2(fd[0], 0);  // parent’s stdin becomes pipe input
            }
        }
    }

    for (int i = 0; i < k; i++) {
        wait(NULL);
    }
    return 0;
}