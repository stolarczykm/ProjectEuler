// https://www.hackerrank.com/contests/projecteuler/challenges/euler037/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

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


long truncate_left(long n) {
    long t = pow(10, floor(log10(n)));
    return n - t * (n / t);
}

long truncate_right(long n) {
    return n / 10;
}


int main() {
    long n;
    cin >> n;

    auto is_prime = sieve(n);

    long sum = 0;
    for (int i = 10; i < n; ++i) {
        int k = i;
        bool valid = true;
        while (k > 0) {
            if (!is_prime[k]) {
                valid = false;
                break;
            }
            k = truncate_right(k);
        }

        if (!valid) continue;
        k = i;
        while (k > 0) {
            if (!is_prime[k]) {
                valid = false;
                break;
            }
            k = truncate_left(k);
        }
        if (!valid) continue;

        sum += i;
    }

    cout << sum << endl;

}