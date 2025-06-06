#include<iostream>
#include<vector>

using namespace std;

// merge sort & quick sort
//sample i/p : 5 2 4 1 3
//sample o/p : 1 2 3 4 5

//void merge(int arr[],int low,int mid,int high){
//int left = low;
//int right = mid+1;
//vector<int> temp;
//while(left <= mid && right <= high){
//	
//	if(arr[left]<=arr[right]){
//		temp.push_back(arr[left]);
//		left++;
//	}else{
//		temp.push_back(arr[right]);
//		right++;
//	}
//}
//while(left<=mid){
//	temp.push_back(arr[left]);
//		left++;
//}
//while(right<=high){
//	temp.push_back(arr[right]);
//		right++;
//}	
//
//for(int i=low;i<=high;i++) arr[i]=temp[i-low];	
//}
//
//void merge_sort(int arr[],int low, int high){
//	if(low>=high) return;
//	int mid = (low+high)/2;
//	merge_sort(arr,low,mid);
//	merge_sort(arr,mid+1,high);
//	merge(arr,low,mid,high);
//	
//}

int point(int arr[],int low,int high){
	int left = low;
	int right = high;
	int pivot = arr[low];
	while(left < right){
		while(arr[left]<=pivot && left <= high-1){
			left++;
		}
	while(arr[right]>pivot && right >= low+1){
		right--;
	}
	
	if(left<right){
		swap(arr[left],arr[right]);
	}
	}
	swap(arr[low],arr[right]);
	return right;
}

void quick_sort(int arr[],int low,int high){
	if(low<high){
		int in = point(arr,low,high);
		quick_sort(arr,low,in-1);
		quick_sort(arr,in+1,high);
	}
}

int main(){

	int arr[] = {5,2,4,1,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,n-1);	
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
