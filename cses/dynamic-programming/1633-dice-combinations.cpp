#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Dice Combinations
// https://cses.fi/problemset/task/1633

constexpr int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    ll dp[n + 1] = {};
    dp[0] = 1;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= 6 && j <= i; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % m;
        }
    }

    cout << dp[n] % m << '\n';

    return 0;
}
