#include <bits/stdc++.h>

using namespace std;

int n, a, b, ans;
vector <pair <int, int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a >> b, v.push_back({a, b});
    sort(v.begin(), v.end(), [](const pair <int, int>& x, const pair <int, int>& y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });
    int mx = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first > v[i - 1].first and v[i].second < mx) ans++;
        mx = max(mx, v[i].second);
    }
    cout << ans << endl;
    return (0);
}