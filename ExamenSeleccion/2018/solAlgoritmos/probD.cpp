/**
 * By: Victoralin10
 */
 
#include <iostream>
 
using namespace std;
 
#define MAXN 100005
 
int S[MAXN], cs[10], cp[10];
 
int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    for (int i = 0, p; i < m; i++) {
        cin >> p;
        cp[p]++;
    }
    for (int i = 0; i < m; i++) {
        cs[S[i]]++;
    }
    for (int i = m; i <= n; i++) {
        bool ok = 1;
        for (int j = 0; j < 10; j++) {
            ok = ok && (cs[j] == cp[j]);
        }
        ans += ok;
        cs[S[i]]++;
        cs[S[i - m]]--;
    }
    cout << ans << endl;
}
