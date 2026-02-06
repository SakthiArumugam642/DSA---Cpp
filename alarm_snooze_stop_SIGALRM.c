#include <time.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int flag = 0; 

void handler(int signum){
    flag = 1;    
}


int main(int argc, char * argv[]){
    if(argc < 2 || argc > 3){
        printf("Error: Invalid arguments counts\nUsage : ./a.out Date(optional) Time\n");
        return 0;
    }
    if(argc == 3 && (argv[1][2] != '/' || argv[1][5] != '/') && (argv[2][2] != ':' || argv[2][5] != ':')){
        printf("Error1: Date format should be mm/dd/yy\nError: Time format should be hh/mm/ss\n");
        return 0;
    }
    if(argc == 2 && (argv[1][2] != ':' || argv[1][5] != ':')){
        printf("Error2: Date format should be mm/dd/yy\nError: Time format should be hh/mm/ss\n");
        return 0;
    }

    signal(SIGALRM,handler);
    unsigned long int c_t = time(NULL);
    struct tm g_t;
    if(argc == 2){
        struct tm * ct_format = localtime(&c_t);
        g_t.tm_year = ct_format->tm_year;
        g_t.tm_mday = ct_format->tm_mday;
        g_t.tm_mon = ct_format->tm_mon;
        strptime(argv[1],"%T",&g_t);
    }
    else if(argc == 3){
        strptime(argv[1],"%d/%m/%y",&g_t);
        strptime(argv[2],"%H:%M:%S",&g_t);
    }
    unsigned long int g_t_sec = mktime(&g_t);
    // printf("%d %d\n",g_t_sec,c_t);
    
    unsigned long int sec = g_t_sec -c_t;
        // printf("%d\n",sec);
    if(sec < 0){
        printf("invalid time given\n");
        return 0;
    }
    alarm(sec);
    pause();
    while(1){
        if(flag){
            flag = 0;
            printf("Alarm occurred...!!!\n");
            int opt;
            while(1){
                printf("Enter the opt\n1.Snooze\n2.Stop\n");
                scanf("%d",&opt);
                if(opt == 1){
                    int new_sec;
                    printf("Enter the snooze min : ");
                    scanf("%d",&new_sec);
                    if(new_sec <= 0){
                        printf("Invalid sec given\n");
                        continue;
                    }
                    alarm(new_sec*60);
                    pause();
                }else if(opt == 2){
                    printf("Alarm Stopped\n");
                    return 0;
                }else{
                    printf("invalid option\nTry Again\n");
                    continue;
                }
            }
        }
    }
}