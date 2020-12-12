#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"
#include "appconstant.h"

uint32_t evaluate_postfix(char *buffer);
void test_evaluate_postfix(void);

int main() {
  test_evaluate_postfix();
  return 0;
}

uint32_t evaluate_postfix(char *buffer) {
  Stack s = stack_new(MAX_DEPTH), *stack;
  StackResult sresult;
  stack = &s;
  for (char *i = buffer; *i != '\0'; i++) {
    if (*i >= '0' && *i <= '9') {
      stack_push(stack, *i - '0', &sresult);
    } else if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
      int8_t operands[2];
      for (int j = 0; j < 2; j++) {
        stack_pop(stack, &sresult);
        if (sresult.status == STACK_EMPTY) {
          return;
        }
        operands[j] = sresult.data;
      }
      switch (*i) {
        case '+':
          stack_push(stack, operands[0] + operands[1], &sresult);
          break;
        case '-':
          stack_push(stack, operands[0] - operands[1], &sresult);
          break;
        case '*':
          stack_push(stack, operands[0] * operands[1], &sresult);
          break;
        case '/':
          stack_push(stack, operands[0] / operands[1], &sresult);
          break;
      }
    }
  }
  stack_pop(stack, &sresult);
  return (sresult.data);
}

void test_evaluate_postfix() {
  assert(evaluate_postfix("1 2 +") == 3);
  assert(evaluate_postfix("6 5 2 3 + 8 * + 3 + *") == 288);
}