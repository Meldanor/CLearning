#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "myList.h"

int main(void) {
    printf("Create empty list...\n");
    struct MyList *list = emptyList();
    if (NULL == list)
        return EXIT_FAILURE;   

    printf("Size: %d!\n", list->size);
    printf("Add 1...\n");
    list = add(list, 1); 
    printf("Size: %d!\n", list->size);
    printf("Add 2...\n");
    list = add(list, 2); 
    printf("Size: %d!\n", list->size);
    printf("Print list...\n");
    printList(list);
    
    printf("Add elements from 2 until 10 to list...\n");
    int i;
    for (i = 3 ; i <= 10; ++i)
        add(list,i);

    printf("Print list...\n");
    printList(list);
    return EXIT_SUCCESS;
}

struct MyList *emptyList(void) {
    struct MyList *list;
    list = malloc(sizeof(struct MyList));
    if (NULL == list) {
        printf("Not enough memory for an empty list!");
        return NULL;
    }
    list->next = NULL;
    list->size = 0;
    list->value = 0;

    return list;
}

struct MyList *add(struct MyList *list, int element) {
    if (NULL == list) {
        printf("List is null!");
        return NULL;
    }
    
    if(isEmpty(list)) {
        list->value = element;
        list->size = 1;
    }
    else {
        struct MyList *cur = list;
        while (cur->next != NULL)
            cur = cur->next;
        struct MyList *next = emptyList();
        if (NULL == next) {
            printf("Not enough memory for new element!");
            return NULL;
        }
        next->value = element;
        next->size = list->size - 1;

        cur->next = next;
        list->size++;
    }
    return list;
}

bool isEmpty(struct MyList *list) {
    return NULL == list || (NULL != list && list->size == 0);
}

void printList(struct MyList *list) {
    if (NULL == list) {
        printf("List is null!\n");
        return;
    }
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return;
    }

    printf("MyList={Size:%d;Values=[", list->size);
    struct MyList *cur = list;
    while (cur->next != NULL ) {
        printf("%d,",cur->value);
        cur = cur->next;
    }
    printf("%d]}\n",cur->value);
}
