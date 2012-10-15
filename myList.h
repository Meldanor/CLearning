struct MyList {
    struct MyList *next;
    void *value;
    int size;
};

struct MyList *emptyList(void);
struct MyList *add(struct MyList *list, void *elem);

bool isEmpty(struct MyList *list);

void clear(struct MyList *list);

void printList(struct MyList *list, void (*printElem) (void *elem));
