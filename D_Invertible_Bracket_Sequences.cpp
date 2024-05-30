#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countValidPairs(const string& s) {
    int n = s.size();
    vector<int> balance(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        balance[i + 1] = balance[i] + (s[i] == '(' ? 1 : -1);
    }

    unordered_map<int, int> balanceCount;
    int validPairs = 0;

    for (int i = 0; i <= n; ++i) {
        if (balanceCount.find(balance[i]) != balanceCount.end()) {
            validPairs += balanceCount[balance[i]];
        }
        balanceCount[balance[i]]++;
    }

    return validPairs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << countValidPairs(s) << endl;
    }

    return 0;
}
