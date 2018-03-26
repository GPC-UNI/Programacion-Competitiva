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

/* Planteamos la recursion para la altura h(n) y anchura w(n) segun la profundidad
 * Notamos que h(1) = 1, w(1) = 3
 * Ademas, por la forma del fractal:
 * h(n) = 2h(n)+1 y w(n) = 2w(n-1)+1
 * Concluimos que:
 * h(n) = 2^{n}-1
 * w(n) = 2^{n+1}-1
 * 
 * Supongamos una profundidad n del fractal:
 *
 * |--------------------------------------|
 * |                  |                   | 
 * |                  |                   |
 * |      F(n-1)      |       F(n-1)      |
 * |                  |                   |
 * |                  |                   |
 * |----------Fila de separacion----------|
 * |                  |                   |
 * |                  |                   |
 * |      F(n-1)      |       F(n-1)      |
 * |                  |                   |
 * |                  |                   |
 * |--------------------------------------| 
 *
 * Notamos que, si nuestra esquina superior izquierda tiene coordenadas (x,y)
 * entonces pondremos 4 fractales de profundidad (n-1) en las posiciones:
 * 
 * (x,y) ------ (x+dx,y) ------ (x,y+dy) ------ (x+dx,y+dy)
 *
 * Ahora la pregunta principal es el valor de dx y dy.
 *
 * Es sencillo notar que:
 * 
 * x+dx - x = h(n-1) + 2
 * dx = h(n-1)+2 = 2^{n-1}-1+2 = 2^{n-1}+1
 *
 * y+dy - y = w(n-1) + 2
 * dy = w(n-1)+2 = 2^{n}-1+2 = 2^{n}+1
 * 
 * Sin embargo, al estar trabajando con indexacion desde 0, deberemos disminuir en 1 cada coordenada
 * 
 * Ademas de ello, debemos conectar los puntos medios de los fractales horizonatles en la fila de separacion
 * 
 * Para esto, notamos que para la profundidad (n-1) se da la misma forma, por lo que
 *
 * |-----------------------------------------------------------------------------------------------------|
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |        F(n-2)          |          F(n-2)         |        F(n-2)          |          F(n-2)         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |----------------------F(n-1)----------------------|----------------------F(n-1)----------------------|
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |        F(n-2)          |          F(n-2)         |        F(n-2)          |          F(n-2)         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |-----------------------------------------------------------------------------------------------------|
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |        F(n-2)          |          F(n-2)         |        F(n-2)          |          F(n-2)         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |----------------------F(n-1)----------------------|----------------------F(n-1)----------------------|
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |        F(n-2)          |          F(n-2)         |        F(n-2)          |          F(n-2)         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |                        |                         |                        |                         |
 * |-----------------------------------------------------------------------------------------------------|
 * 
 * La ubicacion de la tuberia (|) izquierda sera a una distancia w(n-2)+1 relativo al y
 * 
 * pos_tuberia_izquierda = y + w(n-2)+1 - 1 = y + w(n-2) = y+2^{n-1}-1
 *
 * Y tambien la ubicacion de la tuberia derecha sera a una distancia w(n-2)+1 del final, el cual esta ubicado a una distancia de w(n)
 *
 * pos_tuberia_derecha = y + w(n) - w(n-2) - 1 = y+2^{n+1}-2^{n-1}-1
 * 
 * NOTA: El disminuir en 1 es por la indexacion en 0
 * 
 * Ahora, sabemos que la fila de separacion esta a una distancia dx-1, por lo que
 * fila_separacion = x + dx - 1 - 1 = x+dx-2
 * 
 * Por ultimo, los puntos que debemos conectar con tuberias de manera vertical serian:
 * fila_punto_superior = x + h(n-2)+1 - 1 = x+2^{n-2}-1+1-1 = x+2^{n-2}-1
 * fila_punto_inferior = x + h(n) - h(n-2) - 1 = x+2^{n}-1-2^{n-2}+1-1 = x+2^{n}-2^{n-2}-1
 *
 * Con esto nos basta para colocar los datos en nuestra matriz y procesar el fractal
*/  

const int HMAX = 1023 + 5;
const int WMAX = 2047 + 5;

char tabla[HMAX][WMAX];

int w(int n){
	return (1<<(n+1))-1;
}

int h(int n){
	return (1<<n)-1;
}

void f(int n, int x, int y){
	if(n == 1){
		tabla[x][y] = 'H';
		tabla[x][y+1] = '-';
		tabla[x][y+2] = 'H';
	}
	else{
		int dx = (1<<(n-1)) + 1;
		int dy = (1<<n) + 1;
		f(n-1,x,y);
		f(n-1,x+dx-1,y);
		f(n-1,x,y+dy-1);
		f(n-1,x+dx-1,y+dy-1);
		int pos_tuberia_izquierda = y + (1<<(n-1)) - 1;
		int pos_tuberia_derecha = y + (1<<(n+1)) - (1<<(n-1))-1;
		int fila_separacion = x+dx-2;
		int fila_punto_superior = x+(1<<(n-2))-1;
		int fila_punto_inferior = x+(1<<n) - (1<<(n-2))-1;
		for(int i=fila_punto_superior+1; i<fila_punto_inferior; i++){
			tabla[i][pos_tuberia_izquierda] = '|';
			tabla[i][pos_tuberia_derecha] = '|';
		}
		for(int i=pos_tuberia_izquierda+1; i<pos_tuberia_derecha; i++){
			tabla[fila_separacion][i] = '-';
		}
	}
}

int main(){
	int n;
	memset(tabla,' ', sizeof tabla); // Llenamos de espacios
	ri(n);
	f(n,0,0); // Recursion para el fractal
	for(int i=0; i<h(n); i++){
		int pos = WMAX-1;
		while(tabla[i][pos]==' '){
			pos--;
		}
		tabla[i][pos+1] = '\0'; // Para no imprimir espacios extra
	}
	for(int i=0; i<h(n); i++){
		printf("%s\n",tabla[i]);
	}
	return 0;
}
