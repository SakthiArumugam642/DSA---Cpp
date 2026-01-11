// Pascal triangle

// 1. print Nth row and Nth colomn elements 

#include <iostream>
using namespace std;

void pasc_Nth_Elem(int row,int col){

int ans=1;
for(int i = 1;i<col;i++){
	ans = ans*(row-i)/i;

}

printf("%d ",ans);
}

void pasc_Nth_row(int row){
	int ans=1;
			cout<<1<<" ";
	     for(int i=1;i<row;i++){
	     	ans = ans*(row-i)/i;
	     	cout<<ans<<" ";
		 }
}

int main(){
	pasc_Nth_row(6);
//	pasc_Nth_Elem(4,3); // 5 Th row and 4 th coloum element i.e, 4
	
}




