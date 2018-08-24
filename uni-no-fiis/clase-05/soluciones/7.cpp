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

// Clase BigInteger con suma implementada y basta con almacenamiento de los numeros de Fibonacci

const int N = 5000+5;

class Integer{
	public:
	int n;
	vector<int> v;
	Integer(){
		n = 0;
		v.clear();
	}
	
	void use(int x){
		if(x == 0){
			n = 1;
			v.pb(0);
		}
		else{
			n = 0;
			v.clear();
			while(x){
				v.pb(x%10);
				x /= 10;
				n++;
			}
		}
	}

	void sumar(Integer b){
		int tam = max(n,b.n);
		vector<int> carry;
		for(int i=0; i<tam; i++){
			int x = 0;
			if(i < n) x += v[i];
			if(i < b.n) x += b.v[i];
			carry.pb(x);
		}
		for(int i=0; i<tam; i++){
			if(carry[i] > 9){
				if(i == tam-1){
					carry.pb(carry[i]/10);
					carry[i] %= 10;
				}
				else{
					carry[i+1] += carry[i]/10;
					carry[i] %= 10;
				}
			}
		}
		n = carry.size();
		v = carry;
	}

	void Print(){
		for(int i=n-1; i>=0; i--){
			putchar('0'+v[i]);
		}
	}
};

int n;
Integer F[N];

int main(){
	F[0].use(0);
	F[1].use(1);
	for(int i=2; i<N; i++){
		F[i].use(0);
		F[i].sumar(F[i-1]);
		F[i].sumar(F[i-2]);
	}
	while(ri(n)==1){
		printf("The Fibonacci number for %d is ",n);
		F[n].Print();
		puts("");
	}
	return 0;
}
