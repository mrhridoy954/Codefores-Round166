#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> l(q);
    vector<int> r(q);
    
    for (int i = 0; i < q; ++i) {
        cin >> l[i];
    }
    
    for (int i = 0; i < q; ++i) {
        cin >> r[i];
    }
    
    vector<int> pos(n + 1, -1); // stores the position where each number must appear
    vector<int> valid_prefix(n + 1, 1); // stores whether prefix up to that index is valid
    
    for (int i = 0; i < q; ++i) {
        pos[l[i]] = i; // l[i] must come before r[i]
    }
    
    for (int i = 0; i < q; ++i) {
        if (pos[r[i]] != -1 && pos[r[i]] < pos[l[i]]) {
            cout << 0 << endl; // invalid configuration
            return 0;
        }
        pos[r[i]] = q + i; // a large value to ensure it is considered last
    }
    
    // Calculate the number of valid permutations
    vector<int> factorial(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorial[i] = (factorial[i - 1] * (long long)i) % MOD;
    }
    
    vector<int> dp(n + 1, 0); // dp[i] means the number of ways to arrange first i numbers
    dp[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        if (pos[i] == -1) {
            dp[i] = (dp[i - 1] * (long long)i) % MOD;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
