#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Coin Collector
// https://cses.fi/problemset/task/1686

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

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
        for(auto& v : adj[u]) {
            if (!visited[v])
                dfs1(v);
        }

        top_order.push_back(u);
    };

    for(int i = 0; i < n; ++i) {
        if (!visited[i]) dfs1(i);
    }

    reverse(top_order.begin(), top_order.end());
    fill(visited.begin(), visited.end(), false);

    vector<int> scc_ids(n);
    vector<ll> scc_sums(n, 0);

    function<void(int, int)> dfs2 = [&](const int u, const int& component) {
        visited[u] = true;
        scc_ids[u] = component;
        scc_sums[component] += coins[u];
        
        for(auto& v : rev_adj[u]) {
            if (!visited[v])
                dfs2(v, component);
        }
    };

    int scc = 0;
    for(auto& i : top_order) {
        if (!visited[i]){
            dfs2(i, scc++);
        }
    }

    vector<vector<int>> scc_adj(scc);
    for(int u = 0; u < n; ++u) {
        for (auto& v : adj[u]) {
            if (scc_ids[u] != scc_ids[v]) {
                scc_adj[scc_ids[u]].push_back(scc_ids[v]);
            }
        }
    }

    vector<ll> dp(scc, 0);

    function<ll(int)> scc_dfs = [&](const int u) -> ll {
        if (dp[u]) return dp[u];
        ll local_max = 0;
        for(auto& v : scc_adj[u]) {
            local_max = max(local_max, scc_dfs(v));
        }

        dp[u] = local_max + scc_sums[u];
        return dp[u];
    };

    ll max_coins_sum = 0;

    for(int i = 0; i < scc; ++i) {
        max_coins_sum = max(max_coins_sum, scc_dfs(i));
    }

    cout << max_coins_sum << '\n';

    return 0;
}
