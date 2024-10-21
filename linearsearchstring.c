#include <stdio.h>
#include <string.h>

int main() {
	
    char str[100];
    char target;
    int index = -1; 
    int count = 0;
    
    printf("Enter a string: ");
    scanf("%99s",str);
    
    printf("Enter a character to search for: ");
    scanf(" %c", &target);
    
   
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == target) {
            index = i;
            break; 
        }
    }
    for (int i = 0; i < length; i++) {
        if (str[i] == target) {
            count++; 
        }
    }
    
    if (index != -1) {
        printf("Character '%c' found at index %d and its occurences: %d" , target, index, count);
    } else {
        printf("Character '%c' not found in the string.\n", target);
    }
    
    return 0;
}

