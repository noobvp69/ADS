#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node * next;
};

int isempty(struct node* top){
	return !top;
	}

void push(struct node** op,int data){
	
	struct node* newnode = (struct node*) malloc (sizeof(struct node));
	if (!newnode){
	printf("stack overflow\n");
	return;
	}
	 newnode->data = data;
	 newnode->next = *top;
	 *top = newnode;
	 printf("%d pushed to stack\n", data);
	 }
	 
	

