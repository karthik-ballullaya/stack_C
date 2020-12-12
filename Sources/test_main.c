#include <assert.h>
#include "stack.h"
#include "appconstant.h"

void test_stack_new() {
  Stack stack = stack_new(10);
  assert((stack.size == 10) && (stack.top == -1));
  stack = stack_new(0);
  assert(stack.size == MAX_DEPTH);
  stack_new(MAX_DEPTH + 1);
  assert(stack.size == MAX_DEPTH);
}

void test_stack_empty() {
  Stack stack = stack_new(1);
  assert(stack_empty(&stack) == 1);
  stack.top = 0;
  assert(stack_empty(&stack) == 0);
}

void test_stack_full() {
  Stack stack = stack_new(1);
  assert(stack_full(&stack) == 0);
  stack.top = 0;
  assert(stack_full(&stack) == 1);
}

void test_stack_push() {
  Stack s1 = stack_new(1);
  Stack *stack = &s1;
  StackResult r1, *result;
  result = &r1;
  stack_push(stack, 10, result);
  assert((stack->data[0] == 10) && (stack->top == 0) && (result->status == STACK_OK));
  stack_push(stack, 20, result);
  assert(result->status == STACK_FULL);
  assert(stack_full(stack));
}

void test_stack_pop() {
  Stack s1 = stack_new(1);
  Stack *stack = &s1;
  StackResult r1, *result;
  result = &r1;
  stack_push(stack, 10, result);
  stack_pop(stack, result);
  assert((stack->top == -1) && (result->status == STACK_OK) && (result->data == 10));
  stack_pop(stack, result);
  assert(result->status == STACK_EMPTY);
  assert(stack_empty(stack));
}

void test_stack_peek() {
  Stack s1 = stack_new(1);
  Stack *stack = &s1;
  StackResult r1, *result;
  result = &r1;
  stack_push(stack, 10, result);
  stack_peek(stack, result);
  assert((result->status == STACK_OK) && (result->data == 10));
  stack_pop(stack, result);
  stack_peek(stack, result);
  assert(result->status == STACK_EMPTY);
  assert(stack_empty(stack));
}


int main() {
  test_stack_new();
  test_stack_empty();
  test_stack_full();
  test_stack_push();
  test_stack_pop();
}