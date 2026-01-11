#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include <limits>
#include <stdbool.h>
#include <string.h>
#include<time.h>
using namespace std;
// Duplicates values in array

int MaxArraySum(vector<int> nums,int n,int k){
	int ov_max=0,cur_sum=0,l=0;
	if(n<k) return 0;
	unordered_set<int> S;
	
	for(int r=0;r<n;r++){
		while(S.count(nums[r])||S.size()>=k){
			cur_sum -=nums[l];
			S.erase(nums[l]);
			l++; 
		}
		cur_sum +=nums[r];
		S.insert(nums[r]);
		
		if(S.size()==k) ov_max=max(ov_max,cur_sum);
	}
	return ov_max;
}


int main(){
	
	vector<int> nums={1,5,4,2,9,9,9};
	int n= nums.size();
	int k=3;
	int sum = MaxArraySum(nums,n,k);
	printf("Max sum of Subarray is %d ",sum);
	
}


