#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Subarray Sums II
// https://cses.fi/problemset/task/1661

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    map<ll, ll> prefix_sums;
    prefix_sums.insert({ 0, 1 });

    ll matching_subarrays = 0;

    ll current_prefix_sum = 0;
    for(int i = 0; i < n; ++i) {
        int num = nums[i];

        current_prefix_sum += num;
        ll difference = current_prefix_sum - target;

        auto match = prefix_sums.find(difference);
        if (match != prefix_sums.end()) {
            matching_subarrays += match->second;
        }
        
        if (prefix_sums.find(current_prefix_sum) == prefix_sums.end()) {
            prefix_sums.insert({ current_prefix_sum, 0 });
        }
        prefix_sums[current_prefix_sum] += 1;
    }

    cout << matching_subarrays << "\n";

    return 0;
}
