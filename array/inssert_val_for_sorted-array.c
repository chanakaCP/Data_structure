#include<stdio.h>


int main(){

	int array[10]={12,14,16,18,20,22,24,26,28};
	int val,index;
	
	printf("\nenter value : ");
	scanf("%d",&val);
		
    	if(val < array[0])
			index = 0;
			
		else if(val > array[8])
			index = 9;
			
		else {
		
			for (int i=0;i<9;i++)
		    	if(val>array[i] && array[i+1]>val)
					index = i+1;
		}
			
	if (index != 9){
		
		for(int i = 10; i>index ;i--){
			array[i] = array[i-1]; 
		}
		
	}
		
	array[index]=val;
	printf("index %d",index);
	printf("\narray is : ");
	for (int i=0;i<10;i++){
		
		printf("%d,",array[i]);
	}
		return 0;
}
