#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n), n) {
    int xor_sum = 0;
    for (int i = 0, x_i; i < n; i++) {
      scanf("%d", &x_i);
      xor_sum ^= x_i;
    }
    puts(xor_sum == 0 ? "No" : "Yes");
  }
  return (0);
}
