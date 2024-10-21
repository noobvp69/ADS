#include <stdio.h>

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insertion Sort algorithm
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        printf("first element: %d\n",key);
        printf("second element: %d\n",arr[j]);

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; //next element 
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
