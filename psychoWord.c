#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *mix();
void swap();

int main(int argsc, char *args[]) {

    char *goal = malloc(sizeof(char) * 1024);
    if (NULL == goal) {
        printf("Not enough memory!");    
        return EXIT_FAILURE;
    }
    
    int i;
    char *result = NULL;
    int temp;
    for (i = 1 ; i < argsc; ++i) {
        result = mix(args[i]);
        strcat(goal, " ");
        strcat(goal, result);
    }

    if (NULL == result) {
        return EXIT_FAILURE;
    }
    printf("%s\n",goal);

    return EXIT_SUCCESS;
}

char *mix(char *string) {
    int length = strlen(string);
    char *result = malloc(sizeof(char) *length);
    if (NULL == result) {
        printf("Not enough memory!");
        return NULL;
    }
    strcpy(result, string);

    int i;
    for(i = 1; i < length - 2 ; i += 2) {            
        swap(result, i , i +1);
    }

    return result;
}

void swap(char *array, int i, int j) {
    char temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
