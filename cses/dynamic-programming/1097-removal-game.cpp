#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Removal Game
// https://cses.fi/problemset/task/1097

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    ll total = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        total += nums[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            if (l == r) {
                dp[l][r] = nums[l];
            } else {
                dp[l][r] = max(
                    nums[l] - dp[l + 1][r],
                    nums[r] - dp[l][r - 1]
                );
            }
        }
    }

    cout << (total + dp[0][n - 1]) / 2 << '\n';

    return 0;
}
