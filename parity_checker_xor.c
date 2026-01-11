#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//0->01010
//0->01000

int main(){
	int n;
	scanf("%d",&n);
	int rs = 0;
	while(n){
		rs ^= (n & 1);
		n >>= 1;
	}
	rs ? printf("Odd\n") :  printf("Even");
}