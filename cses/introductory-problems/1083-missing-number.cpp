#include <bits/stdc++.h>
using namespace std;

// Missing Number
// https://cses.fi/problemset/task/1083

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    long long total_sum = n * (1LL + n) / 2;

    for (int i = 0; i < n - 1; ++i) {
        int current_num;
        cin >> current_num;
        total_sum -= (long long)current_num;
    }

    cout << total_sum;

    return 0;
}
