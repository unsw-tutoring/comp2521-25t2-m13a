#include "Set.h"

struct set {
    int *arr;
    int capacity;
    int nelems;
};

// Creates a new empty set
Set SetNew(void) {
    Set s = malloc(sizeof(struct set));
    s->arr = malloc(8 * sizeof(int));
    s->capacity = 8;
    s->nelems = 0;

    return s;
}

// Frees memory allocated to the set
void SetFree(Set s) {
    free(s->arr);
    free(s);
}

// Inserts an element into the set
void SetInsert(Set s, int elem) {
    if (SetContains(s, elem)) return;

    if (s->nelems >= s->capacity) {
        s->capacity *= 2;
        s->arr = realloc(s->arr, s->capacity * sizeof(int));
    }

    s->arr[s->nelems++] = elem;
}

// Deletes an element from the set
void SetDelete(Set s, int elem) {
    bool shift = false;
    for (int i = 0; i < s->nelems; i++) {
        if (s->arr[i] == elem) {
            shift = true;
        }

        if (shift && i < s->nelems - 1) {
            s->arr[i] = s->arr[i + 1];
        }
    }

    if (shift) s->nelems--;
}

// Returns true if the given element is in the set, and false otherwise
bool SetContains(Set s, int elem) {
    for (int i = 0; i < s->nelems; i++) {
        if (s->arr[i] == elem) return true;
    }
    return false;
}

// Returns the number of elements in the set
int SetSize(Set s) {
    return s->nelems;
}
