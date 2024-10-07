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

void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element no %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int item) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == item) {
            return mid;
        }
        if (arr[mid] < item) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int size;
    
    printf("Enter the size: ");
    scanf("%d", &size);
    
    int arr[size];
    
    inputArray(arr, size);
    
    printf("Unsorted array: ");
    printArray(arr, size);
    
    bubbleSort(arr, size);
    
    printf("Sorted array: ");
    printArray(arr, size);
    
    int item;
    printf("Enter the element to find: ");
    scanf("%d", &item);
    
    int result = binarySearch(arr, size, item);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    
    return 0;
}

