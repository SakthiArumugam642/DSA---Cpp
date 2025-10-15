# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	
	int num = 10;
	for(int i=num;i>=0;i--){
		system("cls");
		for (int n = 0; n < 18; n++) printf("\v");
        for (int t = 0; t < 9; t++) printf("\t");
		printf("Time left : %3d",i);
		fflush(stdout);  
		sleep(1);
	} 
	
	printf("\n");
    for (int t = 0; t < 9; t++) printf("\t");
	printf("   Time up!!!");
	
	
}

