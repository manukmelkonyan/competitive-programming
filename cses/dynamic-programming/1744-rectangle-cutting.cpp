#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Rectangle Cutting
// https://cses.fi/problemset/task/1744

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 0x7fffffff;
                for (int cut = 1; cut < j; ++cut) {
                    dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j - cut] + 1);
                }

                for (int cut = 1; cut < i; ++cut) {
                    dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i - cut][j] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << '\n';

    return 0;
}
