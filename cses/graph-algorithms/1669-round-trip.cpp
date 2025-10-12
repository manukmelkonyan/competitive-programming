#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Round Trip
// https://cses.fi/problemset/task/1669

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    stack<int> s;
    int cycle_start = -1, cycle_end = -1;

    for(int i = 0; i < n; ++i) {
        if (!visited[i]) {
            s.push(i);
            parent[i] = i;
        }
        while(!s.empty()) {
            int current = s.top(); s.pop();
            
            if (visited[current]) continue;
            visited[current] = true;
    
            for(auto neighbor : adj[current]) {
                if (visited[neighbor] && neighbor != parent[current]) {
                    cycle_start = neighbor;
                    cycle_end = current;
                    break;
                }
                else if (!visited[neighbor]) {
                    parent[neighbor] = current;
                    s.push(neighbor);
                }
            }
            
            if (cycle_start != -1) break;
        }
        
        if (cycle_start != -1) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        int node = cycle_end;
        while (node != cycle_start) {
            cycle.push_back(node);
            node = parent[node];
        }
        cycle.push_back(cycle_start);
        
        cout << cycle.size() << "\n";
        for (int c : cycle) {
            cout << c + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
