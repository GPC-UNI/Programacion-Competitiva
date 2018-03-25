/**
	problem : http://codeforces.com/problemset/problem/231/C
	approach: binary search, sort, accumulate
	
	solution:

		hint 1: Si el elemento que mas se repide haciendo k
		cambios es x, entonces, los elementos que forman la 
		respuesta en un inicio son <= x.
		
		hint 2: Si la respuesta es x con h operaciones y t 
		repeticiones, para reducir h a lo menos posible los
		t elementos que se usan deben ser los mayores posibles
		que son <= x.		

		hint 3: Como nos piden usar a lo mas k operaciones, 
		y vez que el que mas se repite es y con q repeticiones y
		con m operaciones y el mayor elementos que usaste es z, 
		con z < y entonces podemos reducir las opeaciones en 
		(y - z)*q haciendo y = z. Esto nos dice que para que
		se gaste lo menos posibles, el elemento que se repite
		mas esta necesariamente en el array.  

	
	code: 
		si la respuesta es a[i], entonces buscaremos los que
		son mas cercanos a a[i] pero <= a el, para ello podemos
		ordenar los elementos y hacemos una busqueda binary sobre
		la cantidad de elementos que se repiten, vemos que esta
		funcion es a[i] * len - (sum[i] - sum[i - len + 1]), vemos
		que esta funcion es decreciente (pruebe eso), y por tanto
		es factible usar busqueda binaria. 
		
	
	complexity: O(n x log(n))
**/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxN = 1e5, OFFSET = 2;
int a[maxN + OFFSET];
long long sum[maxN + OFFSET];
int n, k;

void input(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
}

bool p(int x, int i){
	return a[i] * 1ll * (i - x + 1) - (sum[i] - sum[x-1]) <= k;
}

void solve(){
	
	sort(&a[1], &a[n+1]);
	
	for(int i = 1; i <= n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	int ans = 0, Min;
	for(int i = 1; i <= n; ++i){
		int lo = 1, hi = i;
		while(lo < hi){
			int mid = lo + (hi - lo)/2;
			if(not p(mid, i)) lo = mid + 1;
			else hi = mid;
		}
		
		if(ans < i - lo + 1){
			ans = i - lo + 1;
			Min = a[i];
		}
	}
	
	printf("%d %d\n", ans, Min);
}


int main() {
	
	input();
	solve();
	
	return 0;
}