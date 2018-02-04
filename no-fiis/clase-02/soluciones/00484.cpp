#include <bits/stdc++.h>

using namespace std;

int id, num;
map <int, int> frec, order;
set <int> vis;

int main() {
    while (cin >> num) {
        frec[num]++;
        if (vis.find(num) == vis.end()) order[id++] = num;
        vis.insert(num);
    }
    for (int i = 0; i < id; i++) cout << order[i] << ' ' << frec[order[i]] << endl;
    return (0);
}