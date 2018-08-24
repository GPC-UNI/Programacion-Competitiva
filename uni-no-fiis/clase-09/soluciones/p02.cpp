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

/* Problema de implementacion, usar recursion para resolver el problema y leer al mismo tiempo
 * Si tiene un 0 en la parte de peso, entonces plantear recursion para otro problema de mismas caracteristicas.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/

ii Read(){
	int w1, d1, w2, d2;
	ri2(w1,d1);
	ri2(w2,d2);
	bool can = true; // Asumiendo que no hay ningun submovil
	ii submovil1 = mp(0,1), submovil2 = mp(0,1); // Equilibrio y peso 0
	if(w1 == 0){
		submovil1 = Read(); // Resolvemos submovil y asignamos
	}
	if(w2 == 0){
		submovil2 = Read(); // Resolvemos submovil y asignamos
		
	}
	if(!submovil1.second) can = false;
	if(!submovil2.second) can = false;
	w1 += submovil1.first;
	w2 += submovil2.first;
	if(w1*d1 == w2*d2){
		return mp(w1+w2,1&can);
	}
	else return mp(w1+w2,0&can);
}

void solve(){
	ii can = Read();
	puts(can.second?"YES":"NO");
}

int main(){
	int t;
	ri(t);
	while(t--){
		solve();
		if(t) puts("");
	}
	return 0;
}
