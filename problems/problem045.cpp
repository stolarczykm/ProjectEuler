#include <iostream>

using namespace std;


long long triangle_number(const long long& n) {
    return n*(n+1) / 2;
}

long long pentagonal_number(const long long& n) {
    return n*(3*n - 1) / 2;
}

long long hexagonal_number(const long long& n) {
    return n*(2*n - 1);
}


int main() {
    long long n;
    int a, b;
    cin >> n >> a >> b;
    auto x = pentagonal_number(10);

    auto smaller_func = a == 3 ? triangle_number : pentagonal_number;
    auto bigger_func = b == 5 ? pentagonal_number : hexagonal_number;

    long long n1 = 1, n2 = 1;

    auto smaller_max = 0LL, bigger_max = -1LL;

    while (smaller_max < n && bigger_max < n)
    {
        if (smaller_max == bigger_max) {
            cout << smaller_max << endl;
        }
        bigger_max = bigger_func(n2);
        n2++;
        while (smaller_max < bigger_max) {
            smaller_max = smaller_func(n1);
            n1++;
        }
    }

    return 0;
}