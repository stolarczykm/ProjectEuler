#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct BigInt {
    using LL = unsigned long long;
    vector<LL> number;
    const LL MOD = 1000000000;
    const int DIGITS_PER_ELEMENT = 9;

    BigInt(LL n) {
        number = vector<LL>();
        number.push_back(n % MOD);
    }

    BigInt(const BigInt& other) {
        number = other.number;
    }

    const BigInt& operator=(const BigInt& other) {
        number = other.number;
        return *this;
    }

    BigInt(vector<LL> n): number(n) {};

    BigInt(string s) {
        size_t size = (s.size() - 1) / DIGITS_PER_ELEMENT + 1;
        number = vector<LL>(size);
        for (long i = 0; i < size; ++i) {
            auto start = max(0L, (long)(s.size()) - (i+1) * DIGITS_PER_ELEMENT);
            auto end = s.size() - i * DIGITS_PER_ELEMENT;
            number[i] = stoll(s.substr(start, end-start));
        }

    }

    std::string to_string() const {
        stringstream s;
        for (auto it = number.rbegin(); it != number.rend(); ++it ) {
            s << *it;
        }
        return s.str();
    }

    std::string to_reverse_string() const {
        auto s = to_string();
        auto rs = std::string(s.rbegin(), s.rend());
        return rs;
    }


    BigInt reverse() const {
        auto rs = to_reverse_string();
        auto big_int = BigInt(rs);
        return big_int;
    }

    bool is_palindrome() const {
        auto s = to_string();
        auto rs = std::string(s.rbegin(), s.rend());
        return s == rs;
    }

    const BigInt operator+(const BigInt &other) const {
        auto max_size = max(number.size(), other.number.size());
        auto new_number = vector<LL>(max_size);
        LL carry_on = 0LL;
        for (size_t i = 0; i < max_size; ++i) {
            LL sum = carry_on;
            if (i < number.size())
                sum += number[i];
            if (i < other.number.size()) 
                sum += other.number[i];

            carry_on = sum / MOD;
            new_number[i] = sum % MOD;
        }

        if (carry_on > 0) {
            new_number.push_back(carry_on);
        }

        auto result = BigInt(new_number);
        return result;
    }

    bool operator<=(const LL &other) const {
        return number.size() == 1 && number[0] <= other;
    }

    friend ostream& operator<<(ostream& stream, const BigInt& num) {
        for (auto it = num.number.rbegin(); it != num.number.rend(); ++it ) {
            stream << *it;
        }
        return stream;
    }


    vector<int> get_digits(LL number) {
        auto digits = vector<int>();
        while (number > 0) {
            digits.push_back(number % 10);
            number = number / 10;
        }
        return digits;
    }

    vector<int> get_digits() {
        auto digits = vector<int>();
        for (auto it = number.rbegin(); it != number.rend(); ++it ) {
            auto sub_digits = get_digits(*it);
            for (auto it = sub_digits.rbegin(); it != sub_digits.rend(); ++it) {
                digits.push_back(*it);
            }
        }
        return digits;
    }
};


map<string, string> get_palindrome_map(int n) {
    auto num_to_palindrome_map = map<string, string>();
    auto map_end = num_to_palindrome_map.end();

    for (int i = 1; i <= n; ++i) {
        auto num =  BigInt(i);
        vector<BigInt> numbers = {num};
        bool is_lychrel = false;
        BigInt *pal = nullptr;
        for (int j = 0; j < 60; ++j) {
            
            if (num <= num.MOD) {
                auto it = num_to_palindrome_map.find(num.to_string());
                if (it != map_end) {
                    delete pal;
                    if (it -> second == "") pal == nullptr;
                    else {
                        pal = new BigInt(num_to_palindrome_map[num.to_string()]); 
                    }
                    is_lychrel = true;
                }
            }
            if (num.is_palindrome()) {
                pal = &num;
                is_lychrel = true;
            }


            if (is_lychrel) {
                for (auto x: numbers) {
                    {
                        auto s = pal == nullptr ? "" : pal -> to_string();
                    if (x <= (BigInt::LL)n) 
                        num_to_palindrome_map[x.to_string()] = s;
                    }
                }
                break;
            }

            num = num + num.reverse();
            numbers.push_back(num);
        }
        if (!is_lychrel) {
            for (auto x: numbers) 
                num_to_palindrome_map[x.to_string()] = "";
        }
    }

    return num_to_palindrome_map;
}

template <typename T, typename S>
map<T, int> get_value_counts(map<S, T> input_map, T ignore) {
    auto result = map<T, int>();
    auto map_end = result.end();

    for (auto it = input_map.begin(); it != input_map.end(); ++it) {
        if (it->second == ignore) continue;
        if (result.find(it->second) == map_end) {
            result[it->second] = 1;
        } else 
            result[it->second]++;
    }
    return result;
}


template <typename T, typename S>
pair<T, S> find_max_value(map<T, S> map) {
    auto it = map.begin();
    T max_key = it -> first;
    S max_value = it -> second;

    for (; it != map.end(); ++it) {
        if (it->second > max_value) {
            max_key = it->first;
            max_value = it->second;
        }
    }

    return make_pair(max_key, max_value);

}


int main() {

    int n;
    cin >> n;

    auto palindrome_map = get_palindrome_map(n);
    auto palindrom_counts = get_value_counts(palindrome_map, string(""));


    auto max_pair = find_max_value(palindrom_counts);

    cout << max_pair.first << " " << max_pair.second << endl;

    return 0;
}