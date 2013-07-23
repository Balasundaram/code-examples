#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct test_struct
{
    int val;
    struct test_struct *addr;
};

struct test_struct *head = NULL;
struct test_struct *curr = NULL;

struct test_struct* create_list(int val){
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr){
        printf("Cannot create a node");
        return NULL;
    }
    
    ptr->val = val;
    ptr->addr = NULL;
    
    head = curr = ptr;
    return ptr;
}

struct test_struct* add_to_list(int val,bool before_head){
    struct test_struct *ptr = (struct  test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == head){
        return(create_list(val));
    }
    
    if(!before_head) {
        ptr->val = val;
        curr->addr = ptr;
        curr = ptr;
        return ptr;
    }
    else{
        ptr->val = val;
        ptr->addr = head;
        head = ptr;
        return ptr;
    }
}

void print_list(){
    
    struct test_struct *ptr = head;
    printf("\nThe values of the list are\n");
    while(ptr !=NULL){
        printf("\t%d\t",ptr->val);
        ptr = ptr->addr;
    }
    
}

 struct test_struct* search_list(int val,struct test_struct **prev){
	struct test_struct *ptr =head;
	struct test_struct *temp =NULL;
	bool flag = false;
	ptr = head;
	while(ptr !=NULL){
		if(ptr->val == val){
			flag = true;
			break;
		}
		else{
		ptr = ptr->addr;
		}
	}
		if(flag){
			temp = ptr;
		  if(prev)
		     *prev=temp; 
		 return ptr;
		}
		else{
			return NULL;
		}
		
	
	
}

bool delete_node(int val){
	struct test_struct *prev=NULL;
	struct test_struct *del=NULL;

    del=search_list(val,&prev);
    
    if(del != NULL){

    	if(prev != NULL){
    		prev->addr=del->addr;
    		if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->addr;
        }
    		
    	}
    	free(del);
    	del=NULL;
    }
  return false;
}
void main(){
    struct test_struct *prev=NULL;    	
    add_to_list(1,false);
    add_to_list(2,false);
    add_to_list(3,false);
    add_to_list(8,false);
    
    delete_node(3);
    print_list();
    if(search_list(12,&prev) == NULL){
    	printf("\nThe value is not found in the list\n");
    }
    else{
    	printf("The value is FOUND");
    }

}