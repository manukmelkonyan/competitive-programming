#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Subarray Sums I
// https://cses.fi/problemset/task/1660

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;
    
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int l = 0;
    int r = 0;

    int matching_subarrays = 0;
    int sum = 0;
    while (r < n) {
        sum += nums[r];

        while (sum > target && l <= r) {
            sum -= nums[l];
            l++;
        }

        if (sum == target) {
            matching_subarrays++;
        }

        r++;
    }

    cout << matching_subarrays << "\n";

    return 0;
}
