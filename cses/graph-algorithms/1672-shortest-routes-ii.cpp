#include <bits/stdc++.h>

#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL

using namespace std;

// Shortest Routes II
// https://cses.fi/problemset/task/1672

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >>c;
        a--; b--;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<vector<ll>> distance(n, vector<ll>(n, INF));
    for(int i = 0; i < n; ++i) {
        distance[i][i] = 0;
        for(auto [j, weight] : adj[i]) {
            distance[i][j] = min(distance[i][j], (ll)weight);
        }
    }
    
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for(auto [a, b] : queries) {
        ll ans = distance[a - 1][b - 1];
        cout << (ans == INF ? -1 : ans) << "\n";
    }

    return 0;
}
