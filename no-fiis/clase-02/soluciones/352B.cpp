#include <bits/stdc++.h>

using namespace std;

int n, num;
vector <pair <int, int>> v, ans;

void check(int _start, int _end) {
    int _diff = (v[_end - 1].second - v[_start].second) / max(1, (_end - _start - 1));
    while (++_start < _end) if (v[_start].second - v[_start - 1].second != _diff) return;
    ans.push_back(make_pair(v[--_start].first, _diff));
}

int main() {
    cin >> n;
    for (int id = 0; id < n; id++) cin >> num, v.push_back(make_pair(num, id));
    sort(v.begin(), v.end());
    int _start = 0, _end = 0;
    while (_start < n) {
        while (_end < n and v[_start].first == v[_end].first) _end++;
        check(_start, _end);
        _start = _end;
    }
    cout << ans.size() << endl;
    for (auto pp : ans) cout << pp.first << ' ' << pp.second << endl;
    return (0);
}