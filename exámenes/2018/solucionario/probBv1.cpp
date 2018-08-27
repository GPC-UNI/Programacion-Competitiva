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
    }
 
    for (int pc1 = a[0]; pc1 <= b[0]; pc1++) {
        for (int pc2 = a[1]; pc2 <= b[1]; pc2++) {
            for (int pc3 = a[2]; pc3 <= b[2]; pc3++) {
                for (int pc4 = a[3]; pc4 <= b[3]; pc4++) {
                    for (int ep = a[4]; ep <= b[4]; ep++) {
                        for (int ef = a[5]; ef <= b[5]; ef++) {
                            ans += (pc1 + pc2 + pc3 + pc4 - min(min(pc1, pc2), min(pc3, pc4)) + (ef + ep)*3 >= 90);
                        }
                    }
                }
            }
        }
    }
 
    cout << ans << endl;
}
