// https://www.hackerrank.com/contests/projecteuler/challenges/euler041/problem

#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



bool is_prime(long long n) {
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
};

long long digits_to_number(vector<int> digits) {
    long long result = 0LL;
    for (auto digit: digits) {
        result *= 10;
        result += digit;
    }
    return result;
}

vector<long long> get_prime_pandigitals(int n_digits) {
    vector<long long> results = {};
    vector<int> digits = {};
    for (int i = 1; i <= n_digits; ++i) {
        digits.push_back(i);
    }
    do {
        auto number = digits_to_number(digits);
        if (is_prime(number)) results.push_back(number);
    } while (next_permutation(digits.begin(), digits.end()));
    return results;
};

long long get_lower_element(vector<long long> x, long long value, int left = 0, int right=-1) {
    if (right == -1) right = x.size();
    if (right <= left + 1 && x[left] <= value) return left;
    if (right <= left + 1 && x[left] > value) return left - 1;

    auto middle = left + (right - left) / 2;
    if (x[middle] == value) {
        return middle;
    }
    if (x[middle] > value) {
        return get_lower_element(x, value, left, middle);
    }
    return get_lower_element(x, value, middle+1, right);
}

int main() {
    // Only 4 and 7 digit numbers can be pandigital and prime. Sum of digits of 
    // n-digit pandigital number is divisible by 3 for each n in 
    // {2, 3, 5, 6, 8, 9}, so the pandigital won't be prime. 
    auto p = get_prime_pandigitals(7);
    auto p2 = get_prime_pandigitals(4);
    p.insert(p.end(), p2.begin(), p2.end());
    sort(p.begin(), p.end());

    long t;
    cin >> t;
    for (int t0 = 0; t0 < t; ++t0) {
        long long n;
        cin >> n;
        auto x = get_lower_element(p, n);

        cout << (x >= 0 ? p[x] : -1) << endl;
    }
}