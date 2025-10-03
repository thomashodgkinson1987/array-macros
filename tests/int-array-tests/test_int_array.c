#include <assert.h>
#include <stdio.h>

#include "int_array.h"

int main(void) {
    printf("--- Running Integer Array Tests ---\n");

    IntArray* q = int_array_create(4);
    assert(q != NULL);

    int_array_free(q);

    printf("--- Integer Array Tests Passed ---\n");

    return 0;
}
