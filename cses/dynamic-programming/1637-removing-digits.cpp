#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Removing Digits
// https://cses.fi/problemset/task/1637

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[n] = 0;

    for(int i = n; i >= 1; --i) {
        int num = i;
        while (num) {
            int digit = num % 10;
            num /= 10;
            if (digit) {
                dp[i - digit] = min(dp[i - digit], dp[i] + 1);
            }
        }
    }

    cout << dp[0] << '\n';

    return 0;
}
