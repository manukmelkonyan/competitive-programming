#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Subordinates
// https://cses.fi/problemset/task/1674

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 1; i < n; ++i) {
        int u;
        cin >> u;
        adj[--u].push_back(i);
    }

    vector<int> subordinates(n, 0);

    function<int(int)> dfs = [&](int u) -> int {
        for(auto v : adj[u]) {
            subordinates[u] += 1 + dfs(v);
        }
        return subordinates[u];
    };

    dfs(0);

    for(auto x : subordinates) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
