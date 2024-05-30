#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_sorted(const string &s) {
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] < s[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string password;
        cin >> n >> password;
        
        string digits, letters;
        bool valid = true;
        
        for (char c : password) {
            if (isdigit(c)) {
                if (!letters.empty()) { 
                    valid = false;
                }
                digits += c;
            } else if (isalpha(c)) {
                letters += c;
            }
        }
        
        if (!is_sorted(digits) || !is_sorted(letters)) {
            valid = false;
        }
        
        cout << (valid ? "YES" : "NO") << endl;
    }
    
    return 0;
}
