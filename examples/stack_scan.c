#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "../../Queue/Headers/queue.h"

uint8_t stack_scan(Stack *stack, float x, StackResult *res) {
  assert(stack != NULL);
  uint8_t isElementFound = 0;
  Queue q1 = queue_new(stack->top), *q = &q1;
  QueueResult qres;
  while (!stack_empty(stack)) {
    stack_pop(stack, res);
    queue_add(q, res->data, &qres);
    if (res->data == x) {
      isElementFound = 1;
      break;
    }
  }
  for (uint32_t i = 0; i < q->count - 1; i++) {
    queue_delete(q, &qres);
    queue_add(q, qres.data, &qres);
  }
  for (uint32_t i = 0; i <= q->count; i++) {
    queue_delete(q, &qres);
    stack_push(stack, qres.data, res);
  }
  return isElementFound;
}

void test_scan() {
  Stack s = stack_new(10), *stack = &s;
  StackResult res;
  stack_push(stack, 10, &res);
  stack_push(stack, 20, &res);
  stack_push(stack, 30, &res);
  stack_push(stack, 40, &res);
  assert(stack_scan(stack, 20, &res) == 1);
  assert(stack_scan(stack, 35, &res) == 0);
  float data[] = {40, 30, 20, 10};
  for (uint32_t i = 0; i <= stack->top; i++) {
    stack_pop(stack, &res);
    assert(res.data == data[i]);
  }
}

int main(void) {
  test_scan();
}