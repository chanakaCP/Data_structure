#include<stdio.h>

int main(){
	
	int n,tem,num;
	
	printf("\nEnter number of elements in array : ");
	scanf("%d",&n);
	
	int array[n];
	
	for (int i=0; i<n; i++){
		printf("Enter element for array[%d] : ",i);
		scanf("%d",&array[i]);
	}	
	do{
	
		rintf("\nEnter location where you wish to delete : ");
		scanf("%d",&tem);
	
		if(tem >=0 && tem < n){
		
			for (int i=tem;tem<n-1;tem++)
				array[tem] = array[tem+1];
		
			printf("\nNew array is : ");
	
			for(int i =0;i<n-1;i++)
				printf("%d,",array[i]);	
		}
		else
			printf("\nUnable to find location !!");
		
			n--;
			printf("\n\nEnter 1 to continue OR enter any number to exit : ");
			scanf("%d",&num);
		
	}while(num !=0);
	
	return 0;
}
