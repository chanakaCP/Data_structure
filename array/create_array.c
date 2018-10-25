#include<stdio.h>
int main (){
	
	int n,i,val;
	printf(" How many elements do you have :  ");
	scanf("%d",&n);
	int aray[n];
	
	for (int i=0;i<n;i++){
		
		printf(" element - %d :", i+1);
		scanf("%d",&val);
		aray[i]=val;
		}
		printf("Your array is : { " );
		for (int i=0;i<n; i++){
			
			printf("%d, ", aray[i]);
		}
		
		printf("}");
	return 0;
}
