// https://www.hackerrank.com/contests/projecteuler/challenges/euler021/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


map<int, int> prime_decomposition(int n) {
    map<int, int> decomposition = map<int, int>();

    for (int p = 2; p*p <= n & n > 1; ++p) {
        int cnt = 0;
        while (n % p == 0) {
            n = n / p;
            ++cnt;
        }
        if (cnt > 0) {
            decomposition[p] = cnt;
        }
    }

    if (n > 1) decomposition[n] = 1;

    return decomposition;
}


long sum_divisors(map<int, int>& decomposition) {
    if (decomposition.size() == 0) return 1;
    
    auto first = decomposition.begin();
    auto key = first->first;
    auto value = first->second;

    long sum_of_powers = 0L;
    long power = 1;
    for (int i = 0; i <= value; ++i) {
        sum_of_powers += power;
        power *= key; 
    }
    decomposition.erase(key);    

    return sum_of_powers * sum_divisors(decomposition);
}

int main() {
    int cache_limit = 260000;
    vector<map<int, int> > decomposiontions = {};
    for (int i = 2; i <= cache_limit; ++i) {
        decomposiontions.push_back(prime_decomposition(i));
    }

    vector< long > sum_of_proper_divisors = {};
    sum_of_proper_divisors.push_back(0);
    sum_of_proper_divisors.push_back(0);

    long max_ = 0;
    for (int i = 2; i <= cache_limit; ++i) {
        sum_of_proper_divisors.push_back(sum_divisors(decomposiontions[i-2]) - i);
        max_ = max(sum_of_proper_divisors[sum_of_proper_divisors.size() - 1], max_);
    }

    vector<bool> is_amicable = {};
    for (int i = 0; i <= cache_limit; ++i) {
        auto next = sum_of_proper_divisors[i];
        if (next != i && next <= cache_limit && sum_of_proper_divisors[next] == i) {
            is_amicable.push_back(true);
        } else {
            is_amicable.push_back(false);
        }
    }

    vector<long> sums = {};
    long sum = 0L;
    for (int i = 0; i <= is_amicable.size(); ++i) {
        sums.push_back(sum);
        if (is_amicable[i]) sum += i;
    }
    
    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        long n;
        cin >> n;
        cout << sums[n] << endl;
    }

    return 0;
}
