#include <iostream>
#include <vector>
#include <iostream>

using namespace std;


struct DigitVector
{
    vector<int> vec;

    DigitVector() {
        vec = vector<int>(10);
    };

    DigitVector(long n) {
        vec = vector<int>(10);
        while (n > 0) {
            vec[n % 10]++;
            n = n / 10;
        }
    }

    friend bool operator==(const DigitVector& lhs, const DigitVector& rhs);

};

bool operator==(const DigitVector& lhs, const DigitVector& rhs) {
    for (int i = 0; i < 10; ++i) {
        if (lhs.vec[i] !=  rhs.vec[i]) return false;
    }
    return true;

};


int main(int argc, char const *argv[])
{
    long n;
    int k;
    cin >> n >> k;


    for (long i = 1; i <= n; ++i) {
        auto digits = DigitVector(i);

        bool same_digits = true;
        for (int j = 2; j <= k; ++j) {
            auto multiple_digits = DigitVector(i * j);
            if (!(multiple_digits == digits)) {
                same_digits = false;
                break;
            }
        }
        if (same_digits) {
            cout << i;
            for (int j = 2; j <= k; ++j) cout << " " << j*i;
            cout << endl;
        }
    }
}