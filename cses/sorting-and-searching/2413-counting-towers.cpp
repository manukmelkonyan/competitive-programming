#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Counting Towers
// https://cses.fi/problemset/task/2413

constexpr int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> tests(t);

    int max_n = 0;
    for (int i = 0; i < t; ++i) {
        cin >> tests[i];
        max_n = max(max_n, tests[i]);
    }

    vector<vector<ll>> dp(max_n + 1, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= max_n; ++i) {
        dp[i][0] = (2 * dp[i - 1][0] + 1 * dp[i - 1][1]) % M;
        dp[i][1] = (1 * dp[i - 1][0] + 4 * dp[i - 1][1]) % M;
    }

    for(auto n : tests) {
        cout << (dp[n][0] + dp[n][1]) % M << '\n';
    }

    return 0;
}
