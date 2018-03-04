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
	a = add(a,0);
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

/* 
 * Para un par de puntos, la cantidad de triangulos que forma
 * es igual a la cantidad de puntos que no esten en su misma recta,
 * obviamente sin contar al mismo par de puntos
*/

const int N = 2000+5;

typedef pair<pll,pll> Recta;

int n;
int X[N], Y[N];
Recta O[N][N];
map<Recta,int> v[N];

int main(){
	ri(n);
	for(int i=0; i<n; i++){
		ri2(X[i],Y[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j) continue;
			ll a = X[i]-X[j];
			ll b = Y[i]-Y[j];
			if(a == 0){
				b = 1;
			}
			else if(b == 0){
				a = 1;
			}
			else{
				if(a < 0) a *= -1, b *= -1;
				ll mcd = gcd(abs(a),abs(b));
				a /= mcd;
				b /= mcd;
			}
			ll num = Y[i]*a-X[i]*b;
			ll den = a;
			if(num == 0){
				if(den != 0){
					den = 1;
				}
			}
			else if(den == 0){
				num = 1;
			}
			else{
				ll mcd = gcd(abs(num),abs(den));
				num /= mcd;
				den /= mcd;
				if(num < 0) num *= -1, den *= -1;
			}
			Recta carry = mp(mp(a,b),mp(num,den));
			v[i][carry]+=1;
			O[i][j] = carry;
		}
	}
	ll ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j) continue;
			ans += n-1-v[i][O[i][j]];
		}
	}
	cout << ans/6 << endl;
	return 0;
}
