// Solución seleccionada aleatoriamente del contest
// Solución de J_Ruegg

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <string> names(4, "");
    names[0] = "shata";
    names[1] = "hajar";
    names[2] = "lakh";
    names[3] = "kuti";
    vector <int> digits(4);
    
    digits[0] = 2;
    digits[1] = 1;
    digits[2] = 2;
    digits[3] = 2;
    
    vector <int> rDigits;
    
    string num;
    int caseNumber = 1;
    while(cin >> num) {
        string res = "";
        int i = num.size();
        int k = 0;
        while(i > 0)
        {
          i-=digits[k++];
          k%=4;
        }
        if(i == -1) num.insert(0, "0");
        
        i = num.size();
        k = 0;
        rDigits.clear();
        while(i > 0) {
            
            int tempNum = stoi(num.substr( num.size() - digits[k], digits[k]));
            rDigits.push_back(tempNum);
            
            
            for(int counter = 0; counter < digits[k]; counter++) {
                num.pop_back();
            }
            i-=digits[k];
            
            
            k++;
            k %= 4;
        }
        
        for(int j = rDigits.size() - 1; j > 0; j--) {
            if(j > 0 and j%4 == 0 and rDigits[j] == 0) res += " " + names[3];
            if(rDigits[j] == 0) continue;
            res += " " + to_string(rDigits[j]);
            res += " " + names[(j+3)%4];
        }
        if(rDigits[0] != 0 or rDigits.size() == 1) res += " " + to_string(rDigits[0]);
        
        cout << std::setw(4) << caseNumber++ << "." << res << endl;
    }
    
}

//’kuti’ (10000000), ’lakh’ (100000), ’hajar’ (1000), ’shata’ (100)
