/**
 * Usando Finding pattern or formula
 */

#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    cout << min(n - a, b + 1) << endl;
    return (0);
}