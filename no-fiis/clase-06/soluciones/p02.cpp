#include <bits/stdc++.h>

#define SIZE 100
#define MAX_CONT 110
#define MAX_PROB 20

using namespace std;

struct part{
    int c, np, penalty;
} aux;

int tc, cont, prob, tim, score[MAX_CONT][MAX_PROB];
char s[SIZE], ch;
bool solved[MAX_CONT][MAX_PROB], submission[MAX_CONT];
vector <part> ans;

bool cmp(part x, part y) {
   if (x.np != y.np) return (x.np > y.np);
   if (x.penalty != y.penalty) return (x.penalty < y.penalty);
   return (x.c < y.c);
}

void fillRanking(){
   for (int c = 1; c < 110; c++){
      aux.c = c, aux.np = aux.penalty = 0;
      for (int p = 1; p <= 12; p++) if(solved[c][p]) aux.penalty += score[c][p], aux.np++;
      if (aux.np >= 1 || submission[c]) ans.push_back(aux);
   }
}

void printRanking(){
   for(int i = 0; i < ans.size(); i++) printf("%d %d %d\n", ans[i].c, ans[i].np, ans[i].penalty);
   ans.clear();
   memset(solved, false, sizeof solved);
   memset(score, 0, sizeof score);
   memset(submission, false, sizeof submission);
}

int main(){
    scanf("%d\n", &tc);
    while (tc--) {
        while (cin.getline(s, SIZE)) {
            if (sscanf(s,"%d %d %d %c", &cont, &prob, &tim, &ch) == -1) break;
            submission[cont] = true;
            if (ch == 'R' || ch == 'U' || ch == 'E') continue;
            if (solved[cont][prob] == false) {
                if(ch == 'C') score[cont][prob] += tim, solved[cont][prob] = true;
                if (ch == 'I') score[cont][prob] += 20;
            }
        }
        fillRanking();
        sort(begin(ans), end(ans), cmp);
        printRanking();
        if (tc) puts("");
    }
    return(0);
}
