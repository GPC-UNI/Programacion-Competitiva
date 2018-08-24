#include <bits/stdc++.h>

using namespace std;

int n, _diff;

int main() {
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) if (a[i] != b[i]) _diff++;
    puts(_diff <= 2 ? "YES" : "NO");
    return (0);
}