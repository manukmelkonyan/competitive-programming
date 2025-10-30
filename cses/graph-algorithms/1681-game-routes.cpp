#include <bits/stdc++.h>

#define ll long long
const int M = 1e9 + 7;

using namespace std;

// Game Routes
// https://cses.fi/problemset/task/1681

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    vector<ll> path_counts(n, 0);
    path_counts[0] = 1;

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto& v : adj[u]) {
            path_counts[v] = (path_counts[v] + path_counts[u]) % M;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << path_counts[n - 1] << '\n';

    return 0;
}
