#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Stick Lengths
// https://cses.fi/problemset/task/1074

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<int> sticks(n);
    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());
    
    int median = sticks[n / 2];
    ll optimal_cost = 0;
    
    for (int i = 0; i < n; ++i) {
        optimal_cost += abs(median - sticks[i]);
    }

    cout << optimal_cost << '\n';

    return 0;
}
