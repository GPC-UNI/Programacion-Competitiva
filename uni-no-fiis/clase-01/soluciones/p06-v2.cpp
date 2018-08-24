/**
 * Usando Backtracking + bit manipulation
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 110;

struct Word {
    int length;
    char ch_1, ch_2;
};

int n, n_words, sum, ans;
string ss;
Word word[MAX_N];

int mark(int id, int used) {
    used |= 1 << (word[id].ch_1 - 'a');
    used |= 1 << (word[id].ch_2 - 'a');
    return used;
}

void backtrack(int id = 0, int used = 0) {
    if (__builtin_popcount(used) > 2) return;
    if (id == n_words) {
        ans = max(ans, sum);
        return;
    }
    if (__builtin_popcount(used) == __builtin_popcount(mark(id, used))) {
        sum += word[id].length;
        backtrack(id + 1, mark(id, used));
        sum -= word[id].length;
    }
    else {
        sum += word[id].length;
        backtrack(id + 1, mark(id, used));
        sum -= word[id].length;
        backtrack(id + 1, used);
    }
}

void include() {
    word[n_words].length = ss.length();
    word[n_words].ch_1 = word[n_words].ch_2 = ss.front();
    for (int pos = 1; pos < ss.size(); pos++)
        if (ss[pos] != word[n_words].ch_1) {
            if (word[n_words].ch_1 == word[n_words].ch_2) word[n_words].ch_2 = ss[pos];
            else if (word[n_words].ch_2 != ss[pos]) return;
        }
    n_words++;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ss, include();
    backtrack();
    cout << ans << endl;
    return (0);
}