#include <bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum
// https://cses.fi/problemset/task/1643

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int64_t max_sum = INT_MIN;
    int64_t sum = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        max_sum = max(sum, max_sum);
        
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << max_sum << '\n';

    return 0;
}
