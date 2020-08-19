#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ULL = unsigned long long;

const ULL DIVISOR = 10000000000ULL;

ULL multiplication_modulo(ULL x, ULL y, const ULL& mod) {
    ULL res = 0;
    x %= mod;
    while (y) {
        if (y & 1)
            res = (res + x) % mod;
        x = (2 * x) % mod;
        y >>= 1;
    }
    return res;
}

ULL exponentation_by_squaring(ULL n, ULL p, const ULL& mod) {
    if (p == 0) return 1;
    ULL res = 1;
    while (p > 1) {
        if (p % 2 == 0) {
            n = multiplication_modulo(n, n, mod);
            p = p / 2;
        } else {
            res = multiplication_modulo(n, res, mod);
            n = multiplication_modulo(n, n, mod);
            p = (p-1) / 2;
        }
    }
    return multiplication_modulo(res, n, mod);
 
}


int main() {
    ULL n;
    cin >> n;

    ULL sum = 0LL;
    for (ULL i = 1; i <= n; ++i) {
        sum = (sum + exponentation_by_squaring(i, i, DIVISOR)) % DIVISOR;
    }
    cout << sum << endl;
    return 0;
}