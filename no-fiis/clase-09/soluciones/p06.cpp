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

/* Como lo usual, para analizar el fractal primero planteamos recursiones para
 * ancho y alto:
 * h(n) = 2h(n-1)
 * w(n) = 2w(n-1)
 * Donde h(1) = 2 y w(1) = 4
 * Entonces
 * h(n) = 2^{n}
 * w(n) = 2^{n+1}
 * Luego, nos es sencillo notar que es mas facil fijar el (x,y) no en el centro,
 * sino en donde colocamos el primer '/' para formar el triangulo.
 * En este caso, la primera llamada sera f(d,n,0,2^{n}-1) por la indexacion en 0
 * Ademas, como son solo 10 profundidades, podriamos almacenar todas estas en una tabla, para no tener que volver a crear el fractal y simplemente imprimirlo. (de esto se encarga d que va a ser fijo siempre)
 * Para ello creamos un array de booleanos llamado done[N], donde done[i] 
 * dira si es que la profundidad i ya se proceso, con el fin de usar respuestas
 * ya hechas.
 * 
 * Regresando al momento de llenar el fractal, notamos que:
 * 
 * El fractal de profundidad n tiene 3 fractales de profundidad n-1:
 * Uno con la misma posicion, otro a la izquierda y otro a la derecha.
 * Es sencillo notar que sus distancias son dx = h(n-1) y dy = w(n-1)/2, entonces
 * Llenamos los fractales con n > 1 de la siguiente manera:
 * f(d,n-1,x,y)
 * f(d,n-1,x+dx,y-dy)
 * f(d,n-1,x+dx,y+dy)
 * Donde dx = 1<<(n-1) y dy = 1<<(n-1)
 * 
*/

const int MAX_DEPTH = 11;
const int MAX_ROW = 1030;
const int MAX_COL = 2050;

bool done[MAX_DEPTH];
char tabla[MAX_DEPTH][MAX_ROW][MAX_COL];

void f(int depth, int n, int x, int y){
	if(n == 1){
		tabla[depth][x][y] = '/';
		tabla[depth][x][y+1] = '\\';
		tabla[depth][x+1][y-1] = '/';
		tabla[depth][x+1][y+2] = '\\';
		tabla[depth][x+1][y] = tabla[depth][x+1][y+1] = '_';
	}
	else{
		int dy = (1<<(n-1));
		int dx = (1<<(n-1));
		f(depth,n-1,x+dx,y-dy);
		f(depth,n-1,x+dx,y+dy);
		f(depth,n-1,x,y);
	}
}

int main(){
	int n;
	while(ri(n) and n){
		if(done[n]){
			for(int i=0; i<(1<<n); i++){
				printf("%s\n",tabla[n][i]);
			}
		}
		else{
			memset(tabla[n],' ', sizeof tabla[n]);
			f(n,n,0,(1<<n)-1);
			for(int i=0; i<(1<<n); i++){
				int pos = MAX_COL-1;
				while(tabla[n][i][pos]==' '){
					pos--;
				}
				tabla[n][i][pos+1] = '\0';
			}
			for(int i=0; i<(1<<n); i++) printf("%s\n",tabla[n][i]);
			done[n] = true;
		}
		puts("");
	}
	return 0;
}
