/**
	problem : http://codeforces.com/contest/439/problem/D
	approach: binary search, discrete calculus
	
	solution: 
		sea la funcion f(x) : la cantidad de minima de 
		operaciones para que el maximo elemento de b sea
		<= x y el minimo elemento de a sea >= x. Numericamente
		es igual a sum( x  - a[i], con a[i] < x) + 
		sum(b[i] - x, con b[i] > x), ahora si nosotros
		derivamos respecto a x tenemos sum(1, con a[i] < x) +
		sum(-1, con b[i] > x), poddemos apreciar que al aumentar
		x hay >= cantidad de a[i] que son < x y <= cantidad
		de b[i] que son mayores a x, esto nos dice que 
		la primera derivada es no decreciente, con lo cual la 
		segunda derivada es no negativa, por tanto es una
		funcion convexa, entonces para hallar lo que queremos
		no necesitamos mas que hallar el minimo para esta funcion.

	code:
		...

	
	complexity: O(n x log(max(a)))
**/


#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5, OFFSET = 2;
int a[maxN + OFFSET], b[maxN + OFFSET];
int n, m;

void input(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < m; ++i)
	        scanf("%d", b+i);
}

long long f(int x){
	long long ans = 0;
	for(int i = 0; i < n; ++i)
		ans += max(x - a[i], 0);    	 	
	for(int i = 0; i < m; ++i)
		ans += max(b[i] - x, 0);
	
	return ans;
}

long long df(int x){
 	return f(x+1) - f(x);
}

bool p(int x){
 	return df(x) < 0;
}

void solve(){
	int lo = 1, hi = 1e9;
	while(lo < hi){
	     int mid = lo + (hi-lo)/2;
	     if(p(mid)) lo = mid+1;
	     else hi = mid;  
	}

	printf("%lld\n", f(lo));
}


int main(){

	input();
	solve();

	return 0;
}