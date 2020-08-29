#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;
using ULL = unsigned long long;


const ULL DIVISOR = 10000000000ULL;
const double LOG_DIVISOR = log2((double)DIVISOR);
const ULL T = 1ULL << 32;

ULL multiplication_modulo(ULL x, ULL y, const ULL& mod, const double& log_mod) {
    if (x < y) 
        return multiplication_modulo(y, x, mod, log_mod);
    ULL res = 0;
    double log_y = log2((double)y);
    while (y) {
        if (log_mod + log_y < 64) {
            x = (x * y) % mod;
            y = 1;
        }
        if (y & 1)
            res = (res + x) % mod;
        x = (2 * x) % mod;
        y >>= 1;
        log_y -= 1;
    }
    return res;
}

ULL exponentation_by_squaring(ULL n, ULL p, const ULL& mod, const double& log_mod) {
    if (p == 0) return 1;
    ULL res = 1;
    while (p > 1) {
        bool n_small = n < T;
        bool res_small = res < T;
        if (p % 2 == 0) {
            p = p / 2;
        } else {
            if (n_small & res_small) 
                res = (res * n) % mod;
            else 
                res = multiplication_modulo(res, n, mod, log_mod);
            p = (p-1) / 2;
        }
        if (n_small) 
            n = (n * n) % mod;
        else
            n = multiplication_modulo(n, n, mod, log_mod);
    }
    return multiplication_modulo(res, n, mod, log_mod);
 
}


int main2() {
    ULL n;
    // cin >> n;
    n = 2000000ULL;

    auto start = high_resolution_clock::now();
    ULL sum = 0LL;
    for (ULL i = 1; i <= n; ++i) {
        sum = (sum + exponentation_by_squaring(i, i, DIVISOR, LOG_DIVISOR)) % DIVISOR;
    }
    auto end = high_resolution_clock::now();
    cout << sum << endl;
    cout << duration_cast<milliseconds>(end - start).count() << endl;
    return 0;
}


int main() {
    ULL n;
    cin >> n;

    ULL sum = 0LL;
    for (ULL i = 1; i <= n; ++i) {
        sum = (sum + exponentation_by_squaring(i, i, DIVISOR, LOG_DIVISOR)) % DIVISOR;
    }
    cout << sum << endl;
    return 0;
}