#include<stdio.h>

void main(){
  int lower,upper,i,j,flag;
	printf("Prime Number Lister");
	printf("\nEnter the lower limit number");
	scanf("%d",&lower);
    printf("\nEnter the upper limit number");
	scanf("%d",&upper);
	for(i=lower;i<=upper;i++){
		flag=0;
		for(j=2;j<=(i/2);j++){
			if(i%j==0){
				flag=1;				
			}			
		}
		if(flag==0)
			printf("%d\n",i);
	}
}