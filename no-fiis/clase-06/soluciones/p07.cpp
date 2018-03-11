#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

struct Team{
   char name[SIZE], lower_name[SIZE];
   int points, games, goals, sgoals, dif;
}aux;

int tc, t, g, pos1, pos2, g1, g2, j;
char s[SIZE], team1[SIZE], team2[SIZE];
vector <Team> v;

inline bool equals(Team x, Team y) {
   return (x.points == y.points && x.dif == y.dif && x.goals == y.goals);
}

bool cmp(const Team& x, const Team& y) {
   if(x.points != y.points) return (x.points > y.points);
   if(x.dif != y.dif) return (x.dif > y.dif);
   if(x.goals != y.goals) return (x.goals > y.goals);
   return (strcmp(x.lower_name, y.lower_name) < 0);
}

void lowerNames() {
   for(int i = 0; i < v.size(); i++){
      for(j = 0; v[i].name[j]; j++) v[i].lower_name[j] = tolower(v[i].name[j]);
      v[i].lower_name[j] = '\0';
   }
}

int findTeam(char x[]) {
   for(int i = 0; i < v.size(); i++) if(strcmp(v[i].name, x)==0) return i;
}

void printResults() {
   int it = 1;
   for(int i = 0; i < v.size(); i++, it++){
      if(i == 0 || equals(v[i], v[i - 1]) == false) printf("%2d.", it);
      else printf("   ");
      printf("%16s %3d %3d %3d %3d %3d ", v[i].name, v[i].points, v[i].games, v[i].goals, v[i].sgoals, v[i].dif);
      if(v[i].games) printf("%6.2f\n", 100.0 * v[i].points / (3.0 * v[i].games));
      else printf("   N/A\n");
   }  
}

int main(){
    while (scanf("%d %d\n", &t, &g), t | g) {
        if (tc++) putchar('\n');
        v.clear();
        for (int i = 0; i < t; i++) scanf("%s", s), strcpy(aux.name, s), v.push_back(aux);
        for (int i = 0;i < g; i++){
            scanf("%s %d - %d %s", team1, &g1, &g2, team2);
            pos1 = findTeam(team1);
            pos2 = findTeam(team2);
            if(g1 > g2) v[pos1].points += 3;
            else if(g1 < g2) v[pos2].points += 3;
            else v[pos1].points += 1, v[pos2].points += 1;
            v[pos1].games += 1, v[pos2].games += 1;
            v[pos1].goals += g1, v[pos2].goals += g2;
            v[pos1].sgoals += g2, v[pos2].sgoals += g1;
            v[pos1].dif += g1 - g2;
            v[pos2].dif += g2 - g1;
        }
        lowerNames();
        sort(v.begin(), v.end(), cmp);
        printResults();
    }
    return(0);
}
