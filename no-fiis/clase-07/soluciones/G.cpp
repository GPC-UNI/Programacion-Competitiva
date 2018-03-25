/**
	problem : http://codeforces.com/contest/760/problem/B
	approach: binary search, math
	
	solution: la idea consiste en hacer una piramide con
	altura maxima en la posicion k, vemos que si podemos
	hacer una piramide de altura h, claro que podemos hacer una menor.
	
	code: recuerde que se intenta hacer una piramide pero quizas
	salga algo mas raro.
	
	complexity: O(log(m - n))
**/

#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

void input(){
 	scanf("%d %d %d", &n, &m, &k);
	m -= n;
}


bool p(long long x){
	
	long long r = m - x;
	long long l1 = min(x-1, k-1);
	long long l2 = min(n-k, x-1);

	long long r1 = (x-l1-1)*(k-1) + l1*(l1+1)/2;
	long long r2 = (x-l2-1)*(n-k) + l2*(l2+1)/2;


	return r1+r2 <= r;
}

void solve(){
	int lo = 0, hi = m;
	while(lo <  hi){
		int mid = lo + (hi - lo + 1)/2;
		if(p(mid)) lo = mid;
		else hi = mid-1;
	}

	printf("%d\n", lo+1);
}


int main(){

	input();
	solve();

	return 0;
}