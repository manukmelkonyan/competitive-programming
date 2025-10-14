#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Round Trip II
// https://cses.fi/problemset/task/1678

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    stack<int> st;
    
    const int UNVISITED = 0, VISITING = 1, VISITED = 2;
    vector<int> state(n, UNVISITED);
    vector<int> parent(n, -1);
    vector<int> cycle;

    bool found_cycle = false;

    function<void(int)> dfs = [&](int u) {
        state[u] = VISITING;

        for(int v : adj[u]) {
            if (found_cycle) return;
            if (state[v] == UNVISITED) {
                parent[v] = u;
                dfs(v);
            } else if (state[v] == VISITING) {
                found_cycle = true;
                cycle.push_back(v);
                for(int node = u; node != v; node = parent[node]) {
                    cycle.push_back(node);
                }
                cycle.push_back(v);
                reverse(cycle.begin(), cycle.end());
                return;
            }
        }

        state[u] = VISITED;
    };
    
    for(int i = 0; i < n; ++i) {
        if (state[i] == UNVISITED) dfs(i);
    }

    if (found_cycle) {
        cout << cycle.size() << "\n";
        for (auto x : cycle) {
            cout << ++x << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
