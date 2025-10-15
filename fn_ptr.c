#include <stdio.h>
 // callback function
// simple calculator

typedef int (*fptr)(int,int);

int add(int a,int b){
    return a+b;
}
int sub(int a,int b){ return a-b; }
int mul(int a,int b){ return a*b; }
int div(int a,int b){ return a/b; }

int opr(int a,int b,fptr fp){
    return fp(a,b);
}
fptr fn(char c){
    if(c == '-') return sub;
    else return add;
}
int get_fn(int a, int b, char c){
    fptr fp= fn(c);
    return opr(a,b,fp);
}
int main()
{
    // printf("%d ",f1[i](4,3));    
    printf("%d\n",get_fn(4,3,'+'));
}