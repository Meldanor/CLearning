/*
 * Copyright (C) 2012 Kilian Gärtner
 */

#include <stdbool.h>

struct Node {
    void *value;
    struct Node *next;
    struct Node *prev;
};

struct LinkedList {
    struct Node *first;
    struct Node *last;
    int size;
};

struct LinkedList *create(void);

bool isEmpty(struct LinkedList *list);

bool add(struct LinkedList *list, void *value);

void *removeFirst(struct LinkedList *list);

void *removeLast(struct LinkedList *list);

bool removeElement(struct LinkedList *list, void *element);

bool clearList(struct LinkedList *list);

void **toArray(struct LinkedList *list);
