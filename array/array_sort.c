#include<stdio.h>
#define MAX 10

int main(){
	int array[MAX],tem;
	for(int i=0;i<MAX;i++){
		printf("Enter element %d: ",i+1);
		scanf("%d",&array[i]);
	}
	
	for(int i=0;i<MAX;i++){
		for(int j=i+1;j<MAX;j++){
			if(array[j]>array[i]){
				tem = array[i];
				array[i] = array[j];
				array[j] = tem;
			}
		}
	}	
	
	printf("\nSorted array is ----- \n");
	for(int i=0;i<MAX;i++)
		printf("%d ",array[i]);
	
}
