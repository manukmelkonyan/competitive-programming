#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Sliding Window Distinct Values
// https://cses.fi/problemset/task/3222

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    map<int, int> window_counter;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (window_counter.count(nums[i]) == 0) {
            window_counter.insert({ nums[i], 0 });
        }
    }

    int distinct_values = 0;
    for(int i = 0; i < n; ++i) {
        if (window_counter[nums[i]]++ == 0) distinct_values++;
        if (i >= k - 1) {
            cout << distinct_values << " ";
            if (--window_counter[nums[i - k + 1]] == 0) distinct_values--;
        }
    }

    cout << "\n";

    return 0;
}
