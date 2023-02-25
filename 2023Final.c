#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseStr(const char* input) {
    size_t len = strlen(input);
    char* rvrsd = (char*)malloc(len + 1); 
    for(int i = 0; i < len; i++) {
        rvrsd[i] = input[len - i - 1];
    }
    rvrsd[len] = '\0';
    return rvrsd;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    char* rvrsd = reverseStr(input);
    printf("Reversed string: %s\n", rvrsd);
    free(rvrsd); //free the memory allocated for the reversed string

    return 0;
}
