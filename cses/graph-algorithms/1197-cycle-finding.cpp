#include <bits/stdc++.h>

#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL

using namespace std;

// Cycle Finding
// https://cses.fi/problemset/task/1197

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    vector<tuple<int, int, int>> edges(m);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({ b, c });
        edges[i] = { a, b, c };
    }

    vector<ll> distance(n, 0);
    vector<int> parent(n, -1);
    for(int i = 0; i < n - 1; ++i) {
        for(auto [a, b, c] : edges) {
            if (distance[a] + c < distance[b]) {
                distance[b] = distance[a] + c;
                parent[b] = a;
            }
        }
    }

    int negative_cycle_member = -1;

    for(auto [a, b, c] : edges) {
        if (distance[a] + c < distance[b]) {
            distance[b] = distance[a] + c;
            parent[b] = a;
            negative_cycle_member = b;
            break;
        }
    }

    if (negative_cycle_member == -1) {
        cout << "NO\n";
        return 0;
    }

    int cycle_node = negative_cycle_member;
    for(int i = 0; i < n; ++i) {
        cycle_node = parent[cycle_node];
    }

    vector<int> cycle;
    int current = cycle_node;
    do {
        cycle.push_back(current);
        current = parent[current];
    } while(current != cycle_node);
    cycle.push_back(cycle_node);

    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for(int v : cycle) {
        cout << v + 1 << " ";
    }
    cout << "\n";

    return 0;
}
