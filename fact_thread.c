#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct st{
    int st;
    int en;
};
void * thread(void * arg){
        struct st * var = (struct st *)arg;
       unsigned long int ans = 1;
        for(int i = var->st ; i <= var->en; i++) ans *= i;
        return (void *)ans;
}
int main(){
    pthread_t tid[3];
    int n = 0;

    printf("Enter the nummber :");
    scanf("%d",&n);
    struct st var[3];
    var[0].st = 1;
    var[0].en = n/3;
    var[1].st = var[0].en + 1;
    var[1].en = var[0].en + n/3;
    var[2].st = var[1].en + 1;
    var[2].en = n;
    for(int i = 0 ; i < 3; i++){
        pthread_create(&tid[i],NULL,thread,&var[i]);
    }
    unsigned long int ptr, res = 1;
    for(int i = 0 ; i < 3; i++){
        pthread_join(tid[i],(void**)&ptr);
        res *= ptr;
    }
    printf("Factorial of %d is %lu\n",n,res);
}
