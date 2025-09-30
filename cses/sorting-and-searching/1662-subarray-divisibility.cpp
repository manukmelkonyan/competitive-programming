#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Subarray Divisibility
// https://cses.fi/problemset/task/1662

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    map<int, int> prefix_sum_remainders;
    prefix_sum_remainders.insert({ 0, 1 });

    ll divisible_subarrays = 0;
    ll current_prefix_sum = 0;

    for(auto num : nums) {
        current_prefix_sum += num;
        int current_prefix_sum_remainder = current_prefix_sum % n;

        int search = current_prefix_sum_remainder >= 0 ? current_prefix_sum_remainder : (n + current_prefix_sum_remainder);

        auto match = prefix_sum_remainders.find(search);
        if (match != prefix_sum_remainders.end()) {
            divisible_subarrays += match->second;
        } else {
            prefix_sum_remainders.insert({ search, 0 });
        }

        prefix_sum_remainders[search]++;
    }

    cout << divisible_subarrays << "\n";

    return 0;
}
