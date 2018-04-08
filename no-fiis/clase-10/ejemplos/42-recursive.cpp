#include <bits/stdc++.h>

using namespace std;

const int SUM = 42, MAX_LEN = 7;

int sum;
string word;
vector <string> ans;

void backtracking(char ch = 'a') {
    if (sum > SUM) return;
    if (sum == SUM and word.size() <= MAX_LEN) {
        do {
            ans.push_back(word);
        } while(next_permutation(begin(word), end(word)));
    }
    for (char nch = ch; nch <= 'z'; nch++) {
        sum += nch - 'a' + 1;
        word.push_back(nch);
        backtracking(nch);
        word.pop_back();
        sum -= nch - 'a' + 1;
    }
}

int main() {
    backtracking();
    sort(begin(ans), end(ans));
    for (string ans_i : ans) cout << ans_i << endl;
    return (0);
}
