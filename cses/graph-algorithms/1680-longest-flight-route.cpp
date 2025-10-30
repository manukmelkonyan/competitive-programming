#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Longest Flight Route
// https://cses.fi/problemset/task/1680

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
    const int source = 0;
    const int target = n - 1;

    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) q.push(i);
    }
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    dist[source] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto& v : adj[u]) {
            if (dist[u] != -1 && dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (dist[target] == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[target] << '\n';
        vector<int> path;
        int curr = target;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for (auto& v : path) cout << v + 1 << ' ';
        cout << '\n';
    }

    return 0;
}
