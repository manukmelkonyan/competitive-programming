#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Edit Distance
// https://cses.fi/problemset/task/1639

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            dp[i][j] = min({
                dp[i][j - 1] + 1,
                dp[i - 1][j] + 1,
                dp[i - 1][j - 1] + cost
            });
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}
