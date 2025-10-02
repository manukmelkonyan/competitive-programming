#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Coin Combinations II
// https://cses.fi/problemset/task/1636

const int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; ++i) {
        int coin = coins[i];
        for(int sum = coin; sum <= target; ++sum) {
            dp[sum] = (dp[sum] + dp[sum - coin]) % M;
        }
    }

    cout << dp[target] << "\n";

    return 0;
}
