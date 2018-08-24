/**
	problem : http://codeforces.com/contest/779/problem/D
	approach: binary search, string
	
	solution: sea el predicado P(x) : se puede formar al 
	quitar los primero x elementos de la permutacion, entonces
	es claro que para todo y menor tambien se puede. 
	
	code: se puede usar una array visitados para borrar 
	temporalmente los elementos.
	
	complexity: O((|p| + |t|) x log(|p|))
**/


#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5, OFFSET = 2;
int n;
string p, t;
int a[maxN + OOFSET];
bool vis[maxN + OFFSET];

bool P(int x){
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < x; ++i)
		vis[a[i]] = 1;

	int k = 0;
	for(int i = 0; i < n; ++i){
		if(vis[i]) continue;
		if(p[i] == t[k]) k++;
		if(k == t.size()) return 1;
	}

	return 0;
}

int main(){


	cin >> p;
	cin >> t;

	n = p.size();
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		a[i]--;
	}
	
	int lo = 0, hi = n;
	while(lo < hi){
		int mid = lo + (hi-lo+1)/2;
		if(P(mid)) lo = mid;
		else hi = mid-1;
	}

	cout << lo << endl;

	return 0;
}