#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n + 1);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n + 1; ++i) {
            cin >> b[i];
        }
        
        long long sum_a = accumulate(a.begin(), a.end(), 0LL);
        long long sum_b = accumulate(b.begin(), b.end(), 0LL);
        
        long long required_sum_change = sum_b - sum_a;

        long long min_operations = abs(required_sum_change);
        
        cout << min_operations << endl;
    }
    
    return 0;
}
