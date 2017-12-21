/**
 * By: Victoralin10
 */
 
#include <iostream>
 
using namespace std;
 
int main() {
    int notas[6], a[6], b[6], ans = 0;
    for (int i = 0; i < 6; i++) {
        cin >> notas[i];
        if (notas[i] == -1) {
            a[i] = 0, b[i] = 20;
        } else {
            a[i] = b[i] = notas[i];
        }
        notas[i] = a[i];
    }
 
    bool next = true;
    do {
        ans += (notas[0] + notas[1] + notas[2] + notas[3]
        - min(min(notas[0], notas[1]), min(notas[2], notas[3])) 
        + (notas[4] + notas[5])*3 >= 90);
 
        next = false;
        for (int i = 0; i < 6; i++) {
            if (a[i] == b[i]) continue;
            if (notas[i] < b[i]) {
                notas[i]++;
                next = true;
                break;
            } else {
                notas[i] = a[i];
            }
        }
    } while (next);
 
    cout << ans << endl;
}
