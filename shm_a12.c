#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// process 1
int main(){
    int shmid = shmget('A',100,IPC_CREAT | 0644);
    char * ptr = shmat(shmid,NULL,0);
    char str[50];
    printf("Enter the string : ");
    scanf("%s",str);
    for(int i = 0 ; i < strlen(str); i++){
        str[i] = toupper(str[i]); 
    }
    strcpy(ptr,str);
    sleep(5);
    printf("reversal of the string is %s\n",ptr);
    shmdt(ptr);
}

// process 2

int main(){
    int shmid = shmget('A',100,0644);
    char * ntr = shmat(shmid,NULL,0);
    char buf[50];
    strcpy(buf,ntr);
    printf("The data from shm is %s\n",ntr);

    // reverse op.
    for(int i = 0 ; j = strlen(buf)-1; i < j; i++, j--){
        char ch = buf[i];
        buf[i] = buf[j];
        buf[j] = ch;
    }
    strcpy(ntr,buf);

    shmdt(ntr);
    shmctl(shmid, IPC_RMID, NULL);
}
