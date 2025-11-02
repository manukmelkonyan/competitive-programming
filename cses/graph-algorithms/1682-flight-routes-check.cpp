#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Flight Routes Check
// https://cses.fi/problemset/task/1682

void bfs(vector<bool> &visited, vector<vector<int>> &adj) {
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    vector<bool> visited(n);
    visited[0] = true;

    bfs(visited, adj);

    vector<bool> rev_visited(n);
    rev_visited[0] = true;

    bfs(rev_visited, rev_adj);

    for(int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO\n" << 1 << ' ' << i + 1 << '\n';
            return 0;
        }
    }
    for(int i = 0; i < n; ++i) {
        if (!rev_visited[i]) {
            cout << "NO\n" << i + 1 << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
