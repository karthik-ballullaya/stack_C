#include "queue_stack.h"
#include "appconstant.h"

Queue queue_new(uint32_t size) {
  return stack_new(size);
}

Queue *queue_enqueue(Queue *q, float x, QueueResult *res) {
  return stack_push(q, x, res);
}

Queue *queue_dequeue(Queue *q, QueueResult *res) {
  Stack s = stack_new(q->top + 1), *stack = &s;
  StackResult sres;
  float data;
  while(res->status != STACK_EMPTY) {
    stack_pop(q, res);
    stack_push(stack, res->data, &sres);
  }
  data = sres.data;
  while(sres.status != STACK_EMPTY) {
    stack_pop(stack, &sres);
    stack_push(q, sres.data, res);
  }
  res->data = data;
  return q;
}