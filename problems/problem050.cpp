#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(const long long& n) {
    vector<bool> is_prime = vector<bool>(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long j=2; j*2 < is_prime.size(); ++j) {
        is_prime[j*2] = false;
    }

    for (long long i = 3; i < is_prime.size(); i += 2) {
        if (!is_prime[i]) continue;

        for (long long j=i; j*i < is_prime.size(); ++j) {
            is_prime[j*i] = false;
        }
    }
    return is_prime;
}

vector<long long> get_primes(const vector<bool>& is_prime) {
    vector<long long> primes = {};
    for (long long i = 0; i < is_prime.size(); ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}


vector<long long> cumsum(const vector<long long>& vec) {
    vector<long long> res = {0LL};
    long long sum = 0LL;
    for (auto value: vec) {
        sum += value;
        res.push_back(sum);
    }
    return res;
}

template<typename T>
T bin_search_left(const vector<T>& x, T& element, long left=0, long right=-1) {
    if (right == -1) 
        right = x.size();
    if (right - left < 1) 
        return left-1;

    long middle = left + (right - left) / 2;

    if (x[middle] == element) {
        return middle;
    }

    if (element < x[middle]) {
        return bin_search_left(x, element, left, middle);
    }

    return bin_search_left(x, element, middle + 1, right);
}

bool check_is_prime(long long number, const vector<bool>& is_prime, const vector<long long>& primes) {
    if (number < is_prime.size())
        return is_prime[number];

    for (auto prime: primes) {
        if (number % prime == 0) 
            return false;
    }

    return true;

}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    auto is_prime = sieve(10000000LL);
    auto primes = get_primes(is_prime);
    auto cum_primes = cumsum(primes);


    for (int t0 = 0; t0 < t; ++t0) {
        long long n;
        cin >> n;

        auto k = bin_search_left(cum_primes, n);

        long longest = 0;
        long prime_sum = 0;
        for (long j = 0; j < k; ++j) {
            for (long i = k + 3; i >= j; --i) {
                auto diff = cum_primes[i] - cum_primes[j];
                if (diff > n) continue;
                if (i - j < longest) break;
                if (i - j > longest && check_is_prime(diff, is_prime, primes) ) {
                    longest = i - j;
                    prime_sum = diff;
                } 
            }
        }
        cout << prime_sum << " "  << longest << endl;
    }
    return 0;
}
