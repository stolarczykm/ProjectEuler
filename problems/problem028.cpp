// https://www.hackerrank.com/contests/projecteuler/challenges/euler028/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


long long modulo(long long x, long long mod) {
    if (x < 0) {
        return x % mod + mod;
    }
    return x % mod;

}


int main() {
    int t;
    cin >> t;

    auto a = modulo(-3, 10);

    long long mod = 1000000007;
    long long mod2 = 3 * mod;
    for (int t0 = 0; t0 < t; ++t0) {
        long long  n;
        cin >> n;
        long long N = ((n+1) / 2) % mod2;
        long long result = modulo((
            modulo(4 * modulo(modulo(N  * modulo(2*N + 1, mod2), mod2) * modulo(2*N - 1, mod2), mod2), mod2)  / 3
            - 6 * modulo(modulo(N-1, mod2) * N, mod2)  - 3
        ), mod);
        cout << result << endl;
    }
}


