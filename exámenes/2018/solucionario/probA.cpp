/**
* By: Rmg_91
*/
#include <iostream>
using namespace std;

int main(){
  int n, sd = 0;
  cin >> n;
  for( int i = 1; i < n; ++i ){
    if( n % i == 0 ) sd += i;
  }
  if( n == sd ) cout << "SI";
  else cout << "NO";
  return 0;
}
