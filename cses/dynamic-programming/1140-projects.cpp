#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Projects
// https://cses.fi/problemset/task/1140

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int last_end_day = 0;
    
    vector<tuple<int, int, int>> projects(n); // { end, start, reward }[]
    for(int i = 0; i < n; ++i) {
        int start, end, reward;
        cin >> start >> end >> reward;
        projects[i] = { end, start, reward };
    }

    sort(projects.begin(), projects.end());

    vector<ll> dp(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        auto [end, start, reward] = projects[i - 1];
        
        auto it = lower_bound(projects.begin(), projects.begin() + (i - 1), make_tuple(start, 0, 0));
        int prev_idx = distance(projects.begin(), it);

        dp[i] = max(
            dp[i - 1],
            reward + dp[prev_idx]
        );
    }

    cout << dp[n] << "\n";

    return 0;
}
