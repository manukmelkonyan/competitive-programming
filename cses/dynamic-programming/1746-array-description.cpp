#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Array Description
// https://cses.fi/problemset/task/1746

constexpr int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    if (nums[0] == 0) {
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][nums[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (nums[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] +
                            dp[i - 1][j] +
                            dp[i - 1][j + 1]) % M;
            }
        } else {
            int num = nums[i];
            dp[i][num] = (dp[i - 1][num - 1] +
                          dp[i - 1][num] +
                          dp[i - 1][num + 1]) % M;
        }
    }

    ll result = 0;
    for (int j = 0; j <= m; ++j) {
        result = (result + dp[n - 1][j]) % M;
    }

    cout << result << '\n';

    return 0;
}