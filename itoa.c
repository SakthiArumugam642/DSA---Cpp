#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// integer to string function implementation

void rev(char * res)
{
	int n = strlen(res);
	for(int i =0,j=n-1;i<j;i++,j--){
		char t = res[i];
		res[i] = res[j];
		res[j] = t;
	}
}
int main(){
	int  n = 1234,k=0;
	char res[20];
	while(n){
		res[k++] = '0'+(n%10);
		n /= 10;
	}
	res[k] = 0;
	rev(res);
	printf("%s",res);
	
}