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

/* F(i) es igual al digito de i que no sea 0 y que sea del menor orden posible.
 * Dado esto, separamos el problema en:
 * 
 * G(i) = suma para k=0 hasta i de F(k)
 * 
 * Entonces S(p,q) = G(q) - G(p-1)
 * 
 * Ahora, para calcular G(i) nos damos cuenta de que es cuestion de recorrer orden
 * por orden:
 * 
 * Para G(n):
 *
 * Supongamos que estamos en el orden k, entonces notamos que si los digitos a la izquierda son menores estrictos que los digitos de n,
 * entonces en el orden k podemos poner el digito que queramos y el numero
 * formado sera menor que n siempre.
 * Ahora, tambien, para que este digito en el orden k sea el que aporte a G(n),
 * todos los digitos a su derecha deben ser 0, por la definicion de F(n):
 * 
 * Entonces, sumamos 45*(n/(10^{k+1})) al valor, pero ahora debemos considerar
 * el unico caso que nos falta, que es cuando los digitos a la izquierda son los
 * mismos que los de n.
 * Este caso es mas sencillo, pues nos damos cuenta de que la condicion para que
 * sea menor o igual a n es que el digito de orden k sea como maximo n_{k} (digito de n en el orden k), por lo que aporta (n_{k})(n_{k+1})/2.
 *
 * Usando esto, es sencillo calcular la respuesta.
 * 
*/

int p,q;

ll G(int x){
	if(x == 0) return 0LL;
	ll suma = 45LL*(x/10);
	suma += (x%10)*(x%10+1)/2;
	return suma + G(x/10);
}

int main(){
	while(ri2(p,q) and p+q >= 0){
		printf("%lld\n",G(q)-G(p-1));
	}
	return 0;
}
