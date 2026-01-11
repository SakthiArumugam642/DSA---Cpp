#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char * argv[]){
    if(argc > 2){
        printf("Error : Too many arguments\n");
        return 0;
    }
    if(argc == 1){
        printf("Error : File not specified\n");
        return 0;
    }
    int opt;
    printf("Choose an option:\n1.Dup\n2.Dup2\n");
    opt = scanf("%d", &opt);
    if(opt == 1){
        int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
        int std_out = dup(1);
        close(1);
        if(fd == -1){
            perror("Error opening file");
            return 1;
        }
        int new_fd = dup(fd);
        if(new_fd == -1){
            perror("Error duplicating file descriptor");
            return 1;
        }
        printf("Print this message into file\n");
        close(new_fd);
        dup(std_out);
        printf("Print this message into STDOUT\n");
    }
    else if(opt == 2){
        int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
        int std_out = dup2(fd, 1);
        // close(1);
        if(fd == -1){
            perror("Error opening file");
            return 1;
        }
        int new_fd = dup2(fd,1);
        if(new_fd == -1){
            perror("Error duplicating file descriptor");
            return 1;
        }
        printf("Print this message into file\n");
        close(new_fd);
        dup2(std_out,1);
        printf("Print this message into STDOUT\n");
    }
    else{
        printf("Invalid option\n");
    }
}