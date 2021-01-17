#include <iostream>
#include <vector>
#include <istream>

using namespace std;

vector<char> read_input(istream& is) {
    int n;
    is >> n;
    vector<char> chars = {};
    for (int i = 0; i < n; ++i) {
        int ch = 0;
        is >> ch;
        chars.push_back((char)ch);
    }
    return chars;
}


bool is_plain_text(char ch) {
    if (ch >= 'a' && ch <= 'z') return true;
    if (ch >= 'A' && ch <= 'Z') return true;
    if (ch >= '0' && ch <= '9') return true;
    string allowed_chars = "();:,.'?-! ";
    if (allowed_chars.find(ch) != string::npos) return true;
    return false;

}

bool is_valid_key(const vector<char>& chars, const vector<char>& key) {
    bool result = true;
    for (int i = 0; i < chars.size(); ++i) {
        char decrypted_char = chars[i] ^ key[i % 3];
        if (!is_plain_text(decrypted_char)) {
            result = false;
            break;
        }
    }
    return result;
}

vector<char> find_valid_key(const vector<char>& chars) {
    vector<char> key;
    for (char k1 = 'a'; k1 <= 'z'; ++k1) 
        for (char k2 = 'a'; k2 <= 'z'; ++k2) 
            for (char k3 = 'a'; k3 <= 'z'; ++k3) {
                key = {k1, k2, k3};
                if (is_valid_key(chars, key))
                    return key;
    }
    return {'X', 'X', 'X'};

}

int main() {
    auto chars = read_input(cin);
    vector<char> key = find_valid_key(chars);

    cout << key[0] << key[1] << key[2] << endl;
}