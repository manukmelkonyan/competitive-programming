#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Course Schedule
// https://cses.fi/problemset/task/1679

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int UNVISITED = 0, VISITING = 1, VISITED = 2;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    vector<int> topological_order;
    vector<int> state(n, UNVISITED);

    bool hasCycle = false;
    function<void(int)> dfs = [&](const int u) -> void {
        state[u] = VISITING;
        
        for(auto v : adj[u]) {
            if (state[v] == UNVISITED)
                dfs(v);
            else if (state[v] == VISITING)
                hasCycle = true;
        }

        state[u] = VISITED;
        topological_order.push_back(u);
    };

    for(int i = 0; i < n; ++i) {
        if (state[i] == UNVISITED) dfs(i);
    }

    if (hasCycle) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        reverse(topological_order.begin(), topological_order.end());
        for(auto v : topological_order) {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }
        

    return 0;
}
