#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bin(int n ,int left, int right){
	int ans=0;
	while(left <= right){
		int mid = (left+ right)/2;
		if((mid*mid) <= n){
			ans = mid;
			left = mid+1;
		}else right = mid-1;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	int left = 1, right = n;
	printf("%d",bin(n,left,right));
//	printf("%d %d",lc,tc);
}