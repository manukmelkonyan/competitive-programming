#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Sliding Window Xor
// https://cses.fi/problemset/task/3426

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> nums(n);
    nums[0] = x;
    for(int i = 1; i < n; ++i) {
        nums[i] = (a * nums[i - 1] + b) % c;
    }

    ll window_xor = 0;
    ll result = 0;
    for(int i = 0; i < n; ++i) {
        window_xor ^= nums[i];
        if (i >= k - 1) {
            result ^= window_xor;
            window_xor ^= nums[i - k + 1];
        }
    }

    cout << result << "\n";

    return 0;
}
