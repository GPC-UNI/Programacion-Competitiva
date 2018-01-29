#include<bits/stdc++.h>
#define N 1000005

using namespace std;

string s;
int n, x, y;
int A[N];


int main(){
	int caso = 1;

	while( cin >> s ){
		A[1] = s[0]-'0';
		for( int i = 1; i < s.length(); i++ )
			A[i+1] = A[i]+(s[i]-'0');

		scanf("%d",&n);
		printf("Case %d:\n",caso++);
		for( int i = 0; i < n; i++  ){
			scanf("%d%d",&x,&y);
			if( x > y ) swap( x, y );
			if( (y-x+1) == ( A[y+1] - A[x] ) || A[y+1] == A[x] ) puts("Yes");
			else puts("No");
		}	
	}
	return 0;
}
