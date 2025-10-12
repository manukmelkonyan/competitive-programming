#include <bits/stdc++.h>

#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL

using namespace std;

// High Score
// https://cses.fi/problemset/task/1673

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = { a, b, -c };
        adj[a].push_back(b);
    }

    vector<ll> distance(n, INF);
    distance[0] = 0;

    for(int i = 0; i < n - 1; ++i) {
        for(auto [a, b, weight] : edges) {
            if (distance[a] != INF) {
                distance[b] = min(distance[b], distance[a] + weight);
            }
        }
    }

    vector<bool> affected(n, false);
    for(auto [a, b, weight] : edges) {
        if (distance[a] != INF && distance[a] + weight < distance[b]) {
            affected[b] = true;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (affected[j]) {
                for(int k : adj[j]) {
                    affected[k] = true;
                }
            }
        }
    }

    cout << (affected[n - 1] ? -1 : -distance[n - 1]) << "\n";

    return 0;
}
