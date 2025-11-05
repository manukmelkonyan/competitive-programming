#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Multiplication Table
// https://cses.fi/problemset/task/2422

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;

    ll l = 1;
    ll r = n * n;
    
    while(l < r) {
        ll mid = (l + r) / 2;
        ll count = 0;

        for(int i = 1; i <= n; ++i) {
            count += min(n, mid / i);
        }

        if (count >= (n * n + 1) / 2) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';

    return 0;
}
