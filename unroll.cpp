int FuncA(int x) { return x; }
int FuncB(int x) { return 2 * x; }
int FuncC(int x) { return 3 * x; }

int original(int x) {
  int result = 0;
  for (int i = 0; i < 2 * x; ++i) {
    if (i % 2 == 0) {
      result += FuncA(i);
    } else {
      result += FuncB(i);
    }
    result += FuncC(i);
  }
  return result;
}

int unrolled(int x) {
  int result = 0;
  for (int i = 0; i < 2 * x; i += 2) {
    result += FuncA(i);
    result += FuncC(i);
    result += FuncB(i + 1);
    result += FuncC(i + 1);
  }
  return result;
}
