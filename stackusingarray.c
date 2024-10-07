#include<stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isfull(){
	if(top == MAXSIZE-1 ){
		return 1;}
		else{
		return 0;}
}

int isempty(){

	if(top == -1){
	return 1;}
	else{
	return 0;}


}

int push(int data){
	if( !isfull() ){
	
	top = top + 1;
	stack[top]=data;
	}
	else{
	printf("Overflow condition exist.");
	}
	}

int pop(){
int data;
if (!isempty()){
	data = stack[top];
	top = top - 1;
	return data;
	}else{
	printf("Could not retrieve data, Stack is empty.");
	}
	}
	
int peek(){
	return stack[top];
}

int main(){

	int i;
	push(10);
	push(62);
	push(123);
	push(15);
	push(100);
	
	printf("Stack elements:\n");
	printf("[");
	
	for(i=0;i<8;i++){
		printf(" %d ",stack[i]);
		if ( i < top ){
		printf(",");
		}}
	printf("]");
	
	 printf("\nElement at top of the stack: %d\n" ,peek());
	 
	 
	return 0;
	}

