#include <bits/stdc++.h>

using namespace std;

const int LEN = 10;

int tc, n, teams, member, team;
deque <pair <deque <int>, int>> dq;
map <int, int> mp;
char command[LEN];
bool found;

void getQueries() {
    while (scanf("%s", command), command[0] != 'S') {
        if (command[0] == 'D') {
            printf("%d\n", dq.front().first.front());
            dq.front().first.pop_front();
            if (dq.front().first.empty()) dq.pop_front();
        }
        else {
            scanf("%d", &member);
            team = mp[member];
            found = false;
            for (int i = 0; i < dq.size() and not found; i++)
                if (dq[i].second == team) dq[i].first.push_back(member), found = true;
            if (not found) dq.push_back({{member}, team});
        }
    }
}

void getTeams() {
    while (teams--) {
        scanf ("%d", &n);
        while (n--) scanf("%d", &member), mp[member] = teams;
    }
}

void clear() {
    mp.clear();
    dq.clear();
}

int main() {
    while (scanf("%d", &teams), teams) {
        clear();
        getTeams();
        printf("Scenario #%d\n", ++tc);
        getQueries();
        putchar('\n');
    }
    return (0);
}