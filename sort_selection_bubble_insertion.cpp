#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include <limits>
#include <stdbool.h>
#include <string.h>
#include<time.h>
using namespace std;

// selection sort_bubble sort_insertion sort

void selection_sort(int arr[],int n){
	for(int i=0;i<=n-2;i++){
		int mini = i;
		for(int j=i;j<=n-1;j++){
			if(arr[j]<arr[mini]){
				mini = j;	
			}	
		}
		    int temp = arr[mini];
		    arr[mini] = arr[i];
			arr[i]=temp;
	}	
}

void bubble_sort(int arr[],int n){
	
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j+1];
				arr[j+1]=arr[j];
				arr[j] = temp;
			}
		}
	}
	
}

void insertion_sort(int arr[],int n){
	
	for(int i=0;i<n;i++){
		for(int j =i;j>=0;j--){
			while(j>0 && arr[j]<arr[j-1]){
				int temp = arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
	
}

int main(){
	
	int arr[]={1,5,3,6,2,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}	
}