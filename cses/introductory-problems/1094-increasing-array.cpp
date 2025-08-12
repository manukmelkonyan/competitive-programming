#include <bits/stdc++.h>
using namespace std;

// Increasing Array
// https://cses.fi/problemset/task/1094

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;

    int prev;
    cin >> prev;
    long long move_count = 0;

    for (int i = 1; i < n; ++i) {
        int current;
        cin >> current;
        if (current < prev) {
            move_count += (prev - current);
            current = prev;
        }

        prev = current;
    }

    cout << move_count;

    return 0;
}
