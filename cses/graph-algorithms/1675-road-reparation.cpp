#include <bits/stdc++.h>

#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL

using namespace std;

// Road Reparation
// https://cses.fi/problemset/task/1675

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    vector<bool> used(n, false);
    vector<ll> dist(n, INF);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({ 0, 0 });
    int picked = 0;
    ll total_cost = 0;

    while(!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (used[u]) continue;
        used[u] = true;
        picked++;
        total_cost += cost;

        for(auto [v, w] : adj[u]) {
            if (!used[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({ w, v });
            }
        }
    }

    if (picked != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << total_cost << '\n';
    }

    return 0;
}
