// https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<long long> prime_sums(long n) {

    // Eratosthenes sieve
    vector<bool> is_prime = vector<bool>(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (long j=2; j*2 < is_prime.size(); ++j) {
        is_prime[j*2] = false;
    }

    for (long i = 3; i < is_prime.size(); i++) {
        if (!is_prime[i]) continue;

        for (long j=i; j*i < is_prime.size(); ++j) {
            is_prime[j*i] = false;
        }
    }

    vector<long long> sums = vector<long long>(n+1, 0);
    long long sum = 0;
    for (long i=2; i < sums.size(); ++i) {
        if (is_prime[i]) {
            sum += i;
        }
        sums[i] = sum; 
    }

    return sums;
}


int main(int argc, char const *argv[])
{
    vector<long long> sums = prime_sums(2000000L);
    int t = 3;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        long n;
        cin >> n;

        cout << sums[n] << endl;
    }
    return 0;
}
