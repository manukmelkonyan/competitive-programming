#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Minimizing Coins
// https://cses.fi/problemset/task/1634

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target_sum;
    cin >> n >> target_sum;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(target_sum + 1, -1);

    dp[0] = 0;


    for(int i = 1; i <= target_sum; ++i) {
        for (int coin : coins) {
            if (coin > i || dp[i - coin] == -1) {
                continue;
            }
            if (dp[i] == -1) {
                dp[i] = dp[i - coin] + 1;
            }
            else {
                dp[i] = min(
                    dp[i],
                    dp[i - coin] + 1
                );
            }
        }
    }

    cout << dp[target_sum] << '\n';

    return 0;
}
