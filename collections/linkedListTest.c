#include "linkedList.c"
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    struct LinkedList *list = newLinkedList();
    long i;
    long e;
    puts("\n-----------------------");
    puts("--- LinkedList Test ---");
    puts("-----------------------\n");
    
    puts("--- Adding Elements ---");
    for (i = 0 ; i <= 5 ; ++i) {
        e = (1L << i);
        add(list, (void *)e);
    }
        
    printf("Size: %d\n\n", list->size);
    
    puts("--- Printing Elements ---");
    struct Node *node = list->first;
    while (node != NULL) {
        printf("Value: %ld\n", (long)node->value);
        node = node->next;
    }

    puts("");

    puts("--- Removing 1 Element(In List) ---");
    bool b = (bool)removeElement(list, 2);
    printf("Removed: %s\n\n", b ? "true" : "false");
    
    puts("--- Printing Elements ---");
    node = list->first;
    while (node != NULL) {
        printf("Value: %ld\n", (long)node->value);
        node = node->next;
    }
    puts("");
    
    puts("--- Removing 1 Element(Not In List) ---");
    b = (bool)removeElement(list, 3);
    printf("Removed: %s\n\n", b ? "true" : "false");
    
    puts("--- Printing Elements ---");
    node = list->first;
    while (node != NULL) {
        printf("Value: %ld\n", (long)node->value);
        node = node->next;
    }
    puts("");

    puts("--- Clear List ---");
    b = clearList(list);
    printf("Cleared: %s\n", b ? "true" : "false");
    printf("IsEmpty: %s\n\n", isEmpty(list) ? "true" : "false");

    puts("--- Adding Elements ---");
    for (i = 0 ; i <= 10 ; ++i) {
        e = (1L << i);
        add(list, (void *)e);
    }
    printf("HasElements: %s\n", !isEmpty(list) ? "true" : "false");
    puts("");
    
    puts("--- To Array ---");
    void **array = toArray(list);
    printf("ToArray: %s\n\n", (array != NULL) ? "true" : "false");
    if (array != NULL) {
        puts("--- Printing Elements ---");
        for (i = 0 ; i < list->size; ++i)
            printf("Value: %ld\n", (long)array[i]);
        puts("");
    }


    puts("--- Remove Element at 0 ---");
    void *removedValue = removeAt(list, 0);
    if (removedValue != NULL)
        printf("Value: %ld\n", (long)removedValue);

    puts("--- Print Elements ---");
    array = toArray(list);
    printf("ToArray: %s\n\n", (array != NULL) ? "true" : "false");
    if (array != NULL) {
        puts("--- Printing Elements ---");
        for (i = 0 ; i < list->size; ++i)
            printf("Value: %ld\n", (long)array[i]);
        puts("");
    }

}


