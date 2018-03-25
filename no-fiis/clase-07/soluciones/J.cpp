/**
	problem : http://codeforces.com/contest/803/problem/D
	approach: binary search, next
	
	solution: sea el predicado p(x): se puede formar el texto con <= x
	de ancho, es claro que se puede formar para todo y > x.
	
	code: se debe usar un array R (next), que me permita ir al
	siguiente quiebre permitido. 
	
	complexity: O(n x log(n))
**/


#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;
typedef long long ll;
const int N = 1000005;
string s;
int R[N];
int k, n;

bool p(int pos, int x, int l){

	if(l > k) return false;
	if(pos == n) return true;
	int y = pos;
	int in;
	while(y - pos <= x){
		in = y;
		y = R[y];
	}

	return p(in, x, l+1);
}



int main(){


	cin >> k;
	cin.ignore();
	getline(cin, s);

	n = s.size();
	R[n] = 1000000000;
	R[n-1] = n;
	for(int i = n - 2; i >= 0; --i)
		if(s[i] == ' ' or s[i] == '-') R[i] = i+1;			
		else R[i] = R[i+1];
	
	int lo = 1, hi = n;
	while(lo < hi){
		int mid = lo + (hi-lo)/2;
		if(not p(0, mid, 0)) lo = mid+1;		
		else hi = mid;
	}


	cout << lo << endl;


	return 0;
}