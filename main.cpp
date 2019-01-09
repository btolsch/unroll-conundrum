#include <stdio.h>
#include <time.h>

int original(int x);
int unrolled(int x);

int main() {
  int result = 0;
  int loop_count = 100000;
  int arg = 1000;

  struct timespec begin, end;

  clock_gettime(CLOCK_MONOTONIC, &begin);
  for (int i = 0; i < loop_count; ++i) {
    result += original(arg);
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  printf(
      "original(%d): %f ms\n", result,
      ((end.tv_sec - begin.tv_sec) * 1000000000 + end.tv_nsec - begin.tv_nsec) /
          1000000.0f);

  result = 0;
  clock_gettime(CLOCK_MONOTONIC, &begin);
  for (int i = 0; i < loop_count; ++i) {
    result += unrolled(arg);
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  printf(
      "unrolled(%d): %f ms\n", result,
      ((end.tv_sec - begin.tv_sec) * 1000000000 + end.tv_nsec - begin.tv_nsec) /
          1000000.0f);

  return result;
}
