/**
	problem : http://codeforces.com/contest/75/problem/C
	approach: binary search, sort, number theory
	
	solution: hallar los divisores del gcd(a, b) y hacer
	busqueda binaria para cada query con el predicado p(x) : Div[x] <= r,
	si se encuentra un valor ver que sea >= l	

	code: 
		...
	
	complexity: O(sqrt(min(a, b)) +  n x log(min(a, b)^{1/3}))
**/


#include <bits/stdc++.h>
using namespace std;

int a, b, n, l, r;
vector<int> Div;

void input(){
	scanf("%d %d", &a, &b);
}

void prepr(){
	int g = __gcd(a, b);
	int d = 1;
	for(; d*d < g; ++d)
		if(g % d == 0){
			Div.push_back(d);
			Div.push_back(g/d);
		}	

	if(d*d == g) Div.push_back(d);
	
	sort(Div.begin(), Div.end());
}

void querys(){

	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &l, &r);	
	
		int lo = 0, hi = (int)Div.size() - 1;
		while(lo < hi){
			int mid = lo + (hi-lo+1)/2;
			if(Div[mid] <= r) lo = mid;
			else hi = mid-1;
		}

		if(l <= Div[lo] and Div[lo] <= r) printf("%d\n", Div[lo]);
		else puts("-1");
	}
}


int main(){

	input();
	prepr();
	querys();

 	return 0;
}