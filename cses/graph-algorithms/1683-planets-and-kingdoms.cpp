#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Planets and Kingdoms
// https://cses.fi/problemset/task/1683

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

    vector<bool> visited(n, false);
    vector<int> top_order;

    function<void(int)> dfs1 = [&](const int u) {
        visited[u] = true;
        for(int& v : adj[u]) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        top_order.push_back(u);
    };

    for(int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    reverse(top_order.begin(), top_order.end());
    fill(visited.begin(), visited.end(), false);

    vector<int> kingdoms(n);

    function<void(int, int)> dfs2 = [&](const int u, const int component) {
        visited[u] = true;
        kingdoms[u] = component;

        for(auto& v : rev_adj[u]) {
            if (!visited[v]) {
                dfs2(v, component);
            }
        }
    };
    
    int component = 0;
    for(auto& u : top_order) {
        if (!visited[u]) {
            dfs2(u, component++);
        }
    }
    cout << component << '\n';
    for(auto& kingdom : kingdoms) cout << kingdom + 1 << ' ';
    cout << '\n';

    return 0;
}
