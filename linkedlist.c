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

 bool search_list(int val){
	struct test_struct *ptr =head;
	bool flag = false;
	ptr = head;
	while(ptr !=NULL){
		if(ptr->val == val){
			flag = true;
			break;
		}
		ptr = ptr-> addr;
	}
	return flag;
}

bool delete_node(int val){
	struct test_struct *prev=NULL;
	struct test_struct *next=NULL;
}
void main(){
    add_to_list(1,false);
    add_to_list(2,false);
    add_to_list(3,false);
    add_to_list(8,false);
    print_list();
    if(!search_list(2)){
    	printf("\nThe value is not found in the list\n");
    }
    else{
    	printf("The value is FOUND");
    }
}