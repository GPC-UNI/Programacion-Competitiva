/**
 * Link
 * http://codeforces.com/problemset/problem/626/C
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, ans;

int main() {
    cin >> n >> m;
    while (true) {
        if ((n <= ans / 2) and
            (m <= ans / 3) and
            (n + m <= ans / 2 + ans / 3 - ans / 6)) break;
        ans++;
    }
    return (0);
}
