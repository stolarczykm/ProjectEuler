// https://www.hackerrank.com/contests/projecteuler/challenges/euler023/problem

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
    int cache_limit = 100001;
    vector<map<int, int> > decomposiontions = {};
    for (int i = 2; i <= cache_limit; ++i) {
        decomposiontions.push_back(prime_decomposition(i));
    }

    vector< long > abundant_numbers = {};

    long max_ = 0;
    for (int i = 2; i <= cache_limit; ++i) {
        long sum_of_proper_divisors = sum_divisors(decomposiontions[i-2]) - i;
        if (sum_of_proper_divisors > i) {
            abundant_numbers.push_back({i});
        }
    }

    vector<bool> is_sum_of_abundant = vector<bool>(cache_limit, false);
    for (int i = 0; i < abundant_numbers.size(); ++i) {
        for(int j = i; j < abundant_numbers.size(); ++j) {
            auto sum = abundant_numbers[i] + abundant_numbers[j];
            
            if (sum >= is_sum_of_abundant.size()) 
                break;
            
            is_sum_of_abundant[sum] = true;
        }
    }

    
    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        long n;
        cin >> n;
        cout << (is_sum_of_abundant[n] ? "YES" : "NO") << endl;
    }

    return 0;
}
