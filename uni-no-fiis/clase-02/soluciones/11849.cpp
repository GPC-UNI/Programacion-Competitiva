#include <bits/stdc++.h>

using namespace std;

int n, m, num, ans;

int main() {
    while (scanf("%d %d", &n, &m), n or m) {
        set <int> st;
        ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", &num), st.insert(num);
        for (int i = 0; i < m; i++) {
            scanf("%d", &num);
            if (st.find(num) != st.end()) ans++;
        }
        printf("%d\n", ans);
    }
    return (0);
}