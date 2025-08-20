#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Coin Combinations I
// https://cses.fi/problemset/task/1635

constexpr int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target_sum;
    cin >> n >> target_sum;

    vector<int> coins(n);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int dp[target_sum + 1] = {};

    dp[0] = 1;

    for (int i = 1; i <= target_sum; ++i) {
        for (int coin : coins) {
            if (coin > i) continue;

            dp[i] = (dp[i] + dp[i - coin]) % m;
        }
    }

    cout << dp[target_sum] % m << '\n';

    return 0;
}
