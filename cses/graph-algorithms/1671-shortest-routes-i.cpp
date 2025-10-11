#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Shortest Routes I
// https://cses.fi/problemset/task/1671

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

    vector<ll> distance(n, 0x7FFFFFFFFFFFFFFFLL);
    priority_queue<pair<ll, int>> pq;
    vector<bool> processed(n, false);

    distance[0] = 0;
    pq.push({ 0, 0 });

    while(!pq.empty()) {
        int current = pq.top().second; pq.pop();
        if (processed[current]) continue;
        processed[current] = true;

        for(auto [neighbor, weight] : adj[current]) {
            if (distance[current] + weight < distance[neighbor]) {
                distance[neighbor] = distance[current] + weight;
                pq.push({ -distance[neighbor], neighbor });
            }
        }
    }

    for(auto d : distance) {
        cout << d << " ";
    }

    cout << "\n";

    return 0;
}
