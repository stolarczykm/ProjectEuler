#include <iostream>
#include <vector>

using namespace std;


vector<bool> sieve(const long& n) {
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
    auto is_prime = sieve(500000LL);
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int ways = 0;
        int j = 1;
        int t = n - 2 * j*j;
        while (t > 0) 
        {
            if (is_prime[t]) ++ways;
            ++j;
            t = n - 2 * j*j;
        }
        cout << ways << endl;
    }

    return 0;
}