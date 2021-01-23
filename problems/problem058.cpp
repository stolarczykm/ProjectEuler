#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <utility>
#include <random>
using namespace std;
using ULL = unsigned long long;


bool is_prime(ULL n, const vector<ULL>& primes) {
    // if (n < sieve.size()) return sieve[n];
    for (ULL prime: primes) {
        if (n % prime == 0) return false;
        if (prime * prime > n) break;
    }
    return true;
};

ULL multiplication_modulo(ULL x, ULL y, const ULL& mod) {
    if (x < y) 
        return multiplication_modulo(y, x, mod);
    ULL res = 0;
    double log_mod = log2((double)mod);
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

// ULL multiplication_modulo(ULL x, ULL y, const ULL& mod) {
//     if (x < y) 
//         return multiplication_modulo(y, x, mod);
//     ULL res = 0;
//     while (y) {
//         if (y & 1)
//             res = (res + x) % mod;
//         x = (2 * x) % mod;
//         y >>= 1;
//     }
//     return res;
// }

ULL exponentation_by_squaring(ULL n, ULL p, const ULL& mod) {
    if (p == 0) return 1;
    ULL res = 1;
    while (p > 1) {
        if (p % 2 == 0) {
            p = p / 2;
        } else {
            res = multiplication_modulo(res, n, mod);
            p = (p-1) / 2;
        }
        n = multiplication_modulo(n, n, mod);
    }
    return multiplication_modulo(res, n, mod);
 
}


ULL rand_long() {
    ULL r1 = rand();
    ULL r2 = rand();
    return r1 * (ULL)RAND_MAX + r2;
}


bool miller_rabin_test(ULL n, ULL k) {
    ULL d = n - 1;
    ULL r = 0ULL;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    for (ULL i = 0; i < k; ++i) {
        auto a = (rand_long() % (n-4ULL)) + 2ULL;
        auto x = exponentation_by_squaring(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool continue_outer_loop = false;
        for (ULL j = 0; j < r-1; ++j) {
            x = multiplication_modulo(x, x, n);
            if (x == n-1) {continue_outer_loop = true; break;}
        }
        if (continue_outer_loop) continue;
        return false;
    }
    return true;
}



pair<vector<bool>, vector<ULL>> get_primes(ULL n) {
    vector<bool> is_prime = vector<bool>(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (ULL j=2; j*2 < is_prime.size(); ++j) {
        is_prime[j*2] = false;
    }

    for (ULL i = 3; i < is_prime.size(); i += 2) {
        if (!is_prime[i]) continue;

        for (ULL j=i; j*i < is_prime.size(); ++j) {
            is_prime[j*i] = false;
        }
    }

    vector<ULL> primes = {};
    for (ULL i = 0; i <= is_prime.size(); ++i) {

        if (is_prime[i]) primes.push_back(i);

    }
    return make_pair(is_prime, primes);
}



int main() {

    double target_fraction;
    cin >> target_fraction;
    auto start = time(NULL);
    auto p = get_primes(250000);
    auto primes = p.second;
    auto sieve = p.first;

    target_fraction /= 100.0;

    ULL n_primes = 3L, n_diagonal = 5L, side_length = 3L, side_length_square;

    while (double(n_primes) / double(n_diagonal) >= target_fraction) {
        side_length += 2;
        n_diagonal += 4;
        side_length_square = side_length*side_length;

        for (int i = 3; i >= 1; --i) {
            auto half_side_length = side_length / 2;
            if (i == 1 && side_length % 3 == 2) continue;
            if (i == 2 && (half_side_length % 5 == 4 || half_side_length % 5 == 1)) continue;
            if (
              i == 3 && (
                  half_side_length % 3 == 1 
                  || half_side_length % 7 >= 5
              )
            ) continue;

            auto n = side_length_square - (ULL)i * (side_length - 1);
            if (n < sieve.size()) {n_primes += sieve[n]; continue;};
            // if (!miller_rabin_test(n, 10)) {continue;};
            if (is_prime(n, primes))  {
                n_primes++;
            }
        }

        
    }

    cout << side_length << endl;
    cout << time(NULL) - start << endl;
    return 0;
}