#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Building Teams
// https://cses.fi/problemset/task/1668

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<bool> teams(n, true);
    queue<int> q;

    for(int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        q.push(i);
        visited[i] = true;
        teams[i] = true;

        while(!q.empty()) {
            int curr = q.front(); q.pop();
    
            for(auto neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    teams[neighbor] = !teams[curr];
                    q.push(neighbor);
                }
                else if (teams[neighbor] == teams[curr]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }


    for(auto team : teams) {
        cout << (team ? 1 : 2) << " ";
    }
    
    cout << "\n";
    
    return 0;
}
