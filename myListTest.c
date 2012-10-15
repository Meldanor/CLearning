#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "myList.h"

void printString();

void printInt();

int testIntList();
int testStringList();

int main() {
    if (testIntList() == EXIT_FAILURE)
        return EXIT_FAILURE;

    printf("\n\n");
    if (testStringList() == EXIT_FAILURE)
        return EXIT_FAILURE;
}

int testIntList(void) {
    printf("Create empty list... ");
    struct MyList *list = emptyList();
    if (NULL == list)
        return EXIT_FAILURE;   

    printf("Size: %d!\n", list->size);
    printf("Add 1... ");
    list = add(list, (int *)1); 
    printf("Size: %d!\n", list->size);
    printf("Add 2... ");
    list = add(list, (int *)2); 
    printf("Size: %d!\n", list->size);
    printf("Print list...");
    printList(list, printInt);
    
    printf("Add elements from 2 until 10 to list...\n");
    int i;
    for (i = 3 ; i <= 10; ++i)
        add(list,(int *)i);

    printf("Print list...");
    printList(list, printInt);

    printf("Print all sub lists lists\n");
    
    struct MyList *cur = list;
    while (cur != NULL) {
        printf("\t");
        printList(cur, printInt);
        cur = cur->next;
    }

    printf("Clear list...\n");
    clear(list);
    return EXIT_SUCCESS;
}

void printInt(void *elem) {
    printf("%d", (int)elem);
}

int testStringList() {
    printf("Create empty list... ");
    struct MyList *list = emptyList();
    if (NULL == list)
        return EXIT_FAILURE;   

    printf("Size: %d!\n", list->size);
    printf("Add Hallo... ");
    list = add(list, (char *)("Hallo")); 
    printf("Size: %d!\n", list->size);
    printf("Add 2... ");
    list = add(list, (char *)("Kilian")); 
    printf("Size: %d!\n", list->size);
    printf("Print list...");
    printList(list, printString);
    
    printf("Add elements Kilian and Hallo to list...\n");
    int i;
    for (i = 3 ; i <= 10; ++i) {
        if (i % 2 == 0)
            add(list, (char *)("Kilian")); 
        else
            add(list, (char *)("Hallo")); 
    }

    printf("Print list...");
    printList(list, printString);

    printf("Print all sub lists lists\n");
    
    struct MyList *cur = list;
    while (cur != NULL) {
        printf("\t");
        printList(cur, printString);
        cur = cur->next;
    }

    printf("Clear list...\n");
    clear(list);
    return EXIT_SUCCESS;
}

void printString(void *elem) {
    printf("%s", (char *)elem);
}
