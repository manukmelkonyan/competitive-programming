#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Filled Subgrid Count I
// https://cses.fi/problemset/task/3413

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<string> grid(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    vector<ll> nums_of_squares(k, 0);

    for(int l = 0; l < k; ++l) {
        char letter = 'A' + l;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if (grid[i - 1][j - 1] != letter) {
                    dp[i][j] = 0;
                    continue;
                }

                dp[i][j] = min({
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                }) + 1;

                nums_of_squares[l] += dp[i][j];
            }
        }
    }

    for(auto num_of_squares : nums_of_squares) {
        cout << num_of_squares << "\n";
    }

    return 0;
}
