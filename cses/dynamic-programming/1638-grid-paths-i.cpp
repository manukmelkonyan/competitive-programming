#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Grid Paths I
// https://cses.fi/problemset/task/1638
constexpr int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<bool>> grid(n, vector<bool>(n, true));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '*') {
                grid[i][j] = false;
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[1][1] = grid[0][0];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue;
            if (grid[i - 1][j - 1]) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % m;
            }
        }
    }

    cout << dp[n][n] % m << '\n';

    return 0;
}
