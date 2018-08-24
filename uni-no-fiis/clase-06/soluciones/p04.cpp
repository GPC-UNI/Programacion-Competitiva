#include <bits/stdc++.h>

#define LIM 40000

using namespace std;

int tc, lo, hi;
vector <int> Kaprekar_number;
bool ok;

bool check(int num, int sum) {
	int _left,_right,pib=1;
	_left = num, _right = 0;
	while (_left) {
		_right += pib * (_left % 10);
		_left /= 10;
		if(_left + _right == sum && _left * _right) return true;
		pib *= 10;
	}
	return false;
}

int main(){
	for(int it = 1; it < LIM; it++)
		if (check(it * it, it)) Kaprekar_number.push_back(it);
	scanf("%d", &tc);
	for(int t = 1; t <= tc; t++){
		ok = true;
		scanf("%d %d", &lo, &hi);
		printf("case #%d\n", t);
		for(int it = 0; it < Kaprekar_number.size(); it++)
			if(lo <= Kaprekar_number[it] && Kaprekar_number[it] <= hi)
				printf("%d\n", Kaprekar_number[it]), ok = false;
		if (ok) puts("no kaprekar numbers");
		if (t != tc) putchar('\n');
	}
	return(0);
}

