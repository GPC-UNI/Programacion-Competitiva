#include <bits/stdc++.h>

using namespace std;

int T, N;
string S, word;
set <string> dict;
unordered_map <int, int> memo;

inline int _hash(const int& l, const int& r) {
  return l * S.size() + r;
}

int SGV (int l, int r) {
  if (r < l) return 0;
  int __hash = _hash(l, r);
  if (memo.find(__hash) != memo.end()) return memo[__hash];
  int mex = 0;
  unordered_set <int> Grundy;
  for (int i = l; i <= r; i++)
    for (int j = i; j <= r; j++)
      if (dict.find(string(S.begin() + i, S.begin() + j + 1)) != dict.end())
        Grundy.insert(SGV(l, i - 1) xor SGV(j + 1, r));
  while (Grundy.find(mex) != Grundy.end()) mex++;
  return memo[__hash] = mex;
}

int main () {
  cin >> T;
  while (T--) {
    memo.clear();
    dict.clear();
    cin >> S >> N;
    while (N--) cin >> word, dict.insert(word);
    puts(SGV(0, S.size() - 1) == 0 ? "Tracy" : "Teddy");
  }
  return (0);
}
