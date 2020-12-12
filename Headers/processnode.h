#ifndef PROCESS_NODE_H_INCLUDED
#define PROCESS_NODE_H_INCLUDED

#include <stdint.h>

typedef struct _process_node_ ProcessNode;

struct _process_node_ {
  uint32_t            process_id;
  uint32_t            arrival_time;
  uint32_t            execution_time;
  int32_t             priority;
};

#endif