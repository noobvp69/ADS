#include <stdio.h>


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void inputprintarray(){
int i,j,size;
printf("Enter the size: ");
scanf("%d",&size);
int arr[size];
for(i=0;i<size-1;i++){
	printf("enter element no %d:",i);
	scanf("%d",&arr[i]);
	}

for(j=0;j<size-1;j++)

	printf("%d ",arr[j]);
	}

int main() {


 	 int arr[] = {1, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
   
  int item = 8;
    int r = -1;  
  int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == item) {
            r = mid;  
            break;    
        }
        if (arr[mid] < item) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (r != -1) {
        printf("Element found at index %d\n", r);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

