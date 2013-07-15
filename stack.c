#include <stdio.h>

#define STACK_MAX_SIZE 10
int top = -1 ,stack[STACK_MAX_SIZE];
int push(int);
int pop();
int main(){
 int choice,input_element,i;
 while(1){
 printf("Enter u r option");
 scanf("%d",&choice);

 switch(choice){
    case 1:
      //Stack push
      printf("Enter the element to be pushed\n");
      scanf("%d",&input_element);
      if(!push(input_element)){
         printf("The element has been pushed to stack\n");
	for(i=0;i<=top;i++)
          printf("%d",stack[i]);
      }
      else
      {
         printf("There are some issues in pushing the element to stack");
      }
      break;
    case 2:
      printf("The element %d has been popped out of stack\n",pop());
      printf("The remaining elements of stack are\n");
      for(i=0;i<=top;i++){
          printf("%d",stack[i]);
      }

      break;
    case 3:
      //status of stack
      break;
  }
 }
  return 0;
}


int push(int element){
   stack[++top]=element;
   return 0;
}

int pop(){
   return stack[top--];
}
