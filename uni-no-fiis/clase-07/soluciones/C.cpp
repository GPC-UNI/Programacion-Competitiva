/**
	problem : http://codeforces.com/problemset/problem/670/D2
	approach: binary search
	
	solution: Podemos ver que si se pueden hacer x panqueques entonces
	tambien se pueden hacer menos.
	
	code: para implementarlo solo hay que considerar que si hago x
	panqueues, entonces la cantidad de ingrediente que necesito
	por cada ingrediente es max(a[i]*x - b[i], 0), luego ten en cuenta 
	que la suma puede dar hasta n*10^18, para solucionar esto 
	hacemos siempre minimo entre lo que necesitamos y k+1.
	
	complexity: O(n x log(max(b) + k))
**/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5, OFFSET = 2;
int a[N + OFFSET], b[N + OFFSET];
int n, k;


void input(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);

	for(int i = 0; i < n; ++i)
		scanf("%d", b+i);
}

bool p(long long x){

	long long magic = 0;
	for(int i = 0; i < n; ++i)
		magic += min(k+1ll, max(a[i]*x - b[i], 0ll));		
	
	return magic <= k;
}

void solve(){

	long long lo = 0, hi = 2e9;
	while(lo < hi){
		long long mid = lo + (hi-lo+1)/2;
		if(p(mid)) lo = mid;
		else hi = mid-1;
	}

	printf("%d\n", lo);
}



int main(){
	
	input();
	solve();

	return 0;
}