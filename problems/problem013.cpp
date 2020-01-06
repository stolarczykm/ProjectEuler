// https://www.hackerrank.com/contests/projecteuler/challenges/euler013/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> numbers = vector<string>(0, "");
    for (int i = 0; i < n; ++i) {
        string num;
        cin >> num;
        numbers.push_back(num);
    }

    vector<int> sum = vector<int>(0, 0);
    int digits_sum = 0;
    for (int i=49; i>=0; --i) {
        for (auto number: numbers) {
            digits_sum = digits_sum + (number[i] - '0');
        }
        sum.push_back(digits_sum % 10);
        digits_sum = digits_sum / 10;
    }

    while (digits_sum > 0) {
        sum.push_back(digits_sum % 10);
        digits_sum = digits_sum / 10;
    }

    for (int i = 0; i < 10; ++i) {
        cout << sum[sum.size()-1-i];
    }
    cout << endl;
    return 0;
}
