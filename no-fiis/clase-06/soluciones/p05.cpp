#include <bits/stdc++.h>

#define LIM  2000000000L

typedef long long ll;

using namespace std;

int idx;
ll num;
vector <int> humble_number;

int main(){
    for(ll two = 1; two < LIM; two *= 2)
	    for(ll three = 1; three < LIM; three *= 3)
            for(ll five = 1; five < LIM; five *= 5)
                for(ll seven = 1; seven < LIM; seven *= 7) {
                    num = two * three * five * seven;
                    if (num > LIM || num<0) break;
                    if (two * three > LIM || two * five > LIM || two * seven > LIM) break;
                    if (three * five > LIM || three * seven > LIM) break;
                    if (five * seven > LIM) break;
                    humble_number.push_back(num);
				}
	sort(humble_number.begin(), humble_number.end());
	while (scanf("%d", &idx), idx) {
		printf("The %d",idx);
		if (idx % 10 == 1 && (idx / 10) % 10 != 1) printf("st");
		else if (idx%10==2 && (idx / 10) % 10 != 1) printf("nd");
		else if (idx%10==3 && (idx / 10) % 10 != 1) printf("rd");
		else printf("th");
		printf(" humble number is %d.\n", humble_number[idx-1]);
	}
	return(0);
}

