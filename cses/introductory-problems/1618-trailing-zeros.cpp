#include <bits/stdc++.h>
using namespace std;

// Trailing Zeros
// https://cses.fi/problemset/task/1618

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    // TODO: this is not efficient, optimize it
    int zero_count = 0;
    for (int i = 1; i <= n; ++i) {
        int num = i;
        while (num % 5 == 0) {
            num /= 5;
            zero_count++;
        }
    }

    cout << zero_count << '\n';

    return 0;
}
