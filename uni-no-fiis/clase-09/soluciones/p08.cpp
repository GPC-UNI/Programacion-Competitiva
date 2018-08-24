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

/* Simulacion:
 * 
 * Primero, fijarnos que si C > max(A,B) o C mod gcd(A,B) != 0 no se puede obtener la cantidad en alguno de los recipientes.
 * Plantear como una ecuacion diofantica para ello.
 * 
 * Caso truculento: C = 0, entonces la respuesta es 0
 * 
 * Para el resto de los casos, plantear una simulacion considerando como "base"
 * uno de los dos valores de A y B. Ordenando de la siguiente manera:
 * 
 * Recipiente 1, Recipiente 2, Base, Extra, Objetivo:
 * 
 * El recipiente 1 sera el que se ira llenando y quitando, mientras que B se llena y cuando este en su capacidad maxima, deberemos vaciarlo.
 * Cantidad asociada al recipiente 1 <- A
 * Cantidad asociada al recipiente 2 <- B
 *
 * Verificar que movamos una cantidad que no haga que uno de los recipientes se rebalse o que exceda la cantidad que tiene el mismo.
 * Repetir hasta que uno de los recipientes llegue a tener la cantidad C.
 * 
*/


int f(int r1, int r2, int A, int B, int C){
	if(r1 == C or r2 == C) return 0;
	int pasos = 0;
	int mover = min(r1,B-r2);
	r2 += mover;
	r1 -= mover;
	pasos++;
	if(r1 == C or r2 == C) return pasos;
	if(r2 == B) r2 = 0, pasos++;
	else if(r1 ==0) r1 = A, pasos++;
	return pasos+f(r1,r2,A,B,C);
}

int main(){
	int t;
	ri(t);
	int A,B,C;
	while(t--){
		ri3(A,B,C);
		if(A < C and B < C) puts("-1");
		else if(C == 0) puts("0");
		else if(C % gcd(A,B)) puts("-1");
		else{
			printf("%d\n",1+min(f(A,0,A,B,C),f(B,0,B,A,C)));
		}
	}
	return 0;
}
