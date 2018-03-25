/**
	problem : http://codeforces.com/problemset/problem/812/C
	approach: binary search, sort
	
	solution: Debemos darnos cuenta que es una aplicacion directa de 
	predicado, ya que si podemos comprar x elementos, entonces, podemos
	comprar menos que eso ya que el precio es creciente (pruebe eso).
	
	code: para codear el programa como queremos gastar menos por cada
	k, nosotros reemplazamos cada a[i] por a[i] + k * i, (1 <= i <= n)
	y luego escogemos los k menores (se puede hacer facilmente ordenando).
	
	complexity: O(n x log^2(n))
**/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxN = 1e5, OFFSET = 2;
int a[maxN + OFFSET];
long long b[maxN + OFFSET];
long long ans;
int n, s;

void input(){
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
}

bool p(int k, int s){

	for(int i = 0; i < n; ++i)
		b[i] = (i+1) * 1ll * k + a[i];
		
	sort(b, b+n);

	ans = 0;
	for(int i = 0; i < k; ++i)
		ans += b[i];

	return ans <= s;
}

void solve(){
	
	int lo = 0, hi = n;
	while(lo < hi){
		int mid = lo + (hi - lo + 1)/2;
		if(p(mid, s)) lo = mid;
		else hi = mid-1;
	}
	
	printf("%d %d\n", lo, (p(lo, s), ans));
}


int main() {

	input();
	solve();
	
	return 0;
}