#include <stdint.h>
#include "appconstant.h"

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#ifndef STACK_DATA_TYPE
#define STACK_DATA_TYPE float
#endif

typedef struct _stack_ Stack;

struct _stack_ {
  uint32_t                size;
  int32_t                 top;
  STACK_DATA_TYPE         data[MAX_DEPTH];
};

typedef struct _stack_result_ StackResult;

struct _stack_result_ {
  STACK_DATA_TYPE data;
  STACK_STATUS    status;
};

// Public interface

Stack         stack_new(uint32_t);
uint8_t       stack_full(const Stack *);
uint8_t       stack_empty(const Stack *);
Stack*        stack_push(Stack *, STACK_DATA_TYPE, StackResult *);
Stack*        stack_pop(Stack *, StackResult *);
Stack*        stack_peek(Stack *, StackResult *);

#endif