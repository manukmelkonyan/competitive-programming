#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Sliding Window Mex
// https://cses.fi/problemset/task/3219

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    map<int, int> window_counter;
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (window_counter.find(nums[i]) == window_counter.end()) {
            window_counter.insert({ nums[i], 0 });
        }
    }

    set<int> available_nums;
    for(int i = 0; i <= k; ++i) {
        available_nums.insert(i);
    }

    for(int i = 0; i < n; ++i) {
        int num_to_insert = nums[i];
        ++window_counter[num_to_insert];
        available_nums.erase(num_to_insert);

        if (i >= k - 1) {
            int smallest_available = *available_nums.begin();
            cout << smallest_available << " ";

            int num_to_pop = nums[i - k + 1];
            if (--window_counter[num_to_pop] == 0) {
                available_nums.insert(num_to_pop);
            }
        }
    }
    cout << "\n";

    return 0;
}
