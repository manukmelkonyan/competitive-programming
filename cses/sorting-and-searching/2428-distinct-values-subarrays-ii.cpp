#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Distinct Values Subarrays II
// https://cses.fi/problemset/task/2428

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    map<int, int> frequency_in_window;
    ll k_distinct_subarrays = 0;
    int l = 0, r = 0;
    while (r < n) {
        if (frequency_in_window.find(nums[r]) == frequency_in_window.end()) {
            frequency_in_window.insert({ nums[r], 1 });
        } else {
            frequency_in_window[nums[r]]++;
        }

        while(frequency_in_window.size() > k) {
            frequency_in_window[nums[l]]--;
            if (frequency_in_window[nums[l]] == 0) {
                frequency_in_window.erase(nums[l]);
            }
            l++;
        }

        k_distinct_subarrays += r - l + 1;
        r++;
    }

    cout << k_distinct_subarrays << "\n";

    return 0;
}
