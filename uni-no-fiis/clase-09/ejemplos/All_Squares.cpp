#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define rc(x) scanf("%c",&(x))
using namespace::std;

const long double PI = acos(-1);
const int MOD = 1000000000 +7;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;
typedef set<int> si;
typedef set<ii> sii;
typedef set<iii> siii;

ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}

int add(ll a, ll b){ return (a%MOD + b%MOD+2*MOD)%MOD;}

int mul(ll a, ll b){ return ((a%MOD+MOD)*(b%MOD+MOD))%MOD;}

ll pow_mod(ll a, ll b){
	ll res = 1LL;
	a = a%MOD;
	while(b){
		if(b&1) res = mul(res,a);
		b >>= 1;
		a = mul(a,a);
	}
	return res;
}

ll fastexp(ll a, ll b){
	ll res = 1LL;
	while(b){
		if(b&1) res = res*a;
		b >>= 1;
		a *= a;
	}
	return res;
}

int gcdExtendido(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtendido(b%a,a,&x1,&y1);
	
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
};

int modInverso(int a, int m){
	int x, y;
	int g = gcdExtendido(a,m,&x,&y);
	if(g!=1) return -1;
	else return (x%m + m)%m;
}

/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/

/* Para este problema, nos es mas sencillo usar como referencia el centro del 
 * cuadrado que colocaremos, el cual tendra de lado 2k+1, por lo que las
 * esquinas tendran coordenadas
 *
 * (Ox-k,Oy-k) ------ (Ox-k,Oy+k) ------ (Ox+k,Oy-k) ------ (Ox+k,Oy+k)
 * 
 * Preferimos usar una variable global para aumentarla en 1 cada vez que 
 * encontramos un cuadrado que contenga el punto que nos dan
 *
*/

int ans;
int x,y;

void check(int k, int Ox, int Oy){
	if(k == 0) return;
	if(Ox-k <= x and x <= Ox+k and Oy-k <= y and y <= Oy+k) ans++;
	check(k/2,Ox-k,Oy+k);
	check(k/2,Ox-k,Oy-k);
	check(k/2,Ox+k,Oy+k);
	check(k/2,Ox+k,Oy-k);
}

int main(){
	int n;
	while(ri3(n,x,y)==3 and n){
		ans = 0;
		check(n,1024,1024);
		printf("%3d\n",ans);
	}
	return 0;
}
