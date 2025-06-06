#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	int matrix[][3]={{1,2,3},{4,5,6},{7,8,9}};
	int r = 3;
	 for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                if(i==0){
                    matrix[i][j]=matrix[j][r-1];
                }
               if(i==r-1){
                    matrix[i][j]=matrix[j][0];
                }
                matrix[i][j] = matrix[j][i];
                
            }
        }
        for(int i =0;i<r;i++){
        	for(int j=0;j<r;j++) cout<<matrix[i][j]<<" ";
		}
}