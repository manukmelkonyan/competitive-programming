#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Building Roads
// https://cses.fi/problemset/task/1666

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> connected_cities_rep; // represents a city which belongs to the connected group of cities
    unordered_set<int> visited;
    
    for(int i = 1; i <= n; ++i) {
        if (visited.find(i) != visited.end()) continue;
        visited.insert(i);
        queue<int> q;
        q.push(i);
        connected_cities_rep.push_back(i);

        while(!q.empty()) {
            int current_city = q.front(); q.pop();
            
            for(int j : adj[current_city]) {
                if (visited.find(j) == visited.end()) {
                    visited.insert(j);
                    q.push(j);
                }
            }
        }
    }

    int number_of_required_roads = connected_cities_rep.size() - 1;
    cout << number_of_required_roads << "\n";

    for (int i = 0; i < number_of_required_roads; ++i) {
        cout << connected_cities_rep[i] << " " << connected_cities_rep[i + 1] << "\n";
    }

    return 0;
}
