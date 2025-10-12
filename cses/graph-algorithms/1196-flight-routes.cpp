#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Flight Routes
// https://cses.fi/problemset/task/1196

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({ b, c });
    }

    vector<int> visited(n, 0);
    vector<multiset<ll>> distance(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> frontier;
    distance[0].insert(0);
    frontier.push({ 0, 0 });

    while(!frontier.empty()) {
        auto [curr_dist, curr] = frontier.top(); frontier.pop();
        if (visited[curr] > k) continue;
        visited[curr]++;

        for(auto [neighbor, weight] : adj[curr]) {
            ll new_weight = curr_dist + weight;
            if (distance[neighbor].empty() || distance[neighbor].size() < k || new_weight < *distance[neighbor].rbegin()) {
                distance[neighbor].insert(new_weight);
                frontier.push({ new_weight, neighbor });
            }
            if (distance[neighbor].size() > k) {
                distance[neighbor].erase(--distance[neighbor].end());
            }
        }
    }

    for(auto x : distance[n - 1]) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
