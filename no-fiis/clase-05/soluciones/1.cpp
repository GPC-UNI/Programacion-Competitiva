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

struct Punto{
	int x;
	int y;
	Punto(){};
	Punto(int _x, int _y){x=_x; y=_y;}

	bool operator <(const Punto &b){
		return x<b.x or x==b.x and y<b.y;
	}
};

Punto v[5];

bool square(){

	// Lados iguales y producto interno de los vectores direccion de los lados igual a 0

	int L[5];
	L[0] = (v[0].x-v[1].x)*(v[0].x-v[1].x) + (v[0].y-v[1].y)*(v[0].y-v[1].y);
	L[1] = (v[0].x-v[2].x)*(v[0].x-v[2].x) + (v[0].y-v[2].y)*(v[0].y-v[2].y);
	L[2] = (v[3].x-v[1].x)*(v[3].x-v[1].x) + (v[3].y-v[1].y)*(v[3].y-v[1].y);
	L[3] = (v[3].x-v[2].x)*(v[3].x-v[2].x) + (v[3].y-v[2].y)*(v[3].y-v[2].y);
	for(int i=1; i<4; i++){
		if(L[i] != L[0]) return false;
	}
	int m1n = v[0].y - v[1].y;
	int m1d = v[0].x - v[1].x;
	int m2n = v[1].y - v[3].y;
	int m2d = v[1].x - v[3].x;
	int m3n = v[2].y - v[3].y;
	int m3d = v[2].x - v[3].x;
	int m4n = v[0].y - v[2].y;
	int m4d = v[0].x - v[2].x;
	
	int producto = (v[1].x - v[0].x)*(v[2].x-v[0].x) + (v[1].y - v[0].y)*(v[2].y-v[0].y);
	if(producto != 0) return false;
	return m1n*m3d == m1d*m3n and m2n*m4d == m2d*m4n;
}

bool rectangle(){

	// Producto interno de lados opuestos igual a 0

	int m1n = v[0].y - v[1].y;
	int m1d = v[0].x - v[1].x;
	int m2n = v[1].y - v[3].y;
	int m2d = v[1].x - v[3].x;
	int m3n = v[2].y - v[3].y;
	int m3d = v[2].x - v[3].x;
	int m4n = v[0].y - v[2].y;
	int m4d = v[0].x - v[2].x;
	int producto = (v[1].x - v[0].x)*(v[2].x-v[0].x) + (v[1].y - v[0].y)*(v[2].y-v[0].y);
	if(producto != 0) return false;
	return m1n*m3d == m1d*m3n and m2n*m4d == m2d*m4n;
}

bool rhombus(){

	// Lados iguales

	int L[5];
	L[0] = (v[0].x-v[1].x)*(v[0].x-v[1].x) + (v[0].y-v[1].y)*(v[0].y-v[1].y);
	L[1] = (v[0].x-v[2].x)*(v[0].x-v[2].x) + (v[0].y-v[2].y)*(v[0].y-v[2].y);
	L[2] = (v[3].x-v[1].x)*(v[3].x-v[1].x) + (v[3].y-v[1].y)*(v[3].y-v[1].y);
	L[3] = (v[3].x-v[2].x)*(v[3].x-v[2].x) + (v[3].y-v[2].y)*(v[3].y-v[2].y);
	for(int i=1; i<4; i++){
		if(L[i] != L[0]) return false;
	}
	return true;
}

bool parallelogram(){

	// Todos los lados opuestos paralelos

	int m1n = v[0].y - v[1].y;
	int m1d = v[0].x - v[1].x;
	int m2n = v[1].y - v[3].y;
	int m2d = v[1].x - v[3].x;
	int m3n = v[2].y - v[3].y;
	int m3d = v[2].x - v[3].x;
	int m4n = v[0].y - v[2].y;
	int m4d = v[0].x - v[2].x;
	return m1n*m3d == m1d*m3n and m2n*m4d == m2d*m4n;
}

bool trapezium(){
	
	// Dos lados paralelos y los otros no

	bool can = false;
	do{
		int m1n = v[0].y - v[1].y;
		int m1d = v[0].x - v[1].x;
		int m2n = v[1].y - v[3].y;
		int m2d = v[1].x - v[3].x;
		int m3n = v[2].y - v[3].y;
		int m3d = v[2].x - v[3].x;
		int m4n = v[0].y - v[2].y;
		int m4d = v[0].x - v[2].x;
		can = can || m1n*m3d == m1d*m3n or m2n*m4d == m2d*m4n;
		if(can) return true;
	}while(next_permutation(v,v+4));
	return false;
}

string solve(){
	sort(v,v+4);
	if(square()) return "Square";
	if(rectangle()) return "Rectangle";
	if(rhombus()) return "Rhombus";
	if(parallelogram()) return "Parallelogram";
	if(trapezium()) return "Trapezium";
	return "Ordinary Quadrilateral";
}

int main(){
	int t;
	ri(t);
	int x,y;
	int caso = 1;
	while(t--){
		for(int i=0; i<4; i++){
			ri2(x,y);
			v[i] = Punto(x,y);
		}
		printf("Case %d: %s\n",caso++,solve().c_str());
	}
	return 0;
}
