/**
 * Usando DP
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 10;

int ct, a, b, dp[MAX_N];
long long n;

int getAns(int a, int b) {
   int ans = 0;
   for (int it = a; it <= b; it++)
      if (dp[it] > ans) ans = dp[it];
   return ans;
}

void precal() {
   for (int it = 1; it < MAX_N; it++) {
      ct = 1, n = it;
      while (n != 1) {
         ct++;
         n = (n & 1) ? 3 * n + 1 : n / 2;
         if (n < it) ct += dp[n] - 1, n = 1;
      }
      dp[it] = ct;
   }
}

int main(){
   precal();
   while(~scanf("%d %d", &a, &b)) printf("%d %d %d\n", a, b, getAns(min(a, b), max(a, b)));
   return(0);
}