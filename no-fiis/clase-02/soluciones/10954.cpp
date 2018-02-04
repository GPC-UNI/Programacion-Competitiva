#include <bits/stdc++.h>

using namespace std;

int N, ans, num;

int main() {
    while (cin >> N, N) {
        ans = 0;
        priority_queue <int> v;
        for (int i = 0; i < N; i++) cin >> num, v.push(-num);
        for (int i = 1; i < N; i++) {
            int a = v.top(); v.pop();
            int b = v.top(); v.pop();
            ans -= a + b;
            v.push(a + b);
        }
        cout << ans << endl;
    }
    return (0);
}