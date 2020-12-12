#ifndef APPCONSTANT_H_INCLUDED
#define APPCONSTANT_H_INCLUDED

#ifndef MAX_DEPTH
#define MAX_DEPTH   32
#endif

typedef enum _stack_status_ STACK_STATUS;
enum _stack_status_ {
  STACK_OK = 1,
  STACK_EMPTY,
  STACK_FULL
};

#endif