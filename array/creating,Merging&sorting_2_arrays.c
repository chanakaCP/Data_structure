#include<stdio.h>

int arrSort(int arr[], int n){
	
	int temp;
	for(int k=0;k<n;k++){
		
		for(int m=k+1;m<n;m++){
			
			if( arr[k]>arr[m]){
				
				temp = arr[k];
				arr[k] = arr[m];
				arr[m] = temp;
				
			}
		}
	}
	
	for(int i=0;i<n;i++)	
		printf("%d ",arr[i]);
}

	

int main(){
	
	int n1,n2,n3;
	
	printf("enter array1 size : ");
	scanf("%d",&n1);
	printf("enter array2 size : ");
	scanf("%d",&n2);
	
	printf("\n");
	
	n3=n1+n2;
	int array1[n1],array2[n2],array3[n3];
	
	if(n1>0 && n2>0){
		
		 for(int i=0;i<n1;i++){
		 	printf("enter array1 eliment %d : ",i+1);
		 	scanf("%d",&array1[i]);
		 } 
		 
		 printf("\n");
		 
		  for(int j=0;j<n2;j++){
		 	printf("enter array2 eliment %d : ",j+1);
		 	scanf("%d",&array2[j]);
		 }	
	}
		int k=0;
		for(int i=0;i<n1;i++){
			array3[k]=array1[i];
			k++;		
		}
	
		for(int j=0;j<n2;j++){
			array3[k]=array2[j];
			k++;
		}
		
	printf("\n");
	
	printf("array1 is : ");
	for(int i=0;i<n1;i++)
		printf("%d ",array1[i]);
	
	
	printf("\n");	
		
	printf("array2 is : ");
	for(int i=0;i<n2;i++)
		printf("%d ",array2[i]);
		
				
	printf("\n");
			
	printf("array3 is : ");
	for(int i=0;i<n3;i++)
		printf("%d ",array3[i]);	 	
		  
		  
	printf("\n");
	
	printf("sorted array1 is : ");
		arrSort(array1, n1);
		
	printf("\n");
	
	printf("sorted array2 is : ");
		arrSort(array2, n2);
		
	printf("\n");
	
	printf("sorted array3 is : ");
		arrSort(array3, n3);
	
	return 0;
}
