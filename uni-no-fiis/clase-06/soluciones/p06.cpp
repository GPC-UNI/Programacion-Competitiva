#include <bits/stdc++.h>

#define SIZE 10
#define LIM 1010

using namespace std;

int nt, nd, ct;
char number[SIZE];
vector <pair<char,int>> aux;
pair <char,int> ss;

char look_and_say_sequence(string s, int pos, int digit){
	while (--pos) {
		aux.clear();
		for (int i = 0; i < s.size() && i < LIM; ){
			ss.first = s[i], ct = 0;
			for (; i < s.size() && i < LIM; i++)
				if (ss.first==s[i]) ct++;
				else break;
			ss.second = ct;
			aux.push_back(ss);
		}
		s = "";
		for(int i = 0; i < aux.size(); i++){
			s += to_string(aux[i].second);
			s += aux[i].first;
		}
	}
	return s[digit - 1];
}

int main(){
    while (scanf("%s %d %d\n", number, &nt, &nd), number[0]!=0 && nt && nd)
		printf("%c\n", look_and_say_sequence(string(number), nt, nd));
	return(0);
}

