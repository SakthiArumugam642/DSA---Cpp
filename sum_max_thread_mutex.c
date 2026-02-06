#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int global_max, global_sum;
int s,e;
pthread_mutex_t lock;
struct st
{
    int st;
    int en;
    int *arr;
};
void *thread(void *arg)
{
    pthread_mutex_lock(&lock);
    s = ((struct st *)arg)->st;
    e = ((struct st *)arg)->en;
        printf("%d %d\n", s, e);

    struct st *var = (struct st *)arg;
   

    unsigned long int ans = 1;
    int sum = 0;

    for (int i = s; i <= e; i++)
    {
        sum += var->arr[i];
        if (global_max < var->arr[i])
            global_max = var->arr[i];
    }
    global_sum += sum;
    sum = 0;
    pthread_mutex_unlock(&lock);
    return (void *)ans;
}
int main()
{
    pthread_t tid[5];
    int n = 0;

    printf("Enter the number :");
    scanf("%d", &n);
    if (n < 500)
    {
        printf("Invalid number\n");
        return 0;
    }
    struct st var;
    var.arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        var.arr[i] = i + 1;
    }
    for (int i = 0; i < 5; i++)
    {
        var.st = i * (n / 5);
        var.en = ((i + 1) * (n / 5)) - 1;
        pthread_create(&tid[i], NULL, thread, &var);
        sleep(1);
    }

    unsigned long int ptr;
    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], (void **)&ptr);
    }
    printf("The global max is %d\nThe global sum is %d\n", global_max, global_sum);
}
