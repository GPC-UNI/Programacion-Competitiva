/**
 * Link
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=131
 */

#include <bits/stdc++.h>

using namespace std;

int T;
string word;
vector <string> ans;

bool cmp(string s_1, string s_2) {
    for (int i = 0; i < s_1.size(); i++) {
        if (s_1[i] == s_2[i]) continue;
        if (tolower(s_1[i]) != tolower(s_2[i])) return tolower(s_1[i]) < tolower(s_2[i]);
        return s_1[i] < s_2[i];
    }
}

int main() {
    cin >> T;
    while (T--) {
        ans.clear();
        cin >> word;
        sort(begin(word), end(word));
        do {
            ans.push_back(word);
        } while(next_permutation(begin(word), end(word)));
        sort(begin(ans), end(ans), cmp);
        for (string s : ans) cout << s << endl;
    }
    return (0);
}
