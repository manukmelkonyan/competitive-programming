#include <bits/stdc++.h>
using namespace std;

// Bit Strings
// https://cses.fi/problemset/task/1617

constexpr int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    uint64_t res = 1;

    for (int i = 0; i < n; ++i) {
        res = ((res % m) * 2) % m;
    }

    cout << res;

    return 0;
}
