/* This code is based on Chapter 4 of the book "Algorithms in C" by Robert Sedgewick. */

#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

void STACKinit(int Stack_maxN, Stack *Stack_ptr) {
  Stack_ptr->s = malloc(Stack_maxN * sizeof(Item));
  Stack_ptr->N = 0;
}

int STACKempty(Stack *Stack_ptr) {
  return Stack_ptr->N == 0;
}

void STACKpush(Item item, Stack *Stack_ptr) {
  Stack_ptr->s[Stack_ptr->N++] = item;
}

Item STACKpop(Stack *Stack_ptr) {
  return Stack_ptr->s[--Stack_ptr->N];
}
