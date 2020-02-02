// https://www.hackerrank.com/contests/projecteuler/challenges/euler035/problem

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n_digits(int n) {
    return floor(log10(n)) + 1;
}

int next_rotation(int n) {
    int last_digit = n % 10;
    return pow(10, n_digits(n)-1) * last_digit + n/10;
}

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
    auto is_prime = sieve(10*n);
    vector<int> primes = {};
    for (int i = 0; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }

    long sum = 0L;
    for (int i: primes) {
        auto rotation = i;
        int d = n_digits(i);
        bool valid = true;
        for(int j = 0; j < d; ++j) {
            if (!is_prime[rotation]) {
                valid = false;
                break;
            } 
            rotation = next_rotation(rotation);
        }
        if (valid)
            sum += i;
    }
    cout << sum << endl;
}