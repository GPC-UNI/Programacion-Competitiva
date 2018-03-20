/**
 * Link
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2162
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_P = 1e4 + 100;

int T, sq[MAX_P];
string line, word;
bool valid;

void perfectSquare() {
    for (int p = 1; p * p <= MAX_P; p++) sq[p * p] = p;
}

int main() {
    perfectSquare();
    cin >> T;
    cin.ignore();
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ':' << endl;
        getline(cin, line);
        word = "";
        for (char ch : line) if (isalpha(ch)) word += ch;
        valid = sq[word.size()];
        if (valid) {
            int k = word.size();
            for (int i = 0; i < word.size() / 2; i++)
                if (word[i] != word[--k]) valid = false;
            k = word.size() - 1;
            int len = sq[word.size()];
            for (int i = 0; i < len; i++, k--)
                for (int j = 0; j < len; j++)
                    if (word[i + j * len] != word[k - j * len]) valid = false;
        }
        valid ? cout << sq[word.size()] << endl : cout << "No magic :(" << endl;
    }
    return (0);
}
