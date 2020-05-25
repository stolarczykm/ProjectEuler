// https://www.hackerrank.com/contests/projecteuler/challenges/euler043/problem

#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const vector<int> PRIMES = {2, 3, 5, 7, 11, 13, 17};


long long digits_to_number(vector<int> digits, int start = 0, int end = -1) {
    if (end == -1) end = digits.size();
    long long result = 0LL;
    for (int i = start; i < end; ++i) {
        result *= 10;
        result += digits[i];
    }
    return result;
}

vector< vector<int> > get_pandigitals(int n_digits) {
    vector< vector< int > > results = {};
    vector<int> digits = {};
    for (int i = 0; i < n_digits; ++i) {
        digits.push_back(i);
    }
    do {
        results.push_back(vector<int>(digits));
    } while (next_permutation(digits.begin(), digits.end()));
    return results;
};

int main() {
    int t;
    cin >> t;
    auto pandigitals = get_pandigitals(t+1);
    long long sum = 0LL;
    for (auto pandigital: pandigitals) {
        bool has_property = true;
        
        for (int i = 0; i < t - 2; ++i) {
            auto number = digits_to_number(pandigital, i+1, i+4);
            if (number % PRIMES[i] != 0) {
                has_property = false;
                break;
            }
        }
        if (has_property) {
            auto number = digits_to_number(pandigital);
            sum += number;
        };
    }
    cout << sum << endl;
    

}