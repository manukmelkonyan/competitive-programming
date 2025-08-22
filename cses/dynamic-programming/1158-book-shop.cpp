#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Book Shop
// https://cses.fi/problemset/task/1158

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, total_price;
    cin >> n >> total_price;
    
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    for(int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    vector<int> dp(total_price + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = total_price; j >= 1; --j) {
            int pick = 0;
            if (prices[i - 1] <= j) {
                pick = pages[i - 1] + dp[j - prices[i - 1]];
            }

            dp[j] = max(dp[j], pick);
        }
    }

    cout << dp[total_price] << '\n';

    return 0;
}
