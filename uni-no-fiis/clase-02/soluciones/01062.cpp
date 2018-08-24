#include <bits/stdc++.h>

using namespace std;

int tc;
string line;
vector <vector <char>> simulation;

int main() {
    while (cin >> line, line != "end") {
        simulation.clear();
        simulation.push_back({line.front()});
        for (int id = 1; id < line.size(); id++) {
            char ch = line[id];
            bool inserted = false;
            for (int k = 0; k < simulation.size() and not inserted; k++)
                if (ch <= simulation[k].back()) simulation[k].push_back(ch), inserted = true;
            if (not inserted) simulation.push_back({ch});
        }
        cout << "Case " << ++tc << ": " << simulation.size() << endl;
    }
    return (0);
}