#include <bits/stdc++.h>

using namespace std;

const int LEN = 100, N_CARDS = 6;

int ct[N_CARDS + 1];
char moves[LEN];
bool ans;

namespace Minimax {
  int minVal();
  int maxVal();
  void solve();
}

namespace Minimax {
    
  int sum;
  const int WIN  =  1;
  const int FAIL = -1;

  int minVal () {
    if (sum > 31) return FAIL;
    int ret = WIN;
    for (int card = 1; card <= N_CARDS and ret != FAIL; card++) {
      if (ct[card]) {
        ct[card]--, sum += card;
        ret = min(ret, maxVal());
        ct[card]++, sum -= card;
      }
    }
    return ret;
  }

  int maxVal () {
    if (sum > 31) return WIN;
    int ret = FAIL;
    for (int card = 1; card <= N_CARDS and ret != WIN; card++) {
      if (ct[card]) {
        ct[card]--, sum += card;
        ret = max(ret, minVal());
        ct[card]++, sum -= card;
      }
    }
    return ret;
  }

  void solve () {
    sum = 0;
    int id;
    for (id = 0; moves[id]; id++) {
      ct[moves[id] - '0']--;
      sum += moves[id] - '0';
    }
    int res = (id & 1) ? minVal() : maxVal();
    ans = res == WIN;
  }
}


inline void print() {
  printf("%s %c\n", moves, "BA"[ans]);
}

inline bool read() {
  if (cin.getline(moves, LEN)) return true;
  return false;
}

inline void clear() {
  fill(ct, ct + N_CARDS, 4);
}

int main () {
  while (read()) {
    clear();
    Minimax::solve();
    print();
  }
  return (0);   
}

