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

int linearSearch(int arr[], int size, int item) {
    int r = -1, count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            if (r == -1) {
                r = i; // First occurrence
            }
            count++; // Counting occurrences
        }
    }
    if (r != -1) {
        printf("Element first found at index %d and its occurrence: %d\n", r, count);
    } else {
        printf("Element not found\n");
    }
    return r;
}

int binarySearch(int arr[], int size, int item) {
    int left = 0, right = size - 1, mid, r = -1;

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
    return r;
}

int main() {
    int size, choice, item, searchType;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++) {
        printf("Enter the element no %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &item);

    printf("Choose search type: 1 for Linear Search, 2 for Binary Search: ");
    scanf("%d", &searchType);

    if (searchType == 1) {
        linearSearch(arr, size, item);
    } else if (searchType == 2) {
        bubbleSort(arr, size); // Sorting before binary search
        printf("Array sorted for Binary Search\n");
        binarySearch(arr, size, item);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}

