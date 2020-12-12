#ifndef QUEUE_STACK_H_INCLUDED
#define QUEUE_STACK_H_INCLUDED

#include <stdint.h>
#include "stack.h"

typedef struct _stack_ Queue;
typedef struct _stack_result_ QueueResult;

Queue   queue_new(uint32_t);
Queue   *queue_enqueue(Queue *, float, QueueResult *);
Queue   *queue_dequeue(Queue *, QueueResult *);


#endif