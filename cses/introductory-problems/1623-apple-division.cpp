#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Apple Division
// https://cses.fi/problemset/task/1623

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    ll total_sum = 0;
    vector<int> weights(n);
    for(int i = 0; i < n; ++i) {
        cin >> weights[i];
        total_sum += weights[i];
    }

    ll min_diff = 0x7fffffffffffffffLL;
    for(int s = 0; s <= (1 << n); ++s) {
        ll div1 = 0;
        for(int i = 0; i < n; ++i) {
            if (s & (1 << i)) div1 += weights[i];
        }
        min_diff = min(min_diff, abs(total_sum - div1 - div1));
    }

    cout << min_diff << "\n";
    
    return 0;
}
