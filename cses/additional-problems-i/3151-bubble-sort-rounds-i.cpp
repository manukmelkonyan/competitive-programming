#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Bubble Sort Rounds I
// https://cses.fi/problemset/task/3151

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<pair<int, int>> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(nums.begin(), nums.end());

    int max_swaps = 0;
    for(int i = 0; i < n; ++i) {
        max_swaps = max(max_swaps, nums[i].second - i);
    }

    cout << max_swaps << '\n';

    return 0;
}
