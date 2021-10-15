#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

long long calc(long long left, char op, long long right) {
  switch (op) {
  case '+':
    return left + right;
  case '-':
    return left - right;
  case '*':
    return left * right;
  case '/':
    return left / right;
  }
  fprintf(stderr, "Unrecognized op `%c'.\n", op);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr,
            "Usage: %s <num> <op> <num>\nWhere <op> is one of +, -, *, /.\n",
            argv[0]);
    return EXIT_FAILURE;
  }
  const char *left_str = argv[1];
  const char *op_str = argv[2];
  const char *right_str = argv[3];
  errno = 0;
  char *endptr;
  long long left = strtoll(left_str, &endptr, 10);
  if (left_str == endptr) {
    errno = EINVAL;
  }
  if (errno != 0) {
    perror(argv[0]);
    return EXIT_FAILURE;
  }
  if (op_str[1] != '\0') {
    fprintf(stderr, "Op must be one character. Got `%s'.\n", op_str);
    return EXIT_FAILURE;
  }
  errno = 0;
  long long right = strtoll(right_str, &endptr, 10);
  if (right_str == endptr) {
    errno = EINVAL;
  }
  if (errno != 0) {
    perror(argv[0]);
    return EXIT_FAILURE;
  }
  long long result = calc(left, op_str[0], right);
  fprintf(stdout, "%lld\n", result);
  return 0;
}
