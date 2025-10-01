#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Message Route
// https://cses.fi/problemset/task/1667

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; ++i) {
        int comp1, comp2;
        cin >> comp1 >> comp2;
        adj[comp1].push_back(comp2);
        adj[comp2].push_back(comp1);
    }

    int source = 1;
    int target = n;

    queue<int> q;
    vector<bool> visited(n + 1, false);
    q.push(source);
    visited[source] = true;
    
    vector<int> prev(n + 1, 0);
    
    while(!q.empty()) {
        int current_computer = q.front(); q.pop();
        if (current_computer == target) break;

        for(int connected_computer : adj[current_computer]) {
            if (!visited[connected_computer]) {
                q.push(connected_computer);
                visited[connected_computer] = true;
                prev[connected_computer] = current_computer;
            } 
        }
    }
    if (!visited[target]) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        vector<int> path;
        int current = target;
        while(current != 0) {
            path.push_back(current);
            current = prev[current];
        }

        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for(auto computer : path) cout << computer << " ";
        cout << "\n";
    }

    return 0;
}
