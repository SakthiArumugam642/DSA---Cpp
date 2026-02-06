#include <stdio.h>

int len(char * s){
    int i = 0;
    while(s[i]){
        i++;
    }
    return i;
}
void rev(char * str, int st , int en){
    for(int i = st , j = en-1; i < j ; i++, j--){
         char temp = str[i];
         str[i] = str[j];
         str[j] = temp;
    }
}
int main()
{
    char str[50];
    fgets(str,49,stdin);
    printf("before rev : %s\n",str);
    int n = len(str);
    rev(str,0,n);
    printf("after rev : %s\n",str);
    return 0;
}