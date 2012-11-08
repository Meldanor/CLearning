#include "linkedList.c"
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    struct LinkedList *list = create();
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
    bool b = removeElement(list, 2);
    printf("Removed: %s\n\n", b ? "true" : "false");
    
    puts("--- Printing Elements ---");
    node = list->first;
    while (node != NULL) {
        printf("Value: %ld\n", (long)node->value);
        node = node->next;
    }
    puts("");
    
    puts("--- Removing 1 Element(Not In List) ---");
    b = removeElement(list, 3);
    printf("Removed: %s\n\n", b ? "true" : "false");
    
    puts("--- Printing Elements ---");
    node = list->first;
    while (node != NULL) {
        printf("Value: %ld\n", (long)node->value);
        node = node->next;
    }
    puts("");
}

