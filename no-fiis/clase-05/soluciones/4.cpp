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

/* Para formar paralelogramos, nos basta con fijar 2 puntos y sumar la cantidad
 * de pares de puntos que tengan como punto medio el punto medio de los dos ya
 * fijados, y que ademas no pertenezcan a la misma recta.
 * Expresado, seria:
 * Suma (i,j) = Cantidad(punto_medio(Punto i, Punto j)) - Cantidad(Recta(i,j) que pasen por el punto_medio(Punto i, Punto j))
 * Sin embargo, como no hay 3 colineales, entonces la cantidad de rectas total seria igual a la cantidad de parejas que hay.
 * Por lo tanto, si hacemos una suma sobre i < j
 *
 * Al final la cantidad de rectas total seria n*(n-1)/2, mientras que los puntos
 * medios son calculables con preprocesamiento
 *
 * Finalmente, darnos cuenta de que contamos todos los pares que cumplan para (i < j)
 * Pero, si estos son (a < b), entonces contariamos el mismo paralelogramo 2 veces
 * Cuando tenemos i,j y cuando tenemos a,b. Por lo tanto nuestra respuesta es dividida entre 2.
*/

const int N = 2000+5;

typedef pair<double,double> Punto;
typedef pair<ii,pll> Recta;
typedef pair<Recta,Punto> M;

int n;
int X[N], Y[N];
map<Punto,int> v;
vector< vector<Punto> > OP;
vector< vector<Recta> > OR;
vector<int> Q;
vector<Punto> w;

void Print(Punto a){
	cout << a.first << ", " << a.second << endl;
}

void Print2(Recta a){
	cout << a.first.first << "/" << a.first.second << endl;
	cout << a.second.first << "/" << a.second.second << endl;
}

int main(){
	ri(n);
	OP.resize(n);
	OR.resize(n);
	for(int i=0; i<n; i++){
		OP[i].resize(n);
		OR[i].resize(n);
		ri2(X[i],Y[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			double Px = 1.0*(X[i]+X[j])/2.0;
			double Py = 1.0*(Y[i]+Y[j])/2.0;
			int a = X[i]-X[j];
			int b = Y[i]-Y[j];
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
			ll num = 1LL*Y[i]*a-1LL*X[i]*b;
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
			Punto carry = mp(Px,Py);
			Recta carry2 = mp(mp(a,b),mp(num,den));
			OP[i][j] = carry;
			OR[i][j] = carry2;
			v[carry] += 1;
		}
	}
	ll ans = -1LL*n*(n-1)/2;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ans += v[OP[i][j]];
		}
	}
	printf("%lld\n",ans>>1LL);
	return 0;
}
