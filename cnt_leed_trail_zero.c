#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int i = 0,lc=0,tc=0;
	while(i <= 31){
		if((n & 1) == 0) tc++;
		else break;
		n >>= 1; i++;
	}
	i = 31;
	while(i >=0){
		if((((unsigned)n>>i) & 1) == 0) lc++;
		else break;
		i--;
	}
	
	printf("%d %d",lc,tc);
}