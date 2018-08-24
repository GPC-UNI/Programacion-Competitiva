/**
 * Link
 * http://codeforces.com/problemset/problem/578/B
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

long long n, k, x, ans, prod = 1, arr[MAX_N], prefix[MAX_N], suffix[MAX_N];

int main() {
    cin >> n >> k >> x;
    while (k--) prod *= x;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) prefix[i] = arr[i] bitor prefix[i - 1];
    for (int i = n; i >= 1; i--) suffix[i] = arr[i] bitor suffix[i + 1];
    for (int i = 1; i <= n; i++)
        ans = max(ans, prefix[i - 1] bitor (arr[i] * prod) bitor suffix[i + 1]);
    cout << ans << endl;
    return (0);
}
