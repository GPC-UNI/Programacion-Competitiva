/**
 * Link
 * http://codeforces.com/problemset/problem/276/D
 * Check this
 * https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html#Other-Builtins
 */

#include <bits/stdc++.h>

using namespace std;

long long l, r;

int main() {
    cin >> l >> r;
    l == r ? cout << 0 << endl : cout << (1LL << (64 - __builtin_clzll(l xor r))) - 1 << endl;
    return (0);
}
