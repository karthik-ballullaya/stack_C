#include <assert.h>
#include <stdlib.h>
#include "stack.h"

Stack stack_new(uint32_t size) {
  size = (size > 0 && size < MAX_DEPTH) ? size : MAX_DEPTH;
  Stack stack = {size, -1, {0}};
  return stack;
}

uint8_t stack_full(const Stack *stack) {
  assert (stack != NULL);
  return ((stack->top + 1) == stack->size);
}

uint8_t stack_empty(const Stack *stack) {
  assert (stack != NULL);
  return (stack->top == -1);
}

Stack * stack_push(Stack *stack, STACK_DATA_TYPE ele, StackResult *res) {
  assert (stack != NULL);
  if ( (stack->top + 1) < stack->size) {
    stack->data[++stack->top] = ele;
    res->status = STACK_OK;
    res->data = ele;
  } else {
    res->status = STACK_FULL;
  }
  return stack;
}

Stack * stack_pop(Stack *stack, StackResult *res) {
  assert (stack != NULL);
  if (stack->top != -1) {
    res->data = stack->data[stack->top--];
    res->status = STACK_OK;
  } else {
    res->status = STACK_EMPTY;
  }
  return stack;
}

Stack * stack_peek(Stack *stack, StackResult *res) {
  assert (stack != NULL);
  if (stack->top != -1) {
    res->data = stack->data[stack->top];
    res->status = STACK_OK;
  } else {
    res->status = STACK_EMPTY;
  }
  return stack;
}