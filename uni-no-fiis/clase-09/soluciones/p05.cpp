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

/* Se puede resolver este problema con pilas, sale de manera lineal y es sencillo.
 * El enfoque con recursion es el siguiente:
 * 
 * Si tengo el rango [l,r] de la cadena S, entonces basta con probar si algun i
 * cumple con que S[l,i] esta balanceado y S[i+1,r] esta balanceado tambien,
 * en tal caso S[l,r] estaria correctamente balanceado. Iniciamos con toda la cadena
 * Suponiendo que la funcion que nos dice si esta bien balanceado o no es can(l,r)
 * Llamamos primero can(0,n-1).
 *
 * Sin embargo, este metodo daria TLE, pues faltan considerar optimizaciones:
 *
 * 1) Debemos asegurarnos de que cuando fijemos i, los extremos sean coherentes,
 * es decir, que S[l] + S[i] sea igual a "[]" o "()", para S[i+1] y S[r] NO nos 
 * interesa puesto que no sabemos donde vamos a cortar en ese rango, solo 
 * hemos fijado para el primer rango.
 * 
 * 2) Con lo anterior no basta, asi que tambien nos fijamos que S[i+1] sea un simbolo de apertura, S[i+1] == '(' o S[i+1] == '['
 * 
 * 3) Aun podemos optimizar mas, dandonos cuenta de que una cadena bien balanceada debe tener longitud par, poner condicion (r-l+1) %2 debe ser 0 o automaticamente se vuelve falsa la expresion
 *
 * 4) Debido a la optimizacion anterior, no tomamos todos los i, sino los i tales que sean i = l+2k-1, para que la distancia entre i y l sea par. Claro esta que consideramos el caso en el que S[l]+S[r] == "[]" o S[l]+S[r] == "()" aparte
 *
 * 5) Si l+1 == r es un caso base, en el cual debe ser un "[]" o "()" para que sea verdadero. Otro caso base podria ser l >= r  que automaticamente es falso, pero eso no lo analizamos mucho puesto que ya se considera al momento de verificar la longitud de la cadena
 * 
 * Motivos por los cuales daria WA:
 *
 * - Dado que nos mencionan que la cadena vacia tambien puede ser balanceada, no
 * debemos olvidar el caso en que nos den una. Usar cin malogra el proceso, pues
 * no reconoce cadenas vacias. Usar getline en C++.
 *
*/

int n;
int abre[300];
string s;

bool can(int l, int r){
	if((r-l+1)&1) return false;
	if(s[l] == ')' or s[l] == ']' or s[r] == '(' or s[r] == '[') return false;
	if(l >= r) return false;
	if(l+1 == r) return abre[s[r]] == s[l];
	if(s[l] == abre[s[r]]){
		if(can(l+1,r-1)) return true;
	}
	for(int i=l+1; i<r; i+=2){
		if(i+1 <= r){
			if(s[l] == abre[s[i]] and (s[i+1] == '(' or s[i+1] == '[')){
				if(can(l,i) and can(i+1,r)) return true;
			}
		}
	}
	return false;
}

int main(){
	abre[')'] = '(';
	abre[']'] = '[';
	int t;
	ri(t);
	getchar();
	while(t--){
		getline(cin,s);
		n = s.size();
		puts(can(0,n-1) or n == 0?"Yes":"No");
	}
	return 0;
}
