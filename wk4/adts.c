#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

// This function takes an array of integers and its size,
//      and returns the number of integers that occur an odd number of times.
// For example, if given the array [4, 3, 4, 8, 8, 4], the function should
//      return 2, because there are two elements that appear an odd number of
//      times: 3 (occurs 1 time) and 4 (occurs 3 times).
int numOddOccurrences(int arr[], int size) {
    // create a Set s
    Set s = SetNew();

    // for each element in the array
    for (int i = 0; i < size; i++) {
        // if it is not in the set, insert it
        if (!SetContains(s, arr[i])) {
            SetInsert(s, arr[i]);
        } else {
            SetDelete(s, arr[i]);
        }

        // if it is in the set, delete it
    }

    // elements left in the set will have occured an odd number of times
    int res = SetSize(s);

    SetFree(s);

    return res;
}

// This function takes an array of integers and its size,
//     and returns the number of integers that occur exactly once.
// For example,
//     if given the array[4, 3, 4, 8, 7, 4], the function should return 3,
//     because there are three elements that occur exactly once : 3,
//     8 and 7.
int numSingleOccurrences(int arr[], int size) {
    return 0;
}

int main(void) {
    assert(numOddOccurrences((int[]){4, 3, 4, 8, 8, 4}, 6) == 2);
    assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4}, 6) == 3);
    assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4, 3}, 7) == 3);
    assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4, 3, 8}, 8) == 2);
    assert(numOddOccurrences((int[]){4, 3, 4, 8, 7, 4, 3, 8, 7}, 9) == 0);

    assert(numSingleOccurrences((int[]){4, 3, 4, 8, 8, 4}, 6) == 1);
    assert(numSingleOccurrences((int[]){4, 3, 4, 8, 7, 4}, 6) == 3);
    assert(numSingleOccurrences((int[]){4, 3, 4, 8, 7, 4, 3}, 7) == 2);
    return 0;
}
