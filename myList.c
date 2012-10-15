#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "myList.h"

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

struct MyList *add(struct MyList *list, void *element) {
    if (NULL == list) {
        printf("List is null!\n");
        return NULL;
    }
    if(isEmpty(list)) {
        list->value = element;
        list->size = 1;
    }
    else {
        struct MyList *next = emptyList();
        if (NULL == next) {
            printf("Not enough memory for new element!\n");
            return NULL;
        }
        next->value = element;
        next->size = 1;
        struct MyList *cur = list;
        while (cur->next != NULL) {
            cur->size++;
            cur = cur->next;
        }
        cur->size++;
        cur->next = next;
    }
    return list;
}

struct MyList *addFirst(struct MyList *list, void *element) {
    if (NULL == list) {
        printf("List is null!\n");
        return NULL;
    }
    if(isEmpty(list)) {
        list->value = element;
        list->size = 1;
        return list;
    }
    else {
        struct MyList *first = emptyList();
        if (NULL == first) {
            printf("Not enough memory for new element!\n");
            return NULL;
        }
        first->value = element;
        first->size = list->size + 1;
        first->next = list;
        // *list = *first; -- TODO: Some error here :/
        return first;
    }
}

bool isEmpty(struct MyList *list) {
    return NULL == list || (NULL != list && list->size == 0);
}

void printList(struct MyList *list, void (*printElem) (void *elem)) {
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
        (*printElem)(cur->value);
        printf(",");
        cur = cur->next;
    }
    (*printElem)(cur->value);
    printf("]}\n");
}

void *removeFirst(struct MyList *list) {
    if (list == NULL) {
        printf("List is null!\n");
        return NULL;
    }
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return NULL;
    }
    void *value = list->value;
    *list = *(list->next);
    return value;
}

void *removeLast(struct MyList *list) {
    if (list == NULL) {
        printf("List is null!\n");
        return NULL;
    }
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return NULL;
    }
    struct MyList *cur = list;
    struct MyList *next = cur->next;

    while (next->next != NULL) {
        cur->size--;
        cur = next;
        next = cur->next;
    }
    
    void *value = next->value;
    cur->next = NULL;
    free(next);

    return value;
}

void clear(struct MyList *list) {
    if (list == NULL) {
        printf("List is null!\n");  
        return;
    }
    if (isEmpty(list)) {
        free(list);
        return;
    }
    struct MyList *start = list;
    struct MyList *next1, *next2;
    next1 = start->next;
    while (next1 != NULL) {
        next2 = start->next->next;
        start->next = next2;
        free(next1);
        next1 = next2;
    }
    free(start->next);
    free(start);
    start = NULL;
    printf("Cleared list!\n");
}

void *getFirst(struct MyList *list) {
    if (list == NULL) {
        printf("List is null!\n");  
        return NULL;
    }
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return NULL;
    }
    return list->value;
}

void *getLast(struct MyList *list) {
    if (list == NULL) {
        printf("List is null!\n");  
        return NULL;
    }
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return NULL;
    }

    struct MyList *cur = list;
    while(cur->next != NULL) 
        cur = cur->next;

    return cur->value;
}

void *get(struct MyList *list, int index) {
    if (list == NULL) {
        printf("List is null!\n");  
        return NULL;
    }
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return NULL;
    }
    if (index >= list->size) {
        printf("Index out of range! Index: %d Size: %d\n", index, list->size);
        return NULL;
    }

    struct MyList *cur = list;
    while (index > 0) {
        cur = cur->next;
        --index;
    }

    return cur->value;
}

void *getAll(struct MyList *list, size_t elementSize) {
        if (list == NULL) {
        printf("List is null!\n");  
        return NULL;
    }
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return NULL;
    }

    void **elements = malloc(elementSize * list->size);
    if (NULL == elements) {
        printf("Not enough memory!\n");
        return NULL;
    }
    
    struct MyList *cur = list;
    int i;
    for (i = 0; i < list->size ; ++i) {
        elements[i] = cur->value;
        cur = cur->next;
    }
    
    return elements;
}
