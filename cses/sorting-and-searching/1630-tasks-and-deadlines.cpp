#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Tasks and Deadlines
// https://cses.fi/problemset/task/1630

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<pair<int, int>> entries(n);
    for (int i = 0; i < n; ++i) {
        cin >> entries[i].first >> entries[i].second;
    }

    sort(entries.begin(), entries.end());

    ll reward = 0;
    ll current_time = 0;

    for (auto [duration, deadline] : entries) {
        current_time += duration;
        reward += (ll)deadline - current_time;
    }

    cout << reward << "\n";

    return 0;
}
