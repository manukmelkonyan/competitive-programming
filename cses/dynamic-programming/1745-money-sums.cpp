#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Money Sums
// https://cses.fi/problemset/task/1745

#define MAX_SUM 1e5

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<vector<bool>> dp(2, vector<bool>(MAX_SUM + 1, false));
    dp[0][0] = true;

    int sum_count = 0;
    for(int i = 1; i <= n; ++i) {
        sum_count = 0;
        int coin = coins[i - 1];
        for (int j = 0; j <= MAX_SUM; ++j) {
            dp[1][j] = dp[0][j];
            if (j >= coin && dp[0][j - coin]) {
                dp[1][j] = true;
            }
        }

        for (int j = 0; j <= MAX_SUM; ++j) {
            sum_count += dp[1][j];
            dp[0][j] = dp[1][j];
            dp[1][j] = false;
        }
    }

    sum_count--;

    cout << sum_count << '\n';
    for(int i = 1; i <= MAX_SUM; ++i) {
        if (dp[0][i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
