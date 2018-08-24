#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    int num, den;
    Fraction() {}
    Fraction(const int& _num, const int& _den):
        num(_num), den(_den) {}
    bool operator < (const Fraction& other) const {
        return num * other.den < den * other.num;
    }
    inline void print() const {
        cout << num << "/" << den << endl;
    }
};

int n, k;

int main() {
    while (cin >> n >> k) {
        vector <Fraction> arr;
        for (int den = 1; den <= n; den++)
            for (int num = 1; num <= den; num++)
                // __gcd(a, b) = mcm(a, b)
                if (__gcd(num, den) == 1)
                    arr.push_back(Fraction(num, den));
        // Como solo queremos una posicion en el array ordenado
        nth_element(begin(arr), begin(arr) + k - 1, end(arr));
        // Aunque tambien podemos usar sort()
        arr[k - 1].print();
    }
    return (0);
}
