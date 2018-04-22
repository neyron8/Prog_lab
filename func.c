#include <math.h>
#include <stdio.h>

int string(char *str, int sum) {
  if (*str == '\0') {
    return sum;
  }
  sum = sum + (*str - 48) * pow(10, strlen(str) - 1);
  str = str + 1;
  return string(str, sum);
}

int main() {
  char h[] = {"1234"};
  int sum = 0;
  printf("%d", string(h, sum));

  return 0;
}
