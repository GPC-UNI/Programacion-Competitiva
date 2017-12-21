/**
 * By: Victoralin10
 */
 
#include <iostream>
 
using namespace std;
 
int main() {
    int n, m, a;
    cin >> n >> m >> a;
    cout << (long long)((n -1 )/a + 1)*((m - 1)/a + 1) << endl;
}
