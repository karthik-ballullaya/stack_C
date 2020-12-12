#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"
#include "appconstant.h"

uint8_t check_bracket_balance(char *buffer);
void test_bracket_balance(void);


int main() {
  test_bracket_balance();
  return 0;
}


uint8_t check_bracket_balance(char *buffer) {
  char expectedChar;
  Stack s = stack_new(MAX_DEPTH), *stack;
  StackResult sresult;
  stack = &s;
  for (char *i = buffer; *i != '\0'; i++) {
    if (*i == '[' || *i == '{' || *i == '(') {
      stack_push(stack, *i, &sresult);
    } else if (*i == ']' || *i == '}' || *i == ')') {
      switch (*i) {
        case ']':
          expectedChar = '[';
          break;
        case '}':
          expectedChar = '{';
          break;
        case ')':
          expectedChar = '(';
          break;
      }
      stack_pop(stack, &sresult);
      if (expectedChar != sresult.data) {
        return (1);
      }
    }
  }
  return (0);
}

void test_bracket_balance() {
  assert(check_bracket_balance("[{}]") == 0);
  assert(check_bracket_balance("[{asbcusd(asbasf)[asniasf]}]") == 0);
  assert(check_bracket_balance("[{{()[]}}]") == 0);
  assert(check_bracket_balance("[{{()[]}]") == 1);
  assert(check_bracket_balance("][{{()[]}]") == 1);
}