#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Increasing Subsequence
// https://cses.fi/problemset/task/1145

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> accumulator;
    accumulator.push_back(nums[0]);

    for(auto num : nums) {
        if (num > accumulator.back()) {
            accumulator.push_back(num);
        } else {
            auto insert_position = lower_bound(accumulator.begin(), accumulator.end(), num);
            *insert_position = num;
        }
    }

    cout << accumulator.size() << '\n';

    return 0;
}
