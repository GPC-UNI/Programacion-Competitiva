#include <bits/stdc++.h>

using namespace std;

int X, n, sum;
vector <int> a, choice;

void backtracking(int idx = 0) {
    if (sum > X) return;
    if (sum == X) {
        for (int c_i : choice) cout << c_i << ' ';
        cout << endl;
    }
    if (idx == n) return;
    sum += a[idx];
    choice.push_back(a[idx]);
    backtracking(idx + 1);
    sum -= a[idx];
    choice.pop_back();
    backtracking(idx + 1);
}

int main() {
    a = {2, 2, 2, 2, 2, 5, 5, 5, 10, 10, 10, 20};
    n = a.size();
    X = 20;
    backtracking();
    return (0);
}
