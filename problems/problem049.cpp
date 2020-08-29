#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
using std::cout;
using GROUP = map<long, vector<long> >;


vector<bool> sieve(const long& n) {
    vector<bool> is_prime = vector<bool>(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (long j=2; j*2 < is_prime.size(); ++j) {
        is_prime[j*2] = false;
    }

    for (long i = 3; i < is_prime.size(); i += 2) {
        if (!is_prime[i]) continue;

        for (long j=i; j*i < is_prime.size(); ++j) {
            is_prime[j*i] = false;
        }
    }
    return is_prime;
}

vector<long> get_primes(const vector<bool>& is_prime) {
    vector<long> primes = {};
    for (long i = 0; i < is_prime.size(); ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}


long get_digit_counts(long n) {
    auto digits = vector<int>(10, 0);
    while (n > 0) {
        digits[n % 10] += 1;
        n = n / 10;
    }
    long res = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
        res *= 10;
        res = res + digits[i];
    }
    return res;
}


GROUP find_prime_groups(const vector<long>& primes, const long& n) {
    GROUP prime_groups = {};
    for (auto p: primes) {
        auto group = get_digit_counts(p);
        if (prime_groups.find(group) != prime_groups.end()) {
                prime_groups[group].push_back(p);
        }
        else if (p < n) {
            prime_groups[group] = {p};
        }
    }
    return prime_groups;
}


vector<vector<long>> find_arithmetic_progressions(const vector<long>& sequence, int size) {
    auto progressions = vector<vector<long>>();
    for (int i = 0; i < sequence.size(); ++i) {
        for (int j = i + 1; j < sequence.size(); ++j) {
            long diff = sequence[j] - sequence[i];
            vector<long> prog = {sequence[i], sequence[j]};
            for (int k = j + 1; k < sequence.size(); ++k) {
                if (sequence[k] - prog[prog.size()-1] == diff) {
                    prog.push_back(sequence[k]);
                    if (prog.size() == size) {
                        progressions.push_back(prog);
                        break;
                    }
                }
            }
        }
    }
    return progressions;

}

std::string& ltrim(std::string& s)
{
	auto it = std::find_if(s.begin(), s.end(),
					[](char c) {
						return !std::isspace<char>(c, std::locale::classic());
					});
	s.erase(s.begin(), it);
	return s;
}


int main(int argc, char const *argv[])
{
    long n;
    int k;
    cin >> n >> k;


    auto is_prime = sieve((long)pow(10.0, ceil(log10((double)n))));
    auto primes = get_primes(is_prime);
    auto prime_groups = find_prime_groups(primes, n);


    vector<string> numbers = {};
    for (auto it = prime_groups.begin(); it != prime_groups.end(); ++it) {
        if (it->second.size() < k) continue;

        auto progressions = find_arithmetic_progressions(it->second, k);
        for (auto prog: progressions) {
            if (prog[0] >= n) continue;
            string number = "";
            for (auto p : prog) {
                number += to_string(p);
            }
            numbers.push_back(number);
        }
    }

    int max_len = 0;
    for (auto s: numbers) 
        max_len = max(max_len, (int)s.length());
    
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i].length() < max_len) {
            string s(max_len - numbers[i].length(), ' ');
            numbers[i] = s + numbers[i];
        }
    }


    sort(numbers.begin(), numbers.end());

    for (auto number: numbers) {
        cout << ltrim(number) << endl;
    }

    return 0;
}

