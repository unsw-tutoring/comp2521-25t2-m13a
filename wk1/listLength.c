#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

// return the number of nodes in a linked list, given its head
int listLength(struct node *list);

// use a while loop
int listLength(struct node *list) {
    int length = 0;
    while (list != NULL) {
        length++;
        list = list->next;
    }
    return length;
}

// use a for loop
int listLength(struct node *list) {
    // TODO
    return 0;
}
