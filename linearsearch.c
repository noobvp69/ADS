





#include <stdio.h>

int main() {

    int i,j, r = -1, size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    
    
    for ( i = 0; i<size; i++){
    	printf("Enter the element no %d:",i);
    	scanf("%d",&arr[i]);}
    	
    	
    	
    int item;
    printf("Enter the element to search: ");
    scanf("\n%d",&item);
    
    int count = 0;

     for (j = 0; j < size; j++) {
        if (arr[j] == item) {
               
            r = j;
            break;}}
    for (j = 0; j < size; j++) {
        if (arr[j] == item) {
            count++;   
            
            
              
             
        }
    }

    if (r != -1) {
        printf("Element first found at index %d and its occurence: %d", r,count);

    } else {
        printf("Element not found\n");
    }

    return 0;
}

