// https://www.hackerrank.com/contests/projecteuler/challenges/euler033/problem

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int greatest_common_divisor(int a, int b) {
    if (b == 0) return a;
    return greatest_common_divisor(b, a % b);
}

vector<int> get_common_divisors(int a, int b) {
    auto res = vector<int>();
    int gcd = greatest_common_divisor(a, b);
    for (int i = 2; i*i <= gcd; ++i) {
        if (gcd % i == 0) {
            res.push_back(i);
            if (i * i != gcd) {
                res.push_back(gcd / i);
            }
        }
    }
    if (gcd > 1) res.push_back(gcd);
    return res;
}

vector<int> get_digits(int n) {
    if (n == 0) return {0};
    auto res = vector<int>{};
    while (n > 0) {
        res.push_back(n % 10);
        n = n / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool is_in(const int &element, const set<int> &set) {
    return set.find(element) != set.end();
}

set<int> remove(const int &element, const set<int> &set_) {
    set<int> new_set = {}; 
    for (auto x: set_) {
        if (x != element) new_set.insert(element);
    }
    return new_set;
}

vector<int> nubmers(const vector<int> &digits, const set<int> &digits_to_remove, int start = 0) {
    auto res = 0;
    auto res_numbers = vector<int>(0);
    for (int i = start; i < digits.size(); ++i) {
        if (is_in(digits[i], digits_to_remove)) {
            auto numbers_with_removed_digit = nubmers(digits, remove(digits[i], digits_to_remove), i+1);
            for (auto n: numbers_with_removed_digit) {
                res_numbers.push_back(res * pow(10, digits_to_remove.size() - 1) + n);
            }
        }
        res = res * 10 + digits[i];
    }
    if (digits_to_remove.size() == 0) {
        res_numbers.push_back(res);
    }
    return res_numbers;
}


tuple<long, long> solve(int n, int k) {
    long sum_num=0, sum_den=0;
    for (int i = pow(10, n-1); i < pow(10, n); ++i) {
        auto digits_i = get_digits(i);
        for (int j = i + 1; j < pow(10, n); ++j) {
            if (greatest_common_divisor(i, j) == 1) {
                continue;
            }
            auto digits_j = get_digits(j);
            vector<int> digits_both = vector<int>(digits_i.size());
            auto it = set_intersection(
                digits_i.begin(), digits_i.end(),
                digits_j.begin(), digits_j.end(),
                digits_both.begin()
            );
            digits_both.resize(it - digits_both.begin());

            if (digits_both.size() < k) {
                continue;
            }
            if (i == 49 && j == 98) {
                // cout << i << " " << j << endl;
            }
            for (int m = 0; m < digits_both.size(); ++m) {
                if (digits_both[m] == 0) {
                    continue;
                }
                set<int> digits_to_remove = {digits_both[m]};
                auto reduced_i = nubmers(digits_i, digits_to_remove);
                auto reduced_j = nubmers(digits_j, digits_to_remove);

                for (auto ri: reduced_i) for (auto rj: reduced_j) {
                    if (ri * j == rj * i) {
                        sum_num += i;
                        sum_den += j;
                        // cout << i << " " << j << endl;
                        break;
                    }
                }
            }
        }
    }
    return make_tuple(sum_num, sum_den);
}
 


int main() {
    int n, k;
    // cin >> n >> k;
    n = 4;
    k = 1;


    int sum_num, sum_dem;
    tie(sum_num, sum_dem) = solve(n, k);
    cout << sum_num << " " << sum_dem << endl;

}