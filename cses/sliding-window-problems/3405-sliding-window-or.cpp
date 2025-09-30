#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Sliding Window Or
// https://cses.fi/problemset/task/3405

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

    vector<ll> prefix(n);
    prefix[0] = nums[0];
    for(int i = 1; i < n; ++i) {
        if (i % k == 0) prefix[i] = nums[i];
        else prefix[i] = prefix[i - 1] | nums[i];
    }

    vector<ll> suffix(n);
    suffix[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        if (i % k == k - 1) suffix[i] = nums[i];
        else suffix[i] = suffix[i + 1] | nums[i];
    }
    
    ll result = 0;
    for(int i = k - 1; i < n; ++i) {
        ll window_or;
        if (i % k == k - 1) window_or = prefix[i];
        else window_or = (prefix[i] | suffix[i - k + 1]);
        result ^= window_or;
    }

    cout << result << "\n";

    return 0;
}
