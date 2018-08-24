/**
 * Link
 * http://codeforces.com/problemset/problem/614/A
 */

#include <bits/stdc++.h>

using namespace std;

long long l, r, k;
long double p = 1.0;
bool found = false;

int main() {
    cin >> l >> r >> k;
    while (true) {
        if (p > r) break;
        if (l <= p and p <= r) {
            long long pp = (long long) p;
            if (l <= pp and pp <= r)
                found = true, cout << pp << ' ';
        }
        p *= k;
    }
    not found ? cout << -1 << endl : cout << endl;
    return (0);
}
