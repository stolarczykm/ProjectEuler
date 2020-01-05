#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long nth_prime_number(long n) {

    // Upper bound for nth prime number.
    // https://en.wikipedia.org/wiki/Prime_number_theorem#Approximations_for_the_nth_prime_number
    long upper_bound;
    if (n >= 6) {
        upper_bound = ceil(n * log(n) + n * log(log(n)));
    } else {
        upper_bound = 13;
    }

    vector<bool> is_prime = vector<bool>(upper_bound, true);
    long prime_counter = 0;

    for (int i = 0; i < is_prime.size(); ++i) {
        if (!is_prime[i]) continue;

        ++prime_counter;
        if (prime_counter >= n) {
            return i+2;
        }

        for (int j=2; j*(i+2)-2 < is_prime.size(); ++j) {
            is_prime[j*(i+2)-2] = false;
        }
    }
    throw "nth prime not found";
}


int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;

        cout << nth_prime_number(n) << endl;
    }
    return 0;
}
