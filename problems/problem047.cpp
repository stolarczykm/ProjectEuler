#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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


vector<long> get_primes(const vector<bool>& is_prime) {
    vector<long> primes = {};
    for (long i = 0; i < is_prime.size(); ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}


int main() {
    long n;
    int k;
    cin >> n >> k;

    const auto is_prime = sieve(n + k + 1);
    const auto primes = get_primes(is_prime);

    vector< unordered_map<long, int> > prime_decompositions = {};
    prime_decompositions.push_back({});
    prime_decompositions.push_back({});

    for (long i = 2; i <= n + k; ++i) {
        if (is_prime[i]) {
            unordered_map<long, int> decomposition = {make_pair(i, 1)};
            prime_decompositions.push_back(decomposition);
            continue;
        }         

        for (auto p : primes) {
            if (i % p == 0) {

                auto decomposition = prime_decompositions[i / p];
                auto it = decomposition.find(p);
                if (it == decomposition.end()) {
                    decomposition[p] = 1;
                } else {
                    decomposition[p]++;
                }
                prime_decompositions.push_back(decomposition);
                break;
            }
        }
    }

    for (long i = 2; i <= n; ++i) {
        bool all_match = true;
        for (long j = 0; j < k; ++j) {
            if (prime_decompositions[i+j].size() != k) {
                all_match = false;
                break;
            }
        }
        if (all_match) cout << i << endl;
    }
}