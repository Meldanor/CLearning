#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "myList.h"

void printInt();

int testIntList();

int main() {
    if (testIntList() == EXIT_FAILURE)
        return EXIT_FAILURE;

    printf("\n\n");
}

int testIntList(void) {
    struct MyList *list = emptyList();
    if (NULL == list)
        return EXIT_FAILURE;

    int i;
    for (i = 1 ; i <= 10; ++i)
       add(list,(int *)i);

    printList(list, printInt);

    int *ptr = (int*)(getAll(list, sizeof(int)));
    printf("Number as one sequentiel array: ");
    for (i = 0; i < 10 ;++i) {
        printf("%d ", ptr[i]);
    }
/*
    int value = (int)getFirst(list);
    printf("First Element: %d\n", value);

    value = (int)getLast(list);
    printf("First Element: %d\n", value);
    
    value = (int)get(list, list->size/2);
    printf("Middle(Index:%d) Element: %d\n", list->size/2, value);

    value = (int)get(list, 1000);

*/
/*
    printf("\n");
    printList(list, printInt);

    int value = (int) removeFirst(list);
    printf("Removed value = %d\n", value);
    printList(list, printInt);
    
    list = addFirst(list, (int *)value);
    printList(list, printInt);
*/

/*    value = (int) removeFirst(list);
    printf("Removed value = %d\n", value);
    printList(list, printInt);

    value = (int)removeLast(list),
    printf("Removed value = %d\n", value);
    printList(list, printInt);

    clear(list); */
    return EXIT_SUCCESS;
}

void printInt(void *elem) {
    printf("%d", (int)elem);
}
