// https://www.hackerrank.com/contests/projecteuler/challenges/euler017/problem 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <string> thousands = {
    "Thousand",
    "Million", 
    "Billion",
    "Trillion",
};

vector <string> numbers = {
    "One",
    "Two", 
    "Three",
    "Four", 
    "Five", 
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",

};

vector <string> multiples_of_ten = {
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"
};


vector<string> number_below_1000_to_string(int n) {
    vector<string> result = {};
    if (n / 100 > 0) {
        result.push_back(numbers[n / 100 - 1]);
        result.push_back("Hundred");
        n = n % 100;
    }
    if (n / 10 > 1) {
        result.push_back(multiples_of_ten[n / 10 - 2]);
        n = n >= 20 ? n % 10 : n; 
    }
    if (n > 0) {
        result.push_back(numbers[n-1]);
    }
    
    return result;
}

string number_to_string(long long n) {
    if (n == 0) {
        return "Zero";
    }

    vector< vector<string> > results;
    string result = "";
    int i = 0;
    while (n > 0) {
        if (i > 0 && n % 1000 > 0) results.push_back({thousands[i-1]});
        results.push_back(number_below_1000_to_string(n % 1000));
        n = n / 1000;
        ++i ;
    }
    for (int i = results.size() - 1; i >= 0; -- i) {
        for (auto r: results[i]) {
            result += result.size() > 0 ? " " + r : r; 
        }
    }
    return result;
}


int main() {
    int t;
    cin >> t; 

    for (int t0 = 0; t0 < t; ++t0) {
        long n;
        cin >> n;
        // n = t0;


        cout << number_to_string(n) << endl;
    }
    return 0;
}
