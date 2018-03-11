#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

int n,tc;
char source[SIZE][SIZE], target[SIZE][SIZE], aux[SIZE][SIZE];
bool ok;

bool check(){
    for (int i = 0;i < n; i++)
        for (int j = 0;j < n; j++) if(source[i][j] != target[i][j]) return false;
    return true;
}

void rotate(){
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) aux[i][j] = source[n - j - 1][i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) source[i][j] = aux[i][j];
}

void reflect(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) aux[i][j] = source[n- i - 1][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) source[i][j] = aux[i][j];
}

int main(){
    while (scanf("%d\n",&n)==1) {
        ok = false;
        for (int i = 0; i < n; i++) scanf("%s %s", source[i], target[i]);
        for(int i = 1; i <= 2 && ok == false;i++){
            if (check()) {
                if (i == 1) printf("Pattern %d was preserved.\n", ++tc);
                else printf("Pattern %d was reflected vertically.\n", ++tc);
                ok = true;
                break;
            }
            for (int j = 1; j <= 3; j++) {
                rotate();
                if (check()) {
                    if (i == 1) printf("Pattern %d was rotated %d degrees.\n", ++tc, 90 * j);
                    else printf("Pattern %d was reflected vertically and rotated %d degrees.\n", ++tc, 90 * j);
               ok = true;
               break;
            }
         }
         rotate();
         reflect();
      }
      if(ok == false) printf("Pattern %d was improperly transformed.\n",++tc);
   }
   return(0);
}
