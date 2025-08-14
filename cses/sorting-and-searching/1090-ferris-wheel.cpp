#include <bits/stdc++.h>
using namespace std;

// Ferris Wheel
// https://cses.fi/problemset/task/1090

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, max_weight;
    cin >> n >> max_weight;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int num_of_gondolas = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (weights[l] + weights[r] <= max_weight) {
            l++;
            r--;
        }
        else {
            r--;
        }
        num_of_gondolas++;
    }
    if (l == r) {
        num_of_gondolas++;
    }

    cout << num_of_gondolas << '\n';

    return 0;
}
