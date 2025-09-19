#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Missing Coin Sum
// https://cses.fi/problemset/task/2183

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    ll max_sum_so_far = 0;
    for (int coin : coins) {
        if (coin > max_sum_so_far + 1) {
            break;
        }

        max_sum_so_far += coin;
    }

    cout << max_sum_so_far + 1 << '\n';

    return 0;
}
