#include <bits/stdc++.h>

#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL

const int M = 1e9 + 7;

using namespace std;

// Investigation
// https://cses.fi/problemset/task/1202

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
    }

    const int start = 0;
    const int target = n - 1;

    vector<vector<ll>> stats(n, { INF, 0, INF, 0 }); // dist, count, min_flights, max_flights
    priority_queue<
        tuple<ll, ll, int>,
        vector<tuple<ll, ll, int>>,
        greater<tuple<ll, ll, int>>
    > pq; // { price, flights, node }
    pq.push({ 0, 0, start });
    stats[start] = { 0, 1, 0, 0 };

    while(!pq.empty()) {
        auto [current_price, flights, u] = pq.top(); pq.pop();
        
        if (stats[u][0] < current_price) continue;
        
        for(auto& [v, w] : adj[u]) {
            ll new_weight = current_price + w;
            if (new_weight < stats[v][0]) {
                stats[v] = { new_weight, stats[u][1], stats[u][2] + 1, stats[u][3] + 1 };
                pq.push({ new_weight, flights + 1, v });
            } else if (new_weight == stats[v][0]) {
                stats[v][1] = (stats[v][1] + stats[u][1]) % M;
                stats[v][2] = min(stats[v][2], stats[u][2] + 1);
                stats[v][3] = max(stats[v][3], stats[u][3] + 1);
            }
        }
    }
    stats[target][1] = stats[target][1] % M;
    for(auto answer : stats[target]) cout << answer << ' ';
    cout << '\n';

    return 0;
}
