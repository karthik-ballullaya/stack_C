#include <assert.h>
#include "queue_stack.h"

void test_queue_stack() {
  Queue q1 = queue_new(10), *q = &q1;
  QueueResult res;
  queue_enqueue(q, 10, &res);
  queue_enqueue(q, 20, &res);
  queue_enqueue(q, 30, &res);
  queue_dequeue(q, &res);
  assert(res.data == 10);
}

int main(void) {
  test_queue_stack();
}