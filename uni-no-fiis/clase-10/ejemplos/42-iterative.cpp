#include <bits/stdc++.h>

using namespace std;

vector <string> ans;

int sum(string s) {
    int ret = 0;
    for (char ch : s) ret += ch - 'a' + 1;
    return ret;
}

void generate(string s) {
    do {
        ans.push_back(s);
    } while (next_permutation(begin(s), end(s)));
}

int main() {
    string s = "";
    for (char ch_1 = 'a'; ch_1 <= 'z'; ch_1++) {
        s += ch_1;
        for (char ch_2 = ch_1; ch_2 <= 'z'; ch_2++) {
            s += ch_2;
            if (sum(s) == 42) generate(s);
            if (sum(s) < 42) {
                for (char ch_3 = ch_2; ch_3 <= 'z'; ch_3++) {
                    s += ch_3;
                    if (sum(s) == 42) generate(s);
                    if (sum(s) < 42) {
                        for (char ch_4 = ch_3; ch_4 <= 'z'; ch_4++) {
                            s += ch_4;
                            if (sum(s) == 42) generate(s);
                            if (sum(s) < 42) {
                                for (char ch_5 = ch_4; ch_5 <= 'z'; ch_5++) {
                                    s += ch_5;
                                    if (sum(s) == 42) generate(s);
                                    if (sum(s) < 42) {
                                    	for (char ch_6 = ch_5; ch_6 <= 'z'; ch_6++) {
                                    		s += ch_6;
                                    		if (sum(s) == 42) generate(s);
                                    		if (sum(s) < 42) {
                                    			for (char ch_7 = ch_6; ch_7 <= 'z'; ch_7++) {
                                    				s += ch_7;
                                    				if (sum(s) == 42) generate(s);
                                    				s.pop_back();
                                    			}
                                    		}
                                    		s.pop_back();
                                    	}
                                    }
                                    s.pop_back();
                                }
                            }
                            s.pop_back();
                        }
                    }
                    s.pop_back();
                }
            }
            s.pop_back();
        }
        s.pop_back();
    }
    sort(begin(ans), end(ans));
	for (string ans_i : ans) cout << ans_i << endl;
    return (0);
}
