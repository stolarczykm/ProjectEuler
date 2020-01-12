// https://www.hackerrank.com/contests/projecteuler/challenges/euler022/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int bin_search(const vector<string>& x, string& element, int left=0, int right=-1) {
    if (right == -1) 
        right = x.size();
    if (right - left < 1) 
        return -1;

    int middle = left + (right - left) / 2;

    if (x[middle] == element) {
        return middle;
    }

    if (element < x[middle]) {
        return bin_search(x, element, left, middle);
    }

    return bin_search(x, element, middle + 1, right);
}

int name_score(const string& x) {
    int score = 0;
    for (const auto& ch: x) {
        score += ch - 'A' + 1;
    }
    return score;
}


int main() {
    int q;
    cin >> q;

    vector<string> names = {};
    for (int i = 0; i < q; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    sort(names.begin(), names.end());

    cin >> q;
    for (int i = 0; i < q; ++i) {
        string name;
        cin >> name;
        cout << (bin_search(names, name) + 1) * name_score(name) << endl;
    }

    return 0;
}
