// https://www.hackerrank.com/contests/projecteuler/challenges/euler027/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<bool> sieve(long n) {
    vector<bool> is_prime = vector<bool>(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (long j=2; j*2 < is_prime.size(); ++j) {
        is_prime[j*2] = false;
    }

    for (long i = 3; i < is_prime.size(); i += 2) {
        if (!is_prime[i]) continue;

        for (long j=i; j*i < is_prime.size(); ++j) {
            is_prime[j*i] = false;
        }
    }
    return is_prime;
}


int main() {
    int n;
    cin >> n;

    auto is_prime = sieve(10000000);

    int max_primes = -1;
    int best_a, best_b;
    for (int b = -n; b <= n; ++b) {
        if (!is_prime[abs(b)]) continue;

        for (int a = -n; a <= n; ++a) {
            long t = b;
            int i = 0;
            while (is_prime[abs(t)]) {
                t = i*i + a*i + b;
                ++i;
            }
            if (i-1 > max_primes) {
                max_primes = i-1;
                best_a = a;
                best_b = b;
            }
        }

    }
    cout << best_a << " " << best_b << endl;
    return 0;
}