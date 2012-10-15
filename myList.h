struct MyList {
    struct MyList *next;
    int value;
    int size;
};

struct MyList *emptyList();
struct MyList *add();

bool isEmpty();

void clear();

void printList();
