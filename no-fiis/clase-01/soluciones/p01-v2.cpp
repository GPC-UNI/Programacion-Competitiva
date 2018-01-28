/**
 * Usando sort
 */

#include <bits/stdc++.h>

using namespace std;

int d1, d2, d3;
vector <int> routes;

int main() {
    cin >> d1 >> d2 >> d3;
    routes.push_back(d1 + d1 + d2 + d2);
    routes.push_back(d1 + d3 + d2);
    routes.push_back(d1 + d3 + d3 + d1);
    routes.push_back(d2 + d3 + d3 + d2);
    sort(routes.begin(), routes.end());
    cout << routes.front() << endl;
    return (0);
}